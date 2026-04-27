#include <GL/glut.h>
#include <array>
#include <string>

#define ESCAPE_KEY 27
#define Q_KEY 'q'
#define A_KEY 'a'
#define D_KEY 'd'
#define W_KEY 'w'
#define S_KEY 's'
#define ROTATION_ANGLE 15.0f

float angle = 0.0f;
float dx = 0.0f;
float dy = 0.0f;

void handle_keyboard(unsigned char key, int x, int y) {
    unsigned char lower_key = tolower(key);

    if (lower_key == ESCAPE_KEY || lower_key == Q_KEY) {
        exit(0);
    }

    if (lower_key == A_KEY) {
        if (dx > -1.0f) {
            dx -= 0.01f;
        }
        angle += ROTATION_ANGLE;
    }

    if (lower_key == D_KEY) {
        if (dx < 1.0f) {
            dx += 0.01f;
        }
        angle -= ROTATION_ANGLE;
    }
    
    if (lower_key == W_KEY && dy < 1.0f) {
        dy += 0.01f;
    }

    if (lower_key == S_KEY && dy > -1.0f) {
        dy -= 0.01f;
    }

    glutPostRedisplay();
}


void draw_blade(const GLfloat *color) {
    glColor3fv(color);

    std::array<std::array<GLfloat, 2>, 3> vertices = {{
        {0.0f,   0.0f},
        {0.25f,  0.0f},
        {0.125f, 0.25f}
    }};

    glBegin(GL_TRIANGLES);
    for (const auto &vertex : vertices) {
        glVertex2fv(vertex.data());
    }
    glEnd();
}

void draw_fan() {
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
            glTranslatef(dx, dy, 0.0f);
            glRotatef(angle + i * 120.0f, 0.0f, 0.0f, 1.0f);
            GLfloat color[] = {(GLfloat) i, i / 2.0f, 1.0f - i / 2.0f};
            draw_blade(color);
        glPopMatrix();
    }
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    draw_fan();
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) {
        height = 1;
    }

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Fan");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutKeyboardFunc(handle_keyboard);
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
#include <GL/glut.h>
#include <array>

#define ESCAPE_KEY 27

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void handle_key_pressed(unsigned char key, int x, int y) {
    if (key == ESCAPE_KEY) {
        exit(0);
    }
    if (key == 'q' || key == 'Q') {
        exit(0);
    }
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::array<std::array<GLfloat, 2>, 3> vertices = {{
        { -0.5f, -0.5f },
        {  0.5f, -0.5f },
        {  0.0f,  0.5f }
    }};

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    for (const auto &vertex : vertices) {
        glVertex2fv(vertex.data());
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0); // tamanho do objeto não muda e a proporção é mantida
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle");
    init();
    glutDisplayFunc(render);
    glutKeyboardFunc(handle_key_pressed);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
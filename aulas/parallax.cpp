#include <GL/glut.h>
#include <array>

double obj1_x = 0.0;
double obj2_x = 0.0;

void handle_keyboard(unsigned char key, int x, int y) {
    if (key == 27 || key == 'q' || key == 'Q') {
        exit(0);
    }

    if (key == 'a' || key == 'A') {
        obj1_x -= 0.01;
        obj2_x -= 0.005;
    }

    if (key == 'd' || key == 'D') {
        obj1_x += 0.01;
        obj2_x += 0.005;
    }

    glutPostRedisplay();
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::array<std::array<GLfloat, 2>, 3> obj1_vertices = {{
        {-0.5, -0.5},
        {0.5, -0.5},
        {0.0, 0.0}
    }};

    std::array<std::array<GLfloat, 2>, 3> obj2_vertices = {{
        {-0.25, 0.25},
        {0.25, 0.25},
        {0.0, 0.5}
    }};

    glPushMatrix();
    glTranslatef(obj2_x, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        for (auto &vertex : obj2_vertices) {
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2fv(vertex.data());
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(obj1_x, -0.5f, 0.0f);
    glScalef(1.5f, 1.8f, 0.0);
    glTranslatef(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
        for (auto &vertex : obj1_vertices) {
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2fv(vertex.data());
        }
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Parallax Effect");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(render);
    glutKeyboardFunc(handle_keyboard);
    glutMainLoop();
    return 0;
}
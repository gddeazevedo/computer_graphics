#include <stdlib.h>
#include <GL/glut.h>




int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 350);
    glutInitWindowPosition(10, 100);
    glutCreateWindow("Polígono");
    glutDisplayFunc([]() {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT);

        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_POLYGON);
            glVertex2i(100, 150);
            glVertex2i(100, 100);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2i(150, 100);
            glVertex2i(150, 150);
            glVertex2i(125, 175);
            glVertex2i(75, 125);
        glEnd();

        glFlush();
    });
    glClearColor(0.25, 0.25, 0.25, 1.0);
    glutMainLoop();
    return 0;
}
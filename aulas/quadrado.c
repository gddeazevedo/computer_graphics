#include <stdlib.h>
#include <GL/glut.h>

void draw_square() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
        glVertex2i(100, 150);
        glVertex2i(100, 100);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(150, 100);
        glVertex2i(150, 150);
    glEnd();

    glFlush();
}

void init_background_color() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void change_window_size(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1;
    }

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
        gluOrtho2D(0.0, 250.0, 0.0, 250.0 * h / w);
    } else {
        gluOrtho2D(0.0, 250.0 * w / h, 0.0, 250.0);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400,350);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(draw_square);
    glutReshapeFunc(change_window_size);
    init_background_color();
    glutMainLoop();
    return 0;
}
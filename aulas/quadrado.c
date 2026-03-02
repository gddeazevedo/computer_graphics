#include <stdlib.h>
#include <GL/glut.h>

void draw_house() {
    // Janela tem 250x250 por que?
    // 


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
        glVertex2i(0, 0); // superior esquerdo
        glVertex2i(0, 0); // inferior esquerdo
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(300, 100); // inferior direito
        glVertex2i(300, 150); // superior direito
    glEnd();

    glFlush();
}

void init_background_color() {
    glClearColor(0.25, 0.25, 0.25, 1.0);
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(650, 250);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(draw_house);
    glutReshapeFunc(change_window_size);
    init_background_color();
    glutMainLoop();
}
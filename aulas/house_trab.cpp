#include <stdlib.h>
#include <GL/glut.h>

void draw_house() {

    /**
     * Normalização de coordenadas (MinMax de range -1 a 1):
     *     2x - (xmin + xmax)
     * x = -------------------
     *       (xmax - xmin)
     * 
     *     2y - (ymin + ymax)
     * y = -------------------
     *       (ymax - ymin)
     */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3, 0.65, 0.1);
    glBegin(GL_QUADS);
        glVertex2f(-0.75f,  0.00f);
        glVertex2f(-0.75f, -0.75f);
        glColor3f(1.0, 0.0, 1.0);
        glVertex2f( 0.75f, -0.75f);
        glVertex2f( 0.75f,  0.00f);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.75f,  0.00f);
        glColor3f(0.5, 0.5, 1.0);
        glVertex2f( 0.21f,  0.00f);
        glVertex2f(-0.27f,  0.75f);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.27f,  0.75f);
        glVertex2f( 0.21f,  0.00f);
        glColor3f(0.5, 0.5, 1.0);
        glVertex2f( 0.75f,  0.00f);
        glVertex2f( 0.33f,  0.75f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f( 0.21f,  0.00f);
        glVertex2f( 0.21f, -0.75f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f( 0.33f, -0.225f);
        glVertex2f( 0.33f, -0.525f);
        glColor3f(.5, 0.0, 1.0);
        glVertex2f( 0.69f, -0.525f);
        glVertex2f( 0.69f, -0.225f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.51f, -0.375f);
        glVertex2f(-0.51f, -0.75f);
        glColor3f(.5, 0.0, 1.0);
        glVertex2f(-0.15f, -0.75f);
        glVertex2f(-0.15f, -0.375f);
    glEnd();

    glFlush();
}

void change_window_size(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // define o viewport para normalização de coordenadas (-1 a 1) em x e y

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init_background_color() {
    glClearColor(0.25, 0.25, 0.25, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(650, 250);
    glutCreateWindow("Casa");
    glutDisplayFunc(draw_house);
    glutReshapeFunc(change_window_size);
    init_background_color();
    glutMainLoop();
}
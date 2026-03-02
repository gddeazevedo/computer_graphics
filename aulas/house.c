#include <stdlib.h>
#include <GL/glut.h>

void draw_house() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3, 0.65, 0.1);

    glBegin(GL_QUADS);
        // vértices do quadrado, seguem a ordem anti-horária a partir do primeiro vértice definido (canto superior esquerdo)
        glVertex2i(100, 150); // superior esquerdo
        glVertex2i(100, 100); // inferior esquerdo
        glColor3f(1.0, 0.0, 1.0);
        glVertex2i(225, 100); // inferior direito
        glVertex2i(225, 150); // superior direito
    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
        glVertex2i(100, 150); // vértice da esquerda
        glColor3f(0.5, 0.5, 1.0);
        glVertex2i(180, 150); // vértice da direita
        glVertex2i(140, 200); // vértice do topo
    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
        glVertex2i(140, 200); // vértice superior esquerdo
        glVertex2i(180, 150); // vértice inferior esquerdo
        glColor3f(0.5, 0.5, 1.0);
        glVertex2i(225, 150); // vértice inferior direito
        glVertex2i(190, 200); // vértice superior direito
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(180, 150);
        glVertex2i(180, 100);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(190, 135);
        glVertex2i(190, 115);
        glColor3f(.5, 0.0, 1.0);
        glVertex2i(220, 115);
        glVertex2i(220, 135);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(130, 125);
        glVertex2i(130, 100);
        glColor3f(.5, 0.0, 1.0);
        glVertex2i(150, 100);
        glVertex2i(150, 125);
    glEnd();

    glFlush();
}

void change_window_size(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1;
    }

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h){ 
        gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    } else {
        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
    } 
}

void init_background_color() {
    glClearColor(0.25, 0.25, 0.25, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(650, 250);
    glutCreateWindow("Casa");
    glutDisplayFunc(draw_house);
    glutReshapeFunc(change_window_size);
    init_background_color();
    glutMainLoop();
}
#include <GL/glut.h>

void handle_keyboard(unsigned char key, int x, int y) {
    if (key == 27 || key == 'q' || key == 'Q') {
        exit(0);
    }
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) {
        height = 1;
    }

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

void drawWing(float *color) {
    glColor3fv(color);

    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(3.0f, 0.0f);
        glVertex2f(0.0, 2.0);
    glEnd();
}

void drawBird() {
    glPushMatrix();
        glTranslatef(4.25, 1.5, 0.0);
        glScalef(1.5, 1.5, 1.0);
        glRotatef(-90.0f, 0.0, 0.0, 1.0);
        glTranslatef(-1.5, -1.0, 0.0);
        float wingColor1[] = {1.0f, 0.0f, 0.0f};
        drawWing(wingColor1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.25, 1.5, 0.0);
        glScalef(-1.5, 1.5, 1.0);
        glRotatef(-90.0f, 0.0, 0.0, 1.0);
        glTranslatef(-1.5, -1.0, 0.0);
        float wingColor2[] = {0.0f, 0.0f, 1.0f};
        drawWing(wingColor2);
    glPopMatrix();
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBird();
    glutSwapBuffers();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D Bird");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutKeyboardFunc(handle_keyboard);
    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
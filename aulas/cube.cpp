#include <GL/glut.h>
#include <array>


void handle_keyboard(unsigned char key, int x, int y) {
    if (key == 27 || key == 'q' || key == 'Q') {
        exit(0);
    }
}

void init() {
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
}

void draw_cube() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, 3.0f, // posição do observador
              0.0f, 0.0f, 0.0f, // ponto para onde o observador está olhando
              0.0f, 1.0f, 0.0f); // vetor "up" do observador (indica a direção para cima)

              
    std::array<std::array<GLfloat, 3>, 8> vertices = {{
        { 1.0f, 1.0f, 0.0f },
        {-1.0f, 1.0f, 0.0f },
        {-1.0f,-1.0f, 0.0f },
        { 1.0f,-1.0f, 0.0f },
        { 1.0f, 1.0f, 2.0f },
        {-1.0f, 1.0f, 2.0f },
        {-1.0f,-1.0f, 2.0f },
        { 1.0f,-1.0f, 2.0f }
    }};

    glPushMatrix();
        glRotatef(5.0, 0.0, 1.0, 0.0);
        glTranslatef(0.0f, 0.0f, -10.0f);
        glBegin(GL_QUADS);
            for (const auto &vertex : vertices) {
                glColor3f(0.5f, 0.5f, 0.5f);
                glVertex3fv(vertex.data());
            }
        glEnd();
    glPopMatrix();

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
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D Cube");
    init();
    glutDisplayFunc(draw_cube);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handle_keyboard);
    glutMainLoop();
    return 0;
}
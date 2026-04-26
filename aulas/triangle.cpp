#include <GL/glut.h>
#include <array>

#define ESCAPE_KEY 27

double angle = 0.0;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glViewport(200, 150, 400, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

void handle_key_pressed(unsigned char key, int x, int y) {
    if (key == ESCAPE_KEY) {
        exit(0);
    }

    if (key == 'q' || key == 'Q') {
        exit(0);
    }

    if (key == 'z' || key == 'Z') {
        angle += 1.0;
    }

    glutPostRedisplay();
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::array<std::array<GLfloat, 2>, 3> vertices = {{
        {  0.5f, 0.5f },
        {  1.5f, 0.5f },
        {  1.0f, 1.5f }
    }};

    glPushMatrix();
    glTranslatef(1.0f, 0.75f, 0.0f);     // translada o triângulo para a posição inicial
    glRotatef(-angle, 0.0f, 0.0f, 1.0f); // rotaciona o triângulo em torno do eixo z por um angulo angle
    glTranslatef(-1.0f, -0.75f, 0.0f);   // translada o triângulo para o centro do sistema de coordenadas
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    for (const auto &vertex : vertices) {
        glVertex2fv(vertex.data());
    }
    glEnd();
    glPopMatrix();


    std::array<std::array<GLfloat, 2>, 4> sides = {{
        {0.0, 0.25},
        {0.0, 0.0},
        {0.25, 0.0},
        {0.25, 0.25}
    }};

    glPushMatrix();
    glTranslatef(0.125f, 0.125f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.125f, -0.125f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.7f);
    for (const auto &side : sides) {
        glVertex2fv(side.data());
    }
    glEnd();
    glPopMatrix();

    std::array<std::array<GLfloat, 2>, 4> sides2 = {{
        {1.75, 2.0},
        {1.75, 1.75},
        {2.0, 1.75},
        {2.0, 2.0}
    }};

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.7f);
    for (const auto &side : sides2) {
        glVertex2fv(side.data());
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(200, 150, width / 2, height / 2);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 2.0, 0.0, 2.0); // tamanho do objeto não muda e a proporção é mantida
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
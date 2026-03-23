#include <GL/glut.h>

#define ESCAPE_KEY 27
#define ROTATION_ANGLE 15.0f
#define X_KEY 'x'
#define Y_KEY 'y'
#define Z_KEY 'z'
#define Q_KEY 'q'
#define R_KEY 'r'
#define X_KEY_UPPER 'X'
#define Y_KEY_UPPER 'Y'
#define Z_KEY_UPPER 'Z'
#define Q_KEY_UPPER 'Q'
#define R_KEY_UPPER 'R'
#define rotate_x_axis(angle) glRotatef(angle, 1.0f, 0.0f, 0.0f) // rotaciona em torno do eixo (1, 0, 0) (eixo x) por um angulo de angle graus
#define rotate_y_axis(angle) glRotatef(angle, 0.0f, 1.0f, 0.0f) // rotaciona em torno do eixo (0, 1, 0) (eixo y) por um angulo de angle graus
#define rotate_z_axis(angle) glRotatef(angle, 0.0f, 0.0f, 1.0f) // rotaciona em torno do eixo (0, 0, 1) (eixo z) por um angulo de angle graus

char title[] = "3D House";
GLfloat angle_x = 0.0f;
GLfloat angle_y = 0.0f;
GLfloat angle_z = 0.0f;

void initGL();
void draw_house();
void reshape(GLsizei width, GLsizei height);
void handle_key_pressed(unsigned char key, int x, int y);
void draw_cube();
void draw_roof();

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(draw_house);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handle_key_pressed);
    initGL();
    glutMainLoop();
    return EXIT_SUCCESS;
}

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void draw_cube() {
    const float red   = 0.5f;
    const float green = 0.5f;
    const float blue  = 0.5f;

    // (x, y, z) do cubo
    glTranslatef(0.0, -1.0, 0.0);

    glBegin(GL_QUADS);
        // Top face (y = 1.0f)
        glColor3f(red, green, blue);

        glVertex3f( 1.0f, 1.0f,  2.0f);
        glVertex3f(-1.0f, 1.0f,  2.0f);
        glVertex3f(-1.0f, 1.0f, -2.0f);
        glVertex3f( 1.0f, 1.0f, -2.0f);

        // Bottom face (y = -1.0f)
        glColor3f(red, green, blue);

        glVertex3f( 1.0f, -1.0f,  2.0f);
        glVertex3f(-1.0f, -1.0f,  2.0f);
        glVertex3f(-1.0f, -1.0f, -2.0f);
        glVertex3f( 1.0f, -1.0f, -2.0f);

        // Front face  (z = 1.0f)
        glColor3f(red, green, blue);

        glVertex3f( 1.0f,  1.0f, 2.0f);
        glVertex3f(-1.0f,  1.0f, 2.0f);
        glVertex3f(-1.0f, -1.0f, 2.0f);
        glVertex3f( 1.0f, -1.0f, 2.0f);

        // door
        glColor3f(0.1, 0.1, 0.1);

        // retangulo da porta
        glVertex3f( 0.3f,  0.4f, 2.01f);  // vértice superior esquerdo da porta
        glVertex3f(-0.4f,  0.4f, 2.01f);  // vértice inferior esquerdo da porta
        glVertex3f(-0.4f, -0.95f, 2.01f); // vértice inferior  da porta
        glVertex3f( 0.3f, -0.95f, 2.01f); // vértice inferior direito da porta

        // Back face (z = -1.0f)
        glColor3f(red, green, blue);

        glVertex3f( 1.0f, -1.0f, -2.0f);
        glVertex3f(-1.0f, -1.0f, -2.0f);
        glVertex3f(-1.0f,  1.0f, -2.0f);
        glVertex3f( 1.0f,  1.0f, -2.0f);

        // Left face (x = -1.0f)
        glColor3f(red, green, blue);

        glVertex3f(-1.0f,  1.0f,  2.0f);
        glVertex3f(-1.0f,  1.0f, -2.0f);
        glVertex3f(-1.0f, -1.0f, -2.0f);
        glVertex3f(-1.0f, -1.0f,  2.0f);

        // Right face (x = 1.0f)
        glColor3f(red, green, blue);

        glVertex3f(1.0f,  1.0f, -2.0f);
        glVertex3f(1.0f,  1.0f,  2.0f);
        glVertex3f(1.0f, -1.0f,  2.0f);
        glVertex3f(1.0f, -1.0f, -2.0f);
    glEnd();
}

void draw_roof() {
    const float red   = 1.0f;
    const float green = 0.0f;
    const float blue  = 0.0f;

    // (x, y, z) da piramide
    glTranslatef(0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        // Front
        glColor3f(red, green, blue);

        glVertex3f( 0.0f,  1.0f, 0.0f); // vértice do topo da pirâmide
        glVertex3f(-1.5f, -1.0f, 2.5f);
        glVertex3f( 1.5f, -1.0f, 2.5f);

        // Right
        glColor3f(red, green, blue);

        glVertex3f(0.0f,  1.0f,  0.0f);
        glVertex3f(1.5f, -1.0f,  2.5f);
        glVertex3f(1.5f, -1.0f, -2.5f);

        // Back
        glColor3f(red, green, blue);

        glVertex3f( 0.0f,  1.0f,  0.0f);
        glVertex3f( 1.5f, -1.0f, -2.5f);
        glVertex3f(-1.5f, -1.0f, -2.5f);

        // Left
        glColor3f(red, green, blue);

        glVertex3f( 0.0f,  1.0f,  0.0f);
        glVertex3f(-1.5f, -1.0f, -2.5f);
        glVertex3f(-1.5f, -1.0f,  2.5f);
    glEnd();
}

void draw_house() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -10.0f); // translada a casa para trás, para que ela fique visível na tela (-7.0f no eixo z)
    
    rotate_x_axis(angle_x); // rotaciona a casa em torno do eixo x por um angulo de angle_x graus
    rotate_y_axis(angle_y); // rotaciona a casa em torno do eixo y por um angulo de angle_y graus
    rotate_z_axis(angle_z); // rotaciona a casa em torno do eixo z por um angulo de angle_z graus

    // primeiro rotaciona nos eixos x, y e z e depois translada -10 no eixo z

    glPushMatrix();
        draw_cube();
    glPopMatrix();

    glPushMatrix();
        draw_roof();
    glPopMatrix();

    glutSwapBuffers();
}

void handle_key_pressed(unsigned char key, int x, int y) {
    switch (key) {
        case ESCAPE_KEY:
        case Q_KEY:
        case Q_KEY_UPPER:
            exit(EXIT_SUCCESS);
            break;
        case X_KEY:
            angle_x += ROTATION_ANGLE;
            break;
        case Y_KEY:
            angle_y += ROTATION_ANGLE;
            break;
        case Z_KEY:
            angle_z += ROTATION_ANGLE;
            break;
        case X_KEY_UPPER:
            angle_x -= ROTATION_ANGLE;
            break;
        case Y_KEY_UPPER:
            angle_y -= ROTATION_ANGLE;
            break;
        case Z_KEY_UPPER:
            angle_z -= ROTATION_ANGLE;
            break;
        case R_KEY:
        case R_KEY_UPPER:
            angle_x = 0.0f;
            angle_y = 0.0f;
            angle_z = 0.0f;
            break;
        default:
            break;
    }
    glutPostRedisplay(); // solicita que a tela seja redesenhada, chamando a função de callback em glutDisplayFunc novamente
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
}
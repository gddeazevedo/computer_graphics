#include <GL/glut.h>
#include <stdio.h>

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


class House
{
    private:
        float angle_x;
        float angle_y;
        float angle_z;
        void draw_cube();
        void draw_roof();

    public:
        House() : angle_x(0.0f), angle_y(0.0f), angle_z(0.0f) {}

        void draw();
        void rotate(float angle_x, float angle_y, float angle_z);
        void set_angle_x(float angle);
        void set_angle_y(float angle);
        void set_angle_z(float angle);
        float get_angle_x() const { return angle_x; }
        float get_angle_y() const { return angle_y; }
        float get_angle_z() const { return angle_z; }
};

void House::draw_cube() {
    const float red   = 0.5f;
    const float green = 0.5f;
    const float blue  = 0.5f;

    // (x, y, z) do cubo
    glTranslatef(0.0f, -1.0f, 0.0f);

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

void House::draw_roof() {
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

void House::draw() {
    rotate(angle_x, angle_y, angle_z);

    glPushMatrix();
        draw_cube();
    glPopMatrix();

    glPushMatrix();
        draw_roof();
    glPopMatrix();
}


void House::rotate(float angle_x, float angle_y, float angle_z) {
    rotate_x_axis(angle_x);
    rotate_y_axis(angle_y);
    rotate_z_axis(angle_z);
}

void House::set_angle_x(float angle) {
    angle_x = angle;
}

void House::set_angle_y(float angle) {
    angle_y = angle;
}

void House::set_angle_z(float angle) {
    angle_z = angle;
}



House* current_house;


void initGL();
void reshape(GLsizei width, GLsizei height);
void handle_key_pressed(unsigned char key, int x, int y);
void handle_mouse_click(int button, int state, int x, int y);
void draw_houses();


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D House");
    glutDisplayFunc(draw_houses);
    glutReshapeFunc(reshape);
    // glutKeyboardFunc(handle_key_pressed);
    glutMouseFunc(handle_mouse_click);
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

void draw_houses() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -10.0f); // translada as casas para trás, para que elas fiquem visíveis na tela (-7.0f no eixo z)
    
    House house1;
    House house2;

    current_house = &house1;

    glPushMatrix();
        house1.draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.0f, 0.0f, 0.0f); // translada a segunda casa para a direita
        house2.draw();
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
            current_house->set_angle_x(current_house->get_angle_x() + ROTATION_ANGLE);
            break;
        case Y_KEY:
            current_house->set_angle_y(current_house->get_angle_y() + ROTATION_ANGLE);
            break;
        case Z_KEY:
            current_house->set_angle_z(current_house->get_angle_z() + ROTATION_ANGLE);
            break;
        case X_KEY_UPPER:
            current_house->set_angle_x(current_house->get_angle_x() - ROTATION_ANGLE);
            break;
        case Y_KEY_UPPER:
            current_house->set_angle_y(current_house->get_angle_y() - ROTATION_ANGLE);
            break;
        case Z_KEY_UPPER:
            current_house->set_angle_z(current_house->get_angle_z() - ROTATION_ANGLE);
            break;
        case R_KEY:
        case R_KEY_UPPER:
            current_house->set_angle_x(0.0f);
            current_house->set_angle_y(0.0f);
            current_house->set_angle_z(0.0f);
            break;
        default:
            break;
    }
    glutPostRedisplay(); // solicita que a tela seja redesenhada, chamando a função de callback em glutDisplayFunc novamente
}

void handle_mouse_click(int button, int state, int x, int y) {
    printf("Mouse click detected at (%d, %d)\n", x, y);
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
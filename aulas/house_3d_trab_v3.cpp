#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define ESCAPE_KEY 27
#define ROTATION_ANGLE 15.0f
#define X_KEY 'x'
#define Y_KEY 'y'
#define Z_KEY 'z'
#define Q_KEY 'q'
#define R_KEY 'r'
#define W_KEY 'w'
#define A_KEY 'a'
#define S_KEY 's'
#define D_KEY 'd'
#define W_KEY_UPPER 'W'
#define A_KEY_UPPER 'A'
#define S_KEY_UPPER 'S'
#define D_KEY_UPPER 'D'
#define X_KEY_UPPER 'X'
#define Y_KEY_UPPER 'Y'
#define Z_KEY_UPPER 'Z'
#define Q_KEY_UPPER 'Q'
#define R_KEY_UPPER 'R'
#define rotate_x_axis(angle) glRotatef(angle, 1.0f, 0.0f, 0.0f)
#define rotate_y_axis(angle) glRotatef(angle, 0.0f, 1.0f, 0.0f)
#define rotate_z_axis(angle) glRotatef(angle, 0.0f, 0.0f, 1.0f)

class Camera {
    public:
        GLdouble obsX;
        GLdouble obsY;
        GLdouble obsZ;
        GLdouble centerX;
        GLdouble centerY;
        GLdouble centerZ;
        Camera() : obsX(0), obsY(0), obsZ(200), centerX(0), centerY(0), centerZ(0) {}

        void move_forward(float distance);
        void move_backward(float distance);
        void move_left(float distance);
        void move_right(float distance);
        void rotate_left(float angle);
        void rotate_right(float angle);
};


void Camera::move_backward(float distance) {
    this->obsZ += distance;
    this->centerZ += distance;
}

void Camera::move_forward(float distance) {
    this->obsZ -= distance;
    this->centerZ -= distance;
}

void Camera::move_left(float distance) {
    this->obsX -= distance;
    this->centerX -= distance;
}

void Camera::move_right(float distance) {
    this->obsX += distance;
    this->centerX += distance;
}

void Camera::rotate_left(float angle) {
    // Implementar rotação para a esquerda
}

void Camera::rotate_right(float angle) {
    float radians = angle * M_PI / 180.0f;
    float x = cos(radians);
    float z = sin(radians);

    // this->centerX += 
}


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

    glTranslatef(0.0f, -1.0f, 0.0f);

    glBegin(GL_QUADS);
        glColor3f(red, green, blue);

        glVertex3f( 1.0f, 1.0f,  2.0f);
        glVertex3f(-1.0f, 1.0f,  2.0f);
        glVertex3f(-1.0f, 1.0f, -2.0f);
        glVertex3f( 1.0f, 1.0f, -2.0f);

        glColor3f(red, green, blue);

        glVertex3f( 1.0f, -1.0f,  2.0f);
        glVertex3f(-1.0f, -1.0f,  2.0f);
        glVertex3f(-1.0f, -1.0f, -2.0f);
        glVertex3f( 1.0f, -1.0f, -2.0f);

        glColor3f(red, green, blue);

        glVertex3f( 1.0f,  1.0f, 2.0f);
        glVertex3f(-1.0f,  1.0f, 2.0f);
        glVertex3f(-1.0f, -1.0f, 2.0f);
        glVertex3f( 1.0f, -1.0f, 2.0f);

        glColor3f(0.1, 0.1, 0.1);

        glVertex3f( 0.3f,  0.4f, 2.01f);
        glVertex3f(-0.4f,  0.4f, 2.01f);
        glVertex3f(-0.4f, -0.95f, 2.01f);
        glVertex3f( 0.3f, -0.95f, 2.01f);

        glColor3f(red, green, blue);

        glVertex3f( 1.0f, -1.0f, -2.0f);
        glVertex3f(-1.0f, -1.0f, -2.0f);
        glVertex3f(-1.0f,  1.0f, -2.0f);
        glVertex3f( 1.0f,  1.0f, -2.0f);

        glColor3f(red, green, blue);

        glVertex3f(-1.0f,  1.0f,  2.0f);
        glVertex3f(-1.0f,  1.0f, -2.0f);
        glVertex3f(-1.0f, -1.0f, -2.0f);
        glVertex3f(-1.0f, -1.0f,  2.0f);

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

    glTranslatef(0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);

        glVertex3f( 0.0f,  1.0f, 0.0f);
        glVertex3f(-1.5f, -1.0f, 2.5f);
        glVertex3f( 1.5f, -1.0f, 2.5f);

        glColor3f(red, green, blue);

        glVertex3f(0.0f,  1.0f,  0.0f);
        glVertex3f(1.5f, -1.0f,  2.5f);
        glVertex3f(1.5f, -1.0f, -2.5f);

        glColor3f(red, green, blue);

        glVertex3f( 0.0f,  1.0f,  0.0f);
        glVertex3f( 1.5f, -1.0f, -2.5f);
        glVertex3f(-1.5f, -1.0f, -2.5f);

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



House house1;
House house2;
House* current_house = &house1;

Camera camera;


void initGL();
void reshape(GLsizei width, GLsizei height);
void handle_key_pressed(unsigned char key, int x, int y);
void handle_special_key_pressed(int key, int x, int y);
void handle_mouse_click(int button, int state, int x, int y);
void draw_houses();


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 520);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D House");
    glutDisplayFunc(draw_houses);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handle_key_pressed);
    glutSpecialFunc(handle_special_key_pressed);
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

    glTranslatef(-3.0f, 0.0f, -10.0f);

    glPushMatrix();
        house1.draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(6.0f, 0.0f, 0.0f); // translada a segunda casa para a direita
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
        case W_KEY:
        case W_KEY_UPPER:
            break;
        default:
            break;
    }

    glutPostRedisplay();
}

void handle_special_key_pressed(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            printf("Up arrow key pressed\n");
            break;
        case GLUT_KEY_DOWN:
            printf("Down arrow key pressed\n");
            break;
        case GLUT_KEY_LEFT:
            printf("Left arrow key pressed\n");
            break;
        case GLUT_KEY_RIGHT:
            printf("Right arrow key pressed\n");
            break;
        default:
            break;
    }

    gluLookAt(camera.obsX, camera.obsY, camera.obsZ, 0, 0, 0, 0, 1, 0);

    glutPostRedisplay();
}

void handle_mouse_click(int button, int state, int x, int y) {
    if (state != GLUT_DOWN) {
        return;
    }

    if (button == GLUT_LEFT_BUTTON) {
        current_house = &house1;
        return;
    }

    if (button == GLUT_RIGHT_BUTTON) {
        current_house = &house2;
        return;
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
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
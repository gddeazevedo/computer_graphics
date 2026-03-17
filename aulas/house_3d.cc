#include <GL/glut.h>

#define ESCAPE_KEY 27
#define ROTATION_ANGLE 15.0f
#define X_KEY 'x'
#define Y_KEY 'y'
#define Z_KEY 'z'
#define rotate_x_axis(angle) glRotatef(angle, 1.0f, 0.0f, 0.0f) // rotaciona em torno do eixo (1, 0, 0) (eixo x) por um angulo de angle graus
#define rotate_y_axis(angle) glRotatef(angle, 0.0f, 1.0f, 0.0f) // rotaciona em torno do eixo (0, 1, 0) (eixo y) por um angulo de angle_y graus
#define rotate_z_axis(angle) glRotatef(angle, 0.0f, 0.0f, 1.0f) // rotaciona em torno do eixo (0, 0, 1) (eixo z) por um angulo de angle_z graus

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


int main(int argc, char** argv) {
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
   return 0;
}


void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void draw_cube() {
   // (x, y, z) do cubo
   glTranslatef(1.5f, 0.0f, -7.0f);

   // (x, y, z)
   rotate_x_axis(angle_x);
   rotate_y_axis(angle_y);
   rotate_z_axis(angle_z);

   
   glBegin(GL_QUADS);
      // Top face (y = 1.0f)
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f( 1.0f, 1.0f, -1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();
}

void draw_roof() {
   // (x, y, z) da piramide
   glTranslatef(1.5f, 0.0f, -7.0f);

   rotate_x_axis(angle_x);
   rotate_y_axis(angle_y);
   rotate_z_axis(angle_z);

   glBegin(GL_TRIANGLES);
      // Front
      glColor3f(10.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

      // Back
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glColor3f(1.0f,0.0f,0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();
}

void draw_house() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   draw_cube();

   glLoadIdentity();
   draw_roof();

   glutSwapBuffers();
}

void handle_key_pressed(unsigned char key, int x, int y) {
   switch (key) {
      case ESCAPE_KEY:
         exit(0);
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
      default:
         break;
   }
   glutPostRedisplay();
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
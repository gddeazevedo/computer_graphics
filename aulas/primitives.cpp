#include <GL/glut.h>
#include <vector>

using namespace std;

vector<vector<float>> vertices = {
    {0.0,  0.0},
    {0.0, -0.5},
    {0.5, -0.5},
    {0.5,  0.0},

    { 0.0,  0.0},
    { 0.0,  0.5},
    {-0.5,  0.5},
    {-0.5,  0.0}
};

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(10);
    glLineWidth(2);
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0, 0.3, 1.0);
        for (const auto &vertex : vertices) {
            glVertex2fv(vertex.data());
        }
    glEnd();
    
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        for (auto& vertex : vertices) {
            // vertex[0] += -0.25f;
            // vertex[1] += -0.25f;
            glVertex2fv(vertex.data());
        }
    glEnd();

    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Primitives");
    glutDisplayFunc(render);
    init();
    glutMainLoop();
    return 0;
}
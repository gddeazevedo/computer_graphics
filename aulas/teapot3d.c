// TeaPot3D.c - Isabel H. Manssour
// Um programa OpenGL que exemplifica a visualização
// de objetos 3D.
// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include "GL/glut.h"

#define W_KEY 'w'
#define A_KEY 'a'
#define S_KEY 's'
#define D_KEY 'd'

GLfloat angle, fAspect;
GLdouble obsX = 0, obsY = 0, obsZ = 200;
GLdouble centerX = 0, centerY = 0, centerZ = 0;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 1.0f);

    // Desenha o teapot com a cor corrente (wire-frame)
    glutWireTeapot(50.0f);

    // Executa os comandos OpenGL
    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle = 45;
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    // Especifica posição do observador e do alvo
    gluLookAt(obsX, obsY, obsZ, centerX, centerY, centerZ, 0, 1, 0);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();

    // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
    gluPerspective(angle, fAspect, 0.5, 500);

    PosicionaObservador();
}

void SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        obsX -= 10;
        centerX -= 10;
        break;
    case GLUT_KEY_RIGHT:
        obsX += 10;
        centerX += 10;
        break;
    case GLUT_KEY_UP:
        obsZ -= 10;
        centerZ -= 10;
        break;
    case GLUT_KEY_DOWN:
        obsZ += 10;
        centerZ += 10;
        break;
    default:
        break;
    }
    glLoadIdentity();
    gluLookAt(obsX, obsY, obsZ, centerX, centerY, centerZ, 0, 1, 0);
    glutPostRedisplay();
}

void KeyPressed(unsigned char key, int x, int y)
{
    switch (key)
    {
    case W_KEY:
        obsZ -= 10;
        centerZ -= 10;
        break;
    case S_KEY:
        obsZ += 10;
        centerZ += 10;
        break;
    case A_KEY:
        obsX -= 10;
        centerX -= 10;
        break;
    case D_KEY:
        obsX += 10;
        centerX += 10;
        break;
    }
    glLoadIdentity();
    gluLookAt(obsX, obsY, obsZ, centerX, centerY, centerZ, 0, 1, 0);
    glutPostRedisplay();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Para previnir uma divisão por zero
    if (h == 0)
        h = 1;

    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

    // Calcula a correção de aspecto
    fAspect = (GLfloat)w / (GLfloat)h;

    EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN)
        { // Zoom-in
            if (angle >= 10)
                angle -= 5;
        }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN)
        { // Zoom-out
            if (angle <= 130)
                angle += 5;
        }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(350, 300);
    glutCreateWindow("Visualizacao 3D");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutMouseFunc(GerenciaMouse);
    glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(KeyPressed);
    Inicializa();
    glutMainLoop();
}
#include <GL/glut.h>
#include <GL/glu.h>

void myInit(){
    glClearColor(0,0,0,1); //R G B Transparency (background color)
    glColor3f(1,0,0); //set to RED (drawing color)
}

void drawSquare(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[]){
    glBegin(GL_POLYGON); //group data points as a single object
        glVertex2fv(V0); //data point 1
        glVertex2fv(V1); //data point 2
        glVertex2fv(V2); //data point 3
        glVertex2fv(V3); //data point 4
    glEnd();
}

void displayMe(void)
{
    GLfloat v[4][2] = {
                            {-0.5,  0.5},
                            { 0.5,  0.5},
                            { 0.5, -0.5},
                            {-0.5, -0.5},
                        };

    glClear(GL_COLOR_BUFFER_BIT); //clear the background

    drawSquare(v[0], v[1], v[2], v[3]);

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(250, 50);
    glutCreateWindow("Basic OpenGL - 2D");
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //RGB | 2D
    myInit();

    glutDisplayFunc(displayMe);

    glutMainLoop();
    return 0;
}

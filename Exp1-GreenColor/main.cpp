#include<windows.h>
#include <GL/glut.h>
void display()
{

 	glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Exp1 - Green Color");
    glClearColor(0,1,0,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

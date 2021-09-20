#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
int n;
void init()
{
    gluOrtho2D(0,200,0,200);
}
void floodFill(int x,int y,float fillColor[3],float oldColor[3])
{
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((oldColor[0]==color[0] && oldColor[1]==color[1] && oldColor[2]==color[2]))
    {
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        floodFill(x+1,y,fillColor,oldColor);
        floodFill(x-1,y,fillColor,oldColor);
        floodFill(x,y+1,fillColor,oldColor);
        floodFill(x,y-1,fillColor,oldColor);
    }
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex2i(50,50);
	glVertex2i(150,50);
	glVertex2i(150,150);
	//glVertex2i(50,150); //Uncomment to make a square
	glEnd();
	glFlush();

}
void mousebutton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    std::cout<<x<<" , "<<y<<"\n";
		float oldcolor[3] = {0.0f,0.0f,1.0f};
        float fillcolor[3] = {0.0f,1.0f,0.0f};
        floodFill(x,200-y,fillcolor,oldcolor);
	}
}
int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Flood Fill Algorithm");
    glutDisplayFunc(display);
    glutMouseFunc(mousebutton);
    init();
    glutMainLoop();
    return 0;
}

#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
void init()
{
    gluOrtho2D(0,200,0,200);
}
void boundaryFill(int x,int y,float fill[3],float boundary[3])
{
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=boundary[0] || color[1]!=boundary[1] || color[2]!=boundary[2]) && (color[0]!=fill[0] || color[1]!=fill[1] || color[2]!=fill[2]))
    {
        glColor3f(fill[0],fill[1],fill[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        boundaryFill(x+1,y,fill,boundary);
        boundaryFill(x-1,y,fill,boundary);
        boundaryFill(x,y+1,fill,boundary);
        boundaryFill(x,y-1,fill,boundary);
    }
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50,50);
	glVertex2i(150,50);
	glVertex2i(150,150);
	glVertex2i(50,150);
	glEnd();
	glFlush();
}
void mousebutton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    std::cout<<x<<" , "<<y<<"\n";
		float oldcolor[3] = {1.0f,0.0f,0.0f};
        float fillcolor[3] = {0.0f,0.0f,1.0f};
        boundaryFill(x,200-y,fillcolor,oldcolor);
	}
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Boundary Fill Algorithm");
    glutDisplayFunc(display);
    glutMouseFunc(mousebutton);
    init();
    glutMainLoop();
    return 0;
}

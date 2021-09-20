#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>
float r,xc,yc,x,y,d;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(-200,0);
	glVertex2f(200,0);
	glVertex2f(0,200);
	glVertex2f(0,-200);
	glEnd();

	glColor3f(1,0,0);
	d=3-(2*r);
	x=0,y=r;
	while(x<=y)
	{
		if(d<0)
		{
			d=d+(4*x)+6;
			x=x+1;
		}
		else if(d>=0)
		{
			d=d+((4*x)-(4*y))+10;
			x=x+1;
			y=y-1;
		}
		glBegin(GL_POINTS);
		glVertex2f(x+xc,y+yc);
        	glVertex2f(-x+xc,y+yc);
       	glVertex2f(x+xc,-y+yc);
        	glVertex2f(-x+xc,-y+yc);
        	glVertex2f(y+yc,x+xc);
        	glVertex2f(-y+yc,x+xc);
        	glVertex2f(y+yc,-x+xc);
        	glVertex2f(-y+yc,-x+xc);
        	glEnd();
        }
        glFlush();
}
int main(int argc, char **argv)
{
	printf("Enter Radius: ");
	scanf("%f",&r);
	printf("Enter Circle Co-ordiantes\nX: ");
	scanf("%f",&xc);
	printf("Y: ");
	scanf("%f",&yc);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Exp7 - Circle using Bresenham Eqn.");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(400,400);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
}

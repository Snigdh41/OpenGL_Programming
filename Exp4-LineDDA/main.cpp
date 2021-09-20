#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<GL/glut.h>
float m,dx,dy,x,y,a,b,c,d;
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

	glColor3f(0,0,1);
	dy=d-b;
	dx=c-a;
	m=(dy/dx);
	printf("m = %f",m);
	if(m==1)
	{
		y=b;
		for(int i=a;i<=c;i++)
		{
			glBegin(GL_POINTS);
			glVertex2d(i,y);
			glEnd();
			y=y+1;
		}
	}
	if(m<1)
	{
		y=b;
		for(int j=a;j<=c;j++)
		{
			glBegin(GL_POINTS);
			glVertex2d(j,y);
			glEnd();
			y=y+m;
		}
	}
	if(m>1)
	{
		x=a;
		for(int k=b;k<=d;k++)
		{
			glBegin(GL_POINTS);
			glVertex2d(x,k);
			glEnd();
			x=x+(1/m);
		}
	}
	glFlush();
}
int main(int argc, char **argv)
{
	printf("Enter Line Starting Co-ordinates:\nX: ");
	scanf("%f",&a);
	printf("Y: ");
	scanf("%f",&b);
	printf("Enter Line Ending Co-ordinates:\nX: ");
	scanf("%f",&c);
	printf("Y: ");
	scanf("%f",&d);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Exp5 - Line using Bresenham");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(400,400);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
}

#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
float p,m,dx,dy,a,b,c,d,x=0,y=0;

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
	dx=c-a;
	dy=d-b;
	m=dy/dx;
	printf("m = %f",m);
	p= (2*dy)-dx;
	x=a;
	y=b;
	if(m<1)
	{
		for(int i=a;i<=c;i++)
		{
			if(p<0)
			{
				p = p + (2*dy);
			}
			else
			{
				p = p + (2*dy) - (2*dx);
				y++;
			}
			glBegin(GL_POINTS);
			glVertex2f(i,y);
			glEnd();
		}
	}

	else if(m>=1)
	{
		for(int j=b;j<=d;j++)
		{
			if(p<0)
			{
				p = p + (2*dx);
			}
			else
			{
				p = p + (2*dx) - (2*dy);
				x++;
			}
			glBegin(GL_POINTS);
			glVertex2f(x,j);
			glEnd();
		}
	}
	glFlush();
}
int main(int argc, char **argv)
{
	printf("Enter Line Starting Coordinate\nX: ");
	scanf("%f",&a);
	printf("Y: ");
	scanf("%f",&b);
	printf("Enter Line Ending Coordinate\nX: ");
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

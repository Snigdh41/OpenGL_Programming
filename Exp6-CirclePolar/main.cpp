#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>
float r,a,b,x,y;
float pi=3.1415;
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
	for(int i=0;i<360;i++)
	{
		x=a+r*sin((i*pi)/180);
		y=b+r*cos((i*pi)/180);
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
	}
	glFlush();

}
int main(int argc, char **argv)
{
	printf("Enter Radius: ");
	scanf("%f",&r);
	printf("Enter Circle Co-ordiantes\nX: ");
	scanf("%f",&a);
	printf("Y: ");
	scanf("%f",&b);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Exp6 - Circle using Polar Equation");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(400,400);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
}

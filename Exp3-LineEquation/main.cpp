#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
float m,x1,y1,x2,y2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Co-Ordinate Lines
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(-200,0);
	glVertex2f(200,0);
	glVertex2f(0,200);
	glVertex2f(0,-200);
	glEnd();
	glColor3f(0,0,1);
	float m,c,y;
	m=(y2-y1)/(x2-x1);
	c=y1-(m*x1);
	printf("m = %f",m);
	glBegin(GL_POINTS);
	for(float i=x1;i<=x2;i++)
	{
		y=(m*i)+c;
		glVertex2f(i,y);
	}
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
	printf("Enter the starting point's x coordinate\n");
	scanf("%f",&x1);
	printf("Enter the starting point's y coordinate\n");
	scanf("%f",&y1);
	printf("Enter the end point's x coordinate\n");
	scanf("%f",&x2);
	printf("Enter the end point's y coordinate\n");
	scanf("%f",&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Exp3 - Line y=mx+c");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(400,400);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>
float rx,ry,xc,yc,x,y,dx,dy,d1,d2;
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
	x=0,y=ry;
	dx=2*ry*ry*x;
	dy=2*rx*rx*y;

	d1=(ry*ry)-(rx*rx*ry)-(0.25*rx*rx);       // d1 is the decision parameter of area 1

	while(dx<dy)
	{
		glBegin(GL_POINTS);
		glVertex2f(x+xc,y+yc);
		glVertex2f(-x+xc,y+yc);
		glVertex2f(x+xc,-y+yc);
		glVertex2f(-x+xc,-y+yc);
		glEnd();
		if(d1<0)
		{
			x=x+1;
			dx=dx+(2*ry*ry);
			d1=d1+dx+(ry*ry);
		}
		else
		{
			x=x+1;
			y=y-1;
			dx=dx+(2*ry*ry);
			dy=dy-(2*rx*rx);
			d1=d1+dx-dy+(ry*ry);
		}
	}

	d2=((ry*ry)*((x+0.5)*(x+0.5)))+((rx*rx)*((y-1)*(y-1)))-(rx*rx*ry*ry);	//d2 is the decision parameter of area 2
	while(y>=0)
	{
		glBegin(GL_POINTS);
		glVertex2f(x+xc,y+yc);
		glVertex2f(-x+xc,y+yc);
		glVertex2f(x+xc,-y+yc);
		glVertex2f(-x+xc,-y+yc);
		glEnd();
		if(d2>0)
		{
			y=y-1;
			dy=dy-(2*rx*rx);
			d2=d2+(rx*rx)-dy;
		}
		else
		{
			y=y-1;
			x=x+1;
			dx=dx+(2*ry*ry);
			dy=dy-(2*rx*rx);
			d2=d2+dx-dy+(rx*rx);
		}
	}
	glFlush();


}
int main(int argc, char **argv)
{
	printf("Enter Radius along X-axis: ");
	scanf("%f",&rx);
	printf("Enter Radius along Y-axis: ");
	scanf("%f",&ry);
	printf("Enter Center Co-ordinates\nX: ");
	scanf("%f",&xc);
	printf("Y: ");
	scanf("%f",&yc);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Exp8 - Ellipse using Bresenham");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(400,400);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
}

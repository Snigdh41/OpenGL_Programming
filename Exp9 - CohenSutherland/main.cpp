#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int c1=0,c2=0;
float m,c,y,x;
float pts[4],bdr[4];

void disply1()
{
    glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(-200,0);
	glVertex2f(200,0);
	glVertex2f(0,200);
	glVertex2f(0,-200);
	glEnd();

	glColor3f(1,0,0);
	glBegin(GL_LINES);
	glVertex2d(pts[0],pts[1]);
	glVertex2d(pts[2],pts[3]);
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(bdr[0],bdr[1]);
	glVertex2f(bdr[2],bdr[1]);
	glVertex2f(bdr[2],bdr[3]);
	glVertex2f(bdr[0],bdr[3]);
	glEnd();

	glFlush();
}

void mousefunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2d(pts[0],pts[1]);
	glVertex2d(pts[2],pts[3]);
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(-200,0);
	glVertex2f(200,0);
	glVertex2f(0,200);
	glVertex2f(0,-200);
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(bdr[0],bdr[1]);
	glVertex2f(bdr[2],bdr[1]);
	glVertex2f(bdr[2],bdr[3]);
	glVertex2f(bdr[0],bdr[3]);
	glEnd();

	int ch = 0;
	while(1)
	{
		if(c1==0 &&c2 ==0)
		{
			ch=1;
			break;
		}
		else if(c1&c2)
			break;
		else
		{
			int c3;
			c3= (c1!=0)?c1:c2;
			if(c3&8)
			{
				x=pts[0]+(pts[2]-pts[0])*(bdr[3]-pts[1])/(pts[3]-pts[1]);
				y=bdr[3];
			}
			else if(c3&4)
			{
				x=pts[0]+(pts[2]-pts[0])*(bdr[1]-pts[1])/(pts[3]-pts[1]);
				y=bdr[1];
			}
			else if(c3&2)
			{
				y=pts[1]+(pts[3]-pts[1])*(bdr[2]-pts[0])/(pts[2]-pts[0]);
				x=bdr[2];
			}
			else if(c3&1)
			{
				y=pts[1]+(pts[3]-pts[1])*(bdr[0]-pts[0])/(pts[1]-pts[0]);
				x=bdr[0];
			}
			if(c3 == c1)
			{
				pts[0]=x;
				pts[1]=y;
				c1 = (pts[0]<bdr[0])?1:(pts[0]>bdr[2])?2:0;
				c1+= (pts[1]<bdr[1])?4:(pts[1]>bdr[3])?8:0;
			}
			else
			{
				pts[2]=x;
				pts[3]=y;
				c2 = (pts[2]<bdr[0])?1:(pts[2]>bdr[2])?2:0;
				c2+= (pts[3]<bdr[1])?4:(pts[3]>bdr[3])?8:0;
			}
		}
	}
		glColor3f(1,0,0);
        glBegin(GL_LINES);
        glVertex2d(pts[0],pts[1]);
        glVertex2d(pts[2],pts[3]);
        glEnd();
        glFlush();
	}
}

int main(int argc, char** argv)
{
	printf("Screen Boundary -X : ");
	scanf("%f",&bdr[0]);
	printf("Screen Boundary +X : ");
	scanf("%f",&bdr[2]);
	printf("Screen Boundary -Y : ");
	scanf("%f",&bdr[1]);
	printf("Screen Boundary +Y : ");
	scanf("%f",&bdr[3]);

	printf("Enter Line x1: ");
	scanf("%f",&pts[0]);
	printf("Enter Line y1: ");
	scanf("%f",&pts[1]);
	printf("Enter Line x2: ");
	scanf("%f",&pts[2]);
	printf("Enter Line y2: ");
	scanf("%f",&pts[3]);

	c1 = (pts[0]<bdr[0])?1:(pts[0]>bdr[2])?2:0;
	c1+= (pts[1]<bdr[1])?4:(pts[1]>bdr[3])?8:0;
	c2 = (pts[2]<bdr[0])?1:(pts[2]>bdr[2])?2:0;
	c2+= (pts[3]<bdr[1])?4:(pts[3]>bdr[3])?8:0;

	glutInit(&argc,argv);
	glutCreateWindow("Line Clipping by Cohen-Sutherland");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(220,220);
	glClearColor(0,0,0,0);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(disply1);
	glutMouseFunc(mousefunc);
	glutMainLoop();
	return 0;
}

#include<windows.h>
#include<GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.64,0.016,0.016);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1,0.5);
	glVertex2f(-0.75,1);
	glVertex2f(-0.5,0.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.49,0.5);
	glVertex2f(-0.25,1);
	glVertex2f(0,0.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.01,0.5);
	glVertex2f(0.25,1);
	glVertex2f(0.5,0.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.51,0.5);
	glVertex2f(0.75,1);
	glVertex2f(1,0.5);
	glEnd();
	glColor3f(0.13,0.13,0.55);
	glBegin(GL_POLYGON);
	glVertex2f(-1,0.48);
	glVertex2f(1,0.48);
	glVertex2f(1,0.124);
	glVertex2f(-1,0.124);
	glEnd();
	glColor3f(0.41,0.55,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(-1,0.1245);
	glVertex2f(-1,-1);
	glVertex2f(1,-1);
	glVertex2f(1,0.1245);
	glEnd();
	glColor3f(0.8,0.19,0.6);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-0.25,-0.25);
	glVertex2f(-0.25,-0.75);
	glVertex2f(0.25,-0.75);
	glVertex2f(0.25,-0.25);
	glEnd();
	glColor3f(0.81,0.71,0.23);
	glBegin(GL_POLYGON);
	glVertex2f(-0.15,-0.75);
	glVertex2f(-0.15,-0.35);
	glVertex2f(0.15,-0.35);
	glVertex2f(0.15,-0.75);
	glEnd();
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0.001,0);
	glVertex2f(0.9,0.125);
	glVertex2f(1,-0.125);
	glVertex2f(0.251,-0.25);
	glEnd();
	glColor3f(0.89,0.47,0.20);
	glBegin(GL_POLYGON);
	glVertex2f(0.252,-0.25);
	glVertex2f(0.99,-0.125);
	glVertex2f(1,-0.75);
	glVertex2f(0.252,-0.75);
	glEnd();
	glFlush();
}
void onclick(int button, int state, int x, int y) {
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
glClearColor(0.22,0.69,0.87,1);
glutPostRedisplay();
}
}
void onclick1(unsigned char key,int x,int y)
{
if(key=='s'){
exit(1);
}
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(170,170);
	glutCreateWindow("Exp2 - Scenery");
	glClearColor(0,0,0,0);
	glutDisplayFunc(display);
	glutMouseFunc(onclick);
	glutKeyboardFunc(onclick1);
	glutMainLoop();
}

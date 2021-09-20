#include<windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
struct point2D { float x, y; };
const int   N = 20; // clipped (new) polygon size
point2D bdr[] = { {100,100}, {300,100}, {300,300}, {100,300} };
point2D pts[] = {{50,150}, {200,50}, {350,150}, {350,300}, {250,300}, {150,350}, {100,250}, {100,200}};
int resSize = 0, bdrSize = 4, ptsSize = 8;
point2D res[N] = { 0 };
void init()
{
    gluOrtho2D(0,400,0,400);
    glClearColor(0.0,0.0,0.0,1.0);
}

bool inside(point2D p, point2D p1, point2D p2)
{
    return (p2.y - p1.y) * p.x + (p1.x - p2.x) * p.y + (p2.x * p1.y - p1.x * p2.y) < 0;
}

point2D intersection(point2D cp1, point2D cp2, point2D s, point2D e)
{
    point2D dc = { cp1.x - cp2.x, cp1.y - cp2.y };
    point2D dp = { s.x - e.x, s.y - e.y };

    float n1 = cp1.x * cp2.y - cp1.y * cp2.x;           //variables of cramer's rule
    float n2 = s.x * e.y - s.y * e.x;
    float n3 = 1.0 / (dc.x * dp.y - dc.y * dp.x);

    return { (n1 * dp.x - n2 * dc.x) * n3, (n1 * dp.y - n2 * dc.y) * n3 };
}

// Sutherland-Hodgeman clipping
void SutherlandHodgeman(point2D *pts, int &ptsSize, point2D *bdr, int &bdrSize, point2D (&res)[N], int &resSize)
{
    point2D cp1, cp2, s, e, inputPolygon[N];

    // copy size to new polygon
    for(int i = 0; i < ptsSize; i++)
        res[i] = pts[i];

    resSize = ptsSize;

    for(int j = 0; j < bdrSize; j++)
    {
        // copy new polygon to input polygon & set counter to 0
        for(int k = 0; k < resSize; k++){ inputPolygon[k] = res[k]; }
        int counter = 0;
        cp1 = bdr[j];
        cp2 = bdr[(j + 1) % bdrSize];

        for(int i = 0; i < resSize; i++)
        {
            s = inputPolygon[i];
            e = inputPolygon[(i + 1) % resSize];

            // Case 1: Both vertex are inside: only second vertex is added to output list
            if(inside(s, cp1, cp2) && inside(e, cp1, cp2))
                res[counter++] = e;

            // Case 2: First vertex is outside while second one is inside: both intersection and second vertex will be added
            else if(!inside(s, cp1, cp2) && inside(e, cp1, cp2))
            {
                res[counter++] = intersection(cp1, cp2, s, e);
                res[counter++] = e;
            }

            // Case 3: First vertex is inside while second one is outside: point of intersection is added
            else if(inside(s, cp1, cp2) && !inside(e, cp1, cp2))
                res[counter++] = intersection(cp1, cp2, s, e);

            // Case 4: Both vertices are outside: No vertex to add
            else if(!inside(s, cp1, cp2) && !inside(e, cp1, cp2))
            {
            }
        }
        resSize = counter;
    }
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<ptsSize;i++)
        glVertex2d(pts[i].x,pts[i].y);
    glEnd();

    // Border
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2d(bdr[0].x,bdr[0].y);
	glVertex2d(bdr[1].x,bdr[1].y);
	glVertex2d(bdr[2].x,bdr[2].y);
	glVertex2d(bdr[3].x,bdr[3].y);
	glEnd();

	glFlush();
}
void mousebutton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    // Calculate clipped Polygon
        SutherlandHodgeman(pts, ptsSize, bdr, bdrSize, res, resSize);

	    // Erase every colored pixel from screen
	    glClear(GL_COLOR_BUFFER_BIT);

	    // Clipped Polygon
	    glColor3f(0,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<resSize;i++)
            glVertex2d(res[i].x,res[i].y);
        glEnd();

        // Boundary Printing
        glColor3f(0,1,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(bdr[0].x,bdr[0].y);
        glVertex2d(bdr[1].x,bdr[1].y);
        glVertex2d(bdr[2].x,bdr[2].y);
        glVertex2d(bdr[3].x,bdr[3].y);
        glEnd();
        glFlush();
	}
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(400,400);
    glutCreateWindow("Exp10 - Polygon Clipping");
    glutDisplayFunc(display);
    glutMouseFunc(mousebutton);
    init();
    glutMainLoop();

    return 0;
}

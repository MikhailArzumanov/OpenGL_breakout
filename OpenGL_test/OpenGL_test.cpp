#include "glut.h"

#include <iostream>

using namespace std;

int rx = 138, ry = 138;
int xCenter = 250, yCenter = 250;

void setPixel(const GLint x, const GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void ellipseMidPoint(float rx, float ry, float xCenter, float yCenter)
{
    float x = 0;
    float y = ry;
    float p1 = ry*ry-(rx*rx)*ry+(rx*rx)*(0.25f);
    float dx = 2*(ry*ry)*x;
    float dy = 2*(rx*rx)*y;
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    while (dx < dy)
    {
        cout << x << " " << y << " " << dx << " " << dy << " " << p1 <<"\n";
        setPixel(xCenter+x, yCenter+y);
        setPixel(xCenter-x, yCenter+y);
        setPixel(xCenter+x, yCenter-y);
        setPixel(xCenter-x, yCenter-y);
        if (p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 += dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + dx - dy + (ry * ry);
        }
    }

    float p2 = (ry*ry)*(x+0.5f)*(x+0.5f) + (rx*rx)*(y-1)*(y-1) - (rx*rx)*(ry*ry);
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    while (y > 0)
    {
        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
        if (p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx);
            dx = dx + 2 * (ry * ry);
            p2 = p2 + dx -
                dy + (rx * rx);
        }
    }
    glFlush();
}

void display_square() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(120,120);
    glVertex2i(230,120);
    glVertex2i(230,230);
    glVertex2i(120,230);
    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    ellipseMidPoint(rx,ry,xCenter,yCenter);
    //display_square();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(390, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("User_Name");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 388.0, 0.0, 480.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
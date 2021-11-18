#include "glut.h"

#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

int rx = 138, ry = 138;
int xCenter = 250, yCenter = 250;

struct point {
    float x, y;
};

struct Color {
    unsigned char r, g, b;
public:
    void set_to_env() {
        glColor3ub(r, g, b);
    }
};

class Drawable {
public:
    virtual void draw() = 0;
};

class Rectangle : public Drawable {
protected:
    point c;
    point r;
    Color color;
public:
    Rectangle(point c_, point r_, Color color_) {
        c = c_; r = r_; color = color_;
    }
    void draw() {
        glBegin(GL_POLYGON);
        color.set_to_env();
        glVertex2f(c.x - r.x, c.y - r.y);
        glVertex2f(c.x + r.x, c.y - r.y);
        glVertex2f(c.x + r.x, c.y + r.y);
        glVertex2f(c.x - r.x, c.y + r.y);
        glEnd();
        glFlush();
    }
};

class Square : public Rectangle {
public:
    Square(point c_, float r_, Color color_) :Rectangle(c_, { r_,r_ }, color_) {}
};

class Ellipse : public Drawable {
protected:
    point c;
    point r;
public:
    void draw() {

    }
};

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
    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25f);
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    while (dx < dy)
    {
        cout << x << " " << y << " " << dx << " " << dy << " " << p1 << "\n";
        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
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

    float p2 = (ry * ry) * (x + 0.5f) * (x + 0.5f) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);
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

std::vector<Drawable*> drawables;
void init_drawables() {
    drawables.push_back(new Square({ 39.f, 39.f }, 38.f, Color{ 255,255,255 }));
    drawables.push_back(new Square({ 325.f,313.f }, 40.f, Color{ 255,255,255 }));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    ellipseMidPoint(rx, ry, xCenter, yCenter);
    for (auto drawable : drawables)
        drawable->draw();
}
int main(int argc, char** argv)
{
    init_drawables();

    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Window1");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1280.0, 0.0, 720.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
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
    Square(point c_, float r_, Color color_) :Rectangle(c_, {r_,r_}, color_) {}
};

class Ellipse : public Drawable {
protected:
    point c;
    point r;
    Color color;
public:
    Ellipse(point c_, point r_, Color color_) {
        c = c_; r = r_; color = color_;
    }
    void draw() {
        glBegin(GL_POINTS);
            float rx = r.x, ry = r.y, xCenter = c.x, yCenter = c.y;

            float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25f);

            float x = 0;
            float y = ry;

            float dx = 2 * (ry * ry) * x;
            float dy = 2 * (rx * rx) * y;
            color.set_to_env();
            while (dx < dy) {
                glVertex2f(xCenter + x, yCenter + y);
                glVertex2f(xCenter - x, yCenter + y);
                glVertex2f(xCenter + x, yCenter - y);
                glVertex2f(xCenter - x, yCenter - y);
                if (p1 < 0) {
                    x = x + 1;
                    dx = 2 * (ry * ry) * x;
                    p1 += dx + (ry * ry);
                }
                else {
                    x = x + 1;
                    y = y - 1;
                    dx = 2 * (ry * ry) * x;
                    dy = 2 * (rx * rx) * y;
                    p1 = p1 + dx - dy + (ry * ry);
                }
            }

            float p2 = (ry * ry) * (x + 0.5f) * (x + 0.5f) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);

            while (y >= 0) {
                glVertex2f(xCenter + x, yCenter + y);
                glVertex2f(xCenter - x, yCenter + y);
                glVertex2f(xCenter + x, yCenter - y);
                glVertex2f(xCenter - x, yCenter - y);
                if (p2 > 0) {
                    x = x;
                    y = y - 1;
                    dy = 2 * (rx * rx) * y;
                    p2 = p2 - dy + (rx * rx);
                }
                else {
                    x = x + 1;
                    y = y - 1;
                    dy = dy - 2 * (rx * rx);
                    dx = dx + 2 * (ry * ry);
                    p2 = p2 + dx -
                        dy + (rx * rx);
                }
            }
        glEnd();
    }
};

std::vector<Drawable*> drawables;
void init_drawables() {
    for (float x = 138.f; x <= 249.f; x += 1.f)
        drawables.push_back(new Ellipse({ x,250.f }, { 138.f,138.f }, Color{255,128,128}));
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    int start = clock();
    for (auto drawable : drawables)
        drawable->draw();
    int end = clock();
    cout << end - start <<"\n";
    glFlush();
}
int main(int argc, char** argv){
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
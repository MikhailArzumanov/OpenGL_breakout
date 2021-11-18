#include "ellipse.hpp"
#include <glut.h>

void Ellipse::draw() {
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
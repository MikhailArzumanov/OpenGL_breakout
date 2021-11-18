#include "rectangle.hpp"
#include <glut.h>
#include <iostream>

void Rectangle::draw() {
    glBegin(GL_POLYGON);
    color.set_to_env();
    glVertex2f(c.x - r.x, c.y - r.y);
    glVertex2f(c.x + r.x, c.y - r.y);
    glVertex2f(c.x + r.x, c.y + r.y);
    glVertex2f(c.x - r.x, c.y + r.y);
    glEnd();
}
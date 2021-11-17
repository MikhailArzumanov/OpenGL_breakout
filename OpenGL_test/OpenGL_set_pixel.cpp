#include "OpenGL_drawing.hpp"


void setPixel(const GLint x, const GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
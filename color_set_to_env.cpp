#include <glut.h>
#include "color.hpp"

void Color::set_to_env() {
    glColor3ub(r, g, b);
}
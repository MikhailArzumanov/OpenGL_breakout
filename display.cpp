#include "main_program_functions.hpp"
#include <glut.h>

#define let auto
#define of :

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    draw_scene();
    glFlush();
}
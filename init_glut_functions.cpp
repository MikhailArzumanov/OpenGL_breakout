#include "main_program_functions.hpp"
#include <glut.h>

void init_glut_functions() {
    glutDisplayFunc(display);
    glutTimerFunc(40, tick, 0);
}
#include "main_program_functions.hpp"
#include <glut.h>

int x = 0;

void tick(int null) {
    move();
    collide();
    live();
    handle_keys();
    glutPostRedisplay();
    glutTimerFunc(40, tick, 0);
}
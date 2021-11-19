#include "main_program_functions.hpp"
#include <glut.h>
#include "is_key_down.hpp"

void key_down(unsigned char key, int x, int y) {
    is_key_down[key] = true;
}

void key_up(unsigned char key, int x, int y) {
    is_key_down[key] = false;
}

void init_glut_functions() {
    glutKeyboardFunc(key_down);
    glutKeyboardUpFunc(key_up);
    glutDisplayFunc(display);
    glutTimerFunc(40, tick, 0);
}
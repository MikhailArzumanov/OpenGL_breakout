#include "main_program_functions.hpp"
#include <glut.h>

void init_glut(int& argc, char**& argv) {
    glutInit(&argc, argv);
    init_glut_window();
    init_glut_functions();
}
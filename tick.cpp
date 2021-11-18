#include "main_program_functions.hpp"
#include "the_square.hpp"
#include <iostream>
#include <glut.h>

int x = 0;

void tick(int null) {
    x = (x + 12) % 100;
    std::cout << x << "\n";
    square->set_c({ (float)x,100 });
    glutPostRedisplay();
    glutTimerFunc(40, tick, 0);
}
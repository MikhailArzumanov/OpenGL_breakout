#include <glut.h>

#include "main_program_functions.hpp"

using namespace std;


int main(int argc, char** argv){
    init_env();
    init_glut(argc,argv);
    glutMainLoop();
    return 0;
}
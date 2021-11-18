#include "main_program_functions.hpp"
#include "the_square.hpp"
#include "drawables.hpp"


void init_drawables() {
    square = new Square({ 0,0 }, 40, { 255,255,255 });
    drawables.push_back(square);
}
#include "main_program_functions.hpp"
#include "is_key_down.hpp"

void init_key_map() {
    is_key_down = new bool[256]{ false };
}
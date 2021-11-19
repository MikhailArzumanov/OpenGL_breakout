#include "main_program_functions.hpp"
#include "is_key_down.hpp"
#include "the_racket.hpp"

void handle_keys() {
	if (is_key_down['d'] || is_key_down['D'])
		the_racket->move_right();
	if (is_key_down['a'] || is_key_down['A'])
		the_racket->move_left();
}
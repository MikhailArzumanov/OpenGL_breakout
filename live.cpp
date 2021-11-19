#include "main_program_functions.hpp"
#include "scene.hpp"

#define let auto
#define of :

void live() {
	if (!the_racket->does_live()) {
		the_racket->die();
	}
	if (!the_ball->does_live()) {
		the_ball->die();
	}
	for (let iterator = the_net.begin(); iterator != the_net.end();iterator++) {
		let net = *iterator;
		if (!net->does_live()) {
			net->die();
			the_net.erase(iterator--);
		}
	}
}
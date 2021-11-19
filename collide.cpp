#include "main_program_functions.hpp"
#include "scene.hpp"

#define let auto
#define of :

void collide() {
	if (the_racket->is_colliding_with(the_ball))
		the_ball->collide_with(the_racket);
	for (let net of the_net) {
		if (the_ball->is_colliding_with(net)) {
			the_ball->collide_with(net);
			net->collide_with(the_ball);
		}

	}
}
#include "main_program_functions.hpp"
#include "scene.hpp"

#define let auto
#define of :

void draw_scene() {
	the_racket->draw();
	the_ball->draw();
	for (let net of the_net)
		net->draw();
}
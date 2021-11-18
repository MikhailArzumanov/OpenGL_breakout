#include "racket.hpp"

const point racket_start_position{325,57};
const point racket_size{70,19};
const Color racket_color{38,70,40};

Racket::Racket():Rectangle(racket_start_position, racket_size, racket_color){
	v = {0,0};
}
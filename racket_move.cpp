#include "racket.hpp"

void Racket::move() {
	c += v;
	v = {0,0};
}
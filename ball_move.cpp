#include "ball.hpp"

const float field_width = 1280;

void Ball::move() {
	c += v;
	if (c.x <= 0 || c.x >= field_width){
		v.x = -v.x;
		c.x += v.x;
	}
}
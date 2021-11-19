#include "ball.hpp"

const float field_width  = 1280;
const float field_height = 720;

void Ball::move() {
	c += v;
	if (c.x-r.x <= 0 || c.x+r.x >= field_width){
		v.x = -v.x;
		c.x += v.x;
	}
	if (c.y + r.y >= field_height) {
		v.y = v.y;
		c.y += v.y;
	}
}
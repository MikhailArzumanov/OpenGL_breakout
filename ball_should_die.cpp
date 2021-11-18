#include "ball.hpp"

bool Ball::should_die() {
	return c.y < 0;
}
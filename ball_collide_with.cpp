#include "ball.hpp"

void Ball::collide_with(Collidable* another) {
	switch (another->type) {
	case Collidable::racket:
	case Collidable::net:
		v.y = -v.y;
		c.y += v.y;
		break;
	}
}
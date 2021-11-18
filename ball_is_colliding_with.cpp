#include "ball.hpp"
#include <cmath>

bool Ball::is_colliding_with(Collidable* another) {
	switch (another->type) {
	case Collidable::racket:
	case Collidable::net:
		auto obj = (Rectangle*)another;
		return is_colliding(obj);
	}
}
#include "racket.hpp"
#include "ball.hpp"
#include "net.hpp"

bool Ball::is_colliding_with(Collidable* another) {
	switch (another->type) {
	case Collidable::racket:
		return is_colliding(static_cast<Rectangle*>(static_cast<Racket*>(another)));
	case Collidable::net:
		return is_colliding(static_cast<Rectangle*>(static_cast<Net*>(another)));
	}
}
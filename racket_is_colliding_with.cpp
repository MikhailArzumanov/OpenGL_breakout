#include "racket.hpp"

bool Racket::is_colliding_with(Collidable* another) {
	switch(another->type){
	case Collidable::ball:
		auto obj = (Rectangle*)another;
		return is_colliding(obj);
	default:
	}
}
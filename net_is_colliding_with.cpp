#include "net.hpp"
#include "ball.hpp"

bool Net::is_colliding_with(Collidable* another) {
	switch(another->type){
	case Collidable::ball:
		return is_colliding(static_cast<Rectangle*>(static_cast<Ball*>(another)));
	}
}
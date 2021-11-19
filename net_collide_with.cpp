#include "net.hpp"

void Net::collide_with(Collidable* another) {
	switch (another->type) {
	case Collidable::ball:
		is_living = false;
		break;
	}
}
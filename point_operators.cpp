#include "point.hpp"

void point::operator+=(point another) {
	x += another.x;
	y += another.y;
}
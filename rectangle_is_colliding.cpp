#include "rectangle.hpp"
#include <cmath>


bool Rectangle::is_colliding(Rectangle* another) {
	return (abs(c.x-another->get_c().x)< (r.x+another->get_r().x))
									   &&
		   (abs(c.y-another->get_c().y) <(r.y+another->get_r().y));
}
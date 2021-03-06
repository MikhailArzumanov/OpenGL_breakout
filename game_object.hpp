#pragma once
#include "collidable.hpp"

class GameObject : public Collidable {
protected:
	bool is_living;
public:
	bool does_live() {return is_living;}
	virtual bool should_die() = 0;
	virtual void move() = 0;
	virtual void die() = 0;
};
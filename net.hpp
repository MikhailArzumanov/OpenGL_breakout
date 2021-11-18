#pragma once
#include "rectangle.hpp"
#include "game_object.hpp"

class Net : public Rectangle, public GameObject {
public:
	Net(point c_);

	bool is_colliding_with(Collidable* another);
	void collide_with(Collidable* another);

	virtual bool should_die();
	virtual void move();
	virtual void die();
};
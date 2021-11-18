#pragma once
#include "rectangle.hpp"
#include "game_object.hpp"

class Ball : public Rectangle, public GameObject {
	point v;
public:
	Ball();

	bool is_colliding_with(Collidable* another);
	void collide_with(Collidable* another);

	virtual bool should_die();
	virtual void move();
	virtual void die();
};
#pragma once
#include "rectangle.hpp"
#include "game_object.hpp"


class Racket : public Rectangle, public GameObject {
	point v;
public:
	Racket();

	bool is_colliding_with(Collidable* another);
	void collide_with(Collidable* another);

	bool should_die();
	void move();
	void die();

	void move_right();
	void move_left();
};
#pragma once
class Collidable {
public:
	enum CollidableType {
		racket,
		ball,
		net
	};
	CollidableType type;

	virtual bool is_colliding_with(Collidable* another) = 0;
	virtual void collide_with(Collidable* another)	    = 0;
};
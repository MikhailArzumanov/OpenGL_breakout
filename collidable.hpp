#pragma once
class Collidable {
	virtual bool is_collide_with(Collidable* another) = 0;
	virtual void collide_with(Collidable* another)	  = 0;
};
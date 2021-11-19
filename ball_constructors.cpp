#include "ball.hpp"

const point ball_start_position{313,120};
const point ball_start_velocity{7,-7};
const point ball_size{20,20};
const Color ball_color{40,70,112};


Ball::Ball():Rectangle(ball_start_position,ball_size,ball_color){
	v = ball_start_velocity; type = Collidable::ball;
}
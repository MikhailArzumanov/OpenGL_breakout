#pragma once
#include "ellipse.hpp"

class Circle : public Ellipse {
public:
	Circle(point c_, float r_, Color color_):Ellipse(c_,{r_,r_},color_) {}
};
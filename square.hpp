#pragma once
#include "rectangle.hpp"
class Square : public Rectangle {
public:
    Square(point c_, float r_, Color color_):Rectangle(c_, { r_,r_ }, color_){}
};

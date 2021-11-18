#pragma once
#include "drawable.hpp"
#include "shape.hpp"

class Rectangle : public Drawable, public Shape {
public:
    Rectangle(point c_, point r_, Color color_);
    bool is_colliding(Rectangle* another);
    void draw();
};
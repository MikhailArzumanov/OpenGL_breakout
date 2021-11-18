#pragma once
#include "drawable.hpp"
#include "shape.hpp"

class Ellipse : public Drawable, public Shape {
public:
    Ellipse(point c_, point r_, Color color_);
    void draw();
};
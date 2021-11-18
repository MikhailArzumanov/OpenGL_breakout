#pragma once
#include "point.hpp"
#include "color.hpp"

class Shape {
protected:
    point c;
    point r;
    Color color;
public:
    point get_c();
    point get_r();
    Color get_color();

    void  set_c(point c_);
    void  set_r(point r_);
    void  set_color(Color color_);
};
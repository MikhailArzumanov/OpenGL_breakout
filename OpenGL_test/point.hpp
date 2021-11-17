#pragma once
struct point {
    float x, y;

    point operator+(const point another)const;
    point operator-(const point another)const;
    point operator*(const float scalar)const;
    point operator/(const float scalar)const;

    point operator+=(const point another);
    point operator-=(const point another);
    point operator*=(const float scalar);
    point operator/=(const float scalar);
};
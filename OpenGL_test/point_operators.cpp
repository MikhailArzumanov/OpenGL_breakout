#include "point.hpp"
point point::operator+(const point another)const {
    return point{ x + another.x, y + another.y };
}
point point::operator-(const point another)const {
    return point{ x - another.x, y - another.y };
}
point point::operator*(const float scalar)const {
    return point{ x * scalar,y * scalar };
}
point point::operator/(const float scalar)const {
    return point{ x / scalar,y / scalar };
}
point point::operator+=(const point another) {
    x += another.x;
    y += another.y;
    return *this;
}
point point::operator-=(const point another) {
    x -= another.x;
    y -= another.y;
    return *this;
}
point point::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}
point point::operator/=(const float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
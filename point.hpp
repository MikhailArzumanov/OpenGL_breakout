#pragma once

struct point {
    float x, y;

    void operator+=(point another);
};

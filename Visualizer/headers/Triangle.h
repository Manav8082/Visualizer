#pragma once
#include "Point.h"

class Triangle {
private:
    Point p1;
    Point p2;
    Point p3;
    Point normal;
public:
    Triangle(Point p1, Point p2, Point p3);
    ~Triangle();
    Point P1() const;
    Point P2() const;
    Point P3() const;
};

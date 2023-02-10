#pragma once
#include"polygon.hpp"

class Parallelogram: public Polygon {

public:
     Parallelogram(Point point1, Point point2, Point point3);
     virtual float area() const;
     virtual float perimeter() const;
     virtual void print(std::ostream& os) const;

};
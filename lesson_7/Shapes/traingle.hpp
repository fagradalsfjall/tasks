#pragma once
#include"polygon.hpp"

class Triangle: public Polygon {

public:
     Triangle(Point point1, Point point2, Point point3);
     virtual float area() const;
     virtual float perimeter() const;
     virtual void print(std::ostream& os) const;

};
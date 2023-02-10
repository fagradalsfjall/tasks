#pragma once
#include"rectangle.hpp"

class Square: public Rectangle {

public:
     Square(Point point1, Point point2);
     virtual void print(std::ostream& os) const;
};
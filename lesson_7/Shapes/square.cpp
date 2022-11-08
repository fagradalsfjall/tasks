#include<iostream>
#include"square.hpp"
#include"rectangle.hpp"
#include<math.h>

Square::Square(Point point1, Point point2)
        :Rectangle(point1, point2, distance(point1, point2)) {
    
};


void Square::print(std::ostream& os) const
{
    os << "Квадрат" << std::endl;
    Polygon::print(os);
}
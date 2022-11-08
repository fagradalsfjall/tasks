#include<iostream>
#include"romb.hpp"
#include"parallelogram.hpp"
#include <cmath>

Point Romb::third_point_of_romb(Point point1, Point point2, float angle) {

float delta_y = point1.second - point2.second;
float delta_x = point1.first - point2.first;

float new_delta_x = delta_x*cos(angle) - delta_y*sin(angle);
float new_delta_y = delta_x*sin(angle) + delta_y*cos(angle);

Point point3(new_delta_x + point2.first, new_delta_y + point2.second);

return point3;

};

Romb::Romb(Point point1, Point point2, float angle)
        :Parallelogram(point1, point2, third_point_of_romb(point1, point2, angle)) {

};


void Romb::print(std::ostream& os) const
{
    os << "Ромб" << std::endl;
    Polygon::print(os);
}
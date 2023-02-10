#include<iostream>
#include"rectangle.hpp"
#include<math.h>

Point Rectangle::third_point_of_rectangle(Point point1, Point point2, float lengh) {

float delta_x = point2.second - point1.second;
float delta_y = point1.first - point2.first;

float mult = lengh / sqrt(delta_x*delta_x + delta_y*delta_y);

Point point3(delta_x * mult + point2.first, delta_y * mult + point2.second);

return point3;

};

Rectangle::Rectangle(Point point1, Point point2, float lengh)
        :Parallelogram(point1, point2, 
        third_point_of_rectangle(point1, point2, lengh)) {
    

};


void Rectangle::print(std::ostream& os) const
{
    os << "Прямоугольник" << std::endl;
    Polygon::print(os);
}
#include<iostream>
#include"polygon.hpp"
#include <math.h>

Polygon::Polygon(const std::vector<Point>& points) {  
  this->points.assign(points.begin(), points.end());
};

float Polygon::distance(Point point1, Point point2) const {
return sqrt((point2.first - point1.first)*(point2.first - point1.first) + (point2.second - point1.second)*(point2.second - point1.second));
};

void Polygon::print(std::ostream& os) const
{
    for (int i=0; i < points.size(); i++)
    {
        std::cout << points[i] << std::endl;
    }
    // os << centre << std::endl <<"большая полуось " << semimajor << std::endl <<"меньшая полуось " << semimajor*sqrt(1-eccentricity*eccentricity) << std::endl;
}
#include<iostream>
#include"traingle.hpp"

Triangle::Triangle(Point point1, Point point2, Point point3):Polygon(std::vector<Point>({point1, point2, point3})) {

};

float Triangle::area() const
{
    float S = 0.5*((points[2].first-points[0].first)*(points[2].second-points[1].second) - (points[2].first-points[1].first)*(points[2].second-points[0].second));
    return S;
}


float Triangle::perimeter() const
{
    float P = distance(points[0], points[1]) + distance(points[1],points[2]) + distance(points[2],points[0]);
    return P;
}

void Triangle::print(std::ostream& os) const
{
    os << "Треугольник" << std::endl;
    Polygon::print(os);
}
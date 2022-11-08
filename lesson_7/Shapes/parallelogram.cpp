#include<iostream>
#include"parallelogram.hpp"
#include <cmath>

Parallelogram::Parallelogram(Point point1, Point point2, Point point3)
        :Polygon(std::vector<Point>({point1, point2, point3})) {
    Point point4;
    point4.first = point1.first - point2.first + point3.first;
    point4.second = point1.second - point2.second + point3.second;

    points.push_back(point4);

};

float Parallelogram::area() const
{
    float S = ((points[2].first-points[0].first)*(points[2].second-points[1].second) - (points[2].first-points[1].first)*(points[2].second-points[0].second));
    return std::abs(S);
}


float Parallelogram::perimeter() const
{
    float P = 2*distance(points[0], points[1]) + 2*distance(points[1],points[2]);
    return P;
}

void Parallelogram::print(std::ostream& os) const
{
    os << "Параллелограмм" << std::endl;
    Polygon::print(os);
}
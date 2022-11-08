#pragma once
#include<utility>
#include<iostream>

#define M_PI 3.14159265358979323846

class Shape{

public:
virtual float area() const = 0;
virtual float perimeter() const = 0;
virtual void print(std::ostream& os) const = 0;

friend std::ostream& operator<<(std::ostream& os, const Shape& shape);

};

using Point=std::pair<float, float>;

std::ostream& operator<<(std::ostream& os, const Point& point);


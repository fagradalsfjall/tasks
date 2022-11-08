#pragma once
#include"shape.hpp"
#include"utility"
#include<iostream>
#include<vector>

class Polygon: public Shape {
    protected:
    std::vector<Point> points;

public:
     Polygon(const std::vector<Point>& points);
    //  virtual float area() const;
    //  virtual float perimeter() const;
    //  virtual void print(std::ostream& os) const;
    float distance(Point point1, Point point2) const;
    void print(std::ostream& os) const;

};
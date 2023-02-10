#pragma once
#include"parallelogram.hpp"

class Rectangle: public Parallelogram {

public:
     Rectangle(Point point1, Point point2, float lengh);
     virtual void print(std::ostream& os) const;
    static Point third_point_of_rectangle(Point point1, Point point2, float lengh);
};
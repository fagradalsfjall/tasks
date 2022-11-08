#pragma once
#include"parallelogram.hpp"

class Romb: public Parallelogram {

public:
     Romb(Point point1, Point point2, float angle);
    
     virtual void print(std::ostream& os) const;

     static Point third_point_of_romb(Point point1, Point point2, float angle);

};
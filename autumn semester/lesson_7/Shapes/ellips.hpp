#pragma once
#include"shape.hpp"
#include"utility"

class Ellips: public Shape {
    protected:
    std::pair<float, float> centre;
    float semimajor;
    float eccentricity;

public:
     Ellips(Point centre, float semimajor, float eccentricity);
     virtual float area() const;
     virtual float perimeter() const;
     virtual void print(std::ostream& os) const;

};


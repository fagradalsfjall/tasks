#pragma once
#include"ellips.hpp"

class Circle: public Ellips {

public:
     Circle(Point centre, float semimajor);
    //  virtual float area() const;
    //  virtual float perimeter() const;
     virtual void print(std::ostream& os) const;

};
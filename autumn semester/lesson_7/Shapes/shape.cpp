#include "shape.hpp"

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os <<'(' << point.first << ';' << point.second << ")" << std::endl;
    return os; 
}

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    shape.print(os); 
    os << "S = " << shape.area() << std::endl << "P = " << shape.perimeter() << std::endl;
    return os;
}
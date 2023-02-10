#include<iostream>
#include"circle.hpp"

Circle::Circle(Point centre, float semimajor):Ellips(centre, semimajor, 0) {};

void Circle::print(std::ostream& os) const
{
    os << "Окружность" << std::endl << centre << std::endl <<"радиус " << semimajor << std::endl;
}
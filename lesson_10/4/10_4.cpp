#include<iostream>
#include"10_4.hpp"
#include <math.h>

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os <<'(' << point.first << ';' << point.second << ")" << std::endl;
    return os; 
}

template <typename Derived>
Ellips<Derived>::Ellips(Point centre, float semimajor, float eccentricity) {
  this->centre = centre;
  this->semimajor = semimajor;
  this->eccentricity = eccentricity;  
};

template <typename Derived>
void Ellips<Derived>::print(std::ostream& os) const
{
    os << "Эллипс" << std::endl << centre << std::endl <<"большая полуось " << semimajor << std::endl <<"меньшая полуось " << semimajor*sqrt(1-eccentricity*eccentricity) << std::endl;
}


Circle::Circle(Point centre, float semimajor):Ellips(centre, semimajor, 0) {};

void Circle::print(std::ostream& os) const
{
    os << "Окружность" << std::endl << centre << std::endl <<"радиус " << semimajor << std::endl;
}

int main(){

Circle okruzhnost({1, 2}, 3);
std::cout << okruzhnost;
// Ellips& a = okruzhnost;
// std::cout << a;
// Ellips ellips({4, 5}, 6, 1);
// std::cout << ellips;

return 0;
}
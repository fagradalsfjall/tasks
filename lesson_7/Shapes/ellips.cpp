#include<iostream>
#include"ellips.hpp"
#include <math.h>

Ellips::Ellips(Point centre, float semimajor, float eccentricity) {
  this->centre = centre;
  this->semimajor = semimajor;
  this->eccentricity = eccentricity;  
};

float Ellips::area() const
{
    float S = M_PI*semimajor*semimajor*sqrt(1-eccentricity*eccentricity);
    return S;
}


float Ellips::perimeter() const
{
    float P = 2*M_PI*sqrt((semimajor*semimajor + semimajor*sqrt(1-eccentricity*eccentricity)*semimajor*sqrt(1-eccentricity*eccentricity))/2);
    return P;
}

void Ellips::print(std::ostream& os) const
{
    os << "Эллипс" << std::endl << centre << std::endl <<"большая полуось " << semimajor << std::endl <<"меньшая полуось " << semimajor*sqrt(1-eccentricity*eccentricity) << std::endl;
}

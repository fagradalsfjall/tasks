#pragma once
#include"utility"


using Point=std::pair<float, float>;

std::ostream& operator<<(std::ostream& os, const Point& point);

template <typename Derived>
class Ellips {
    protected:
    std::pair<float, float> centre;
    float semimajor;
    float eccentricity;

    

public:
     Ellips(Point centre, float semimajor, float eccentricity);
     void print(std::ostream& os) const;

    void print_dispetcher(std::ostream& os) {
        static_cast<Derived *>(this)->print(os);
    }
    
     friend std::ostream& operator<< (std::ostream& os, Ellips<Derived>& shape) {
        shape.print(os);
        shape.print_dispetcher(os);
     };

};




class Circle: public Ellips<Circle> {

public:
     Circle(Point centre, float semimajor);
     void print(std::ostream& os) const;

};
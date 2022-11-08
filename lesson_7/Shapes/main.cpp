#include "ellips.hpp"
#include "circle.hpp"
#include "traingle.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "romb.hpp"

#include <array>
int main() {


    std::vector<Shape*> figures;

    figures.push_back(new Ellips(Point(3, 4), 5,0.5));
    figures.push_back(new Circle(Point(3, 4), 5));
    figures.push_back(new Triangle(Point(3, 4), Point(10, 11), Point(15, 27))); 
    figures.push_back(new Parallelogram(Point(3, 4), Point(10, 11), Point(15, 27))); 
    figures.push_back(new Rectangle(Point(3, 4), Point(10, 11), 11)); 
    figures.push_back(new Square(Point(1, 2), Point(4, 3))); 
    figures.push_back(new Romb(Point(1, 2), Point(4, 3), 1.57)); 

    for (std::vector<Shape*>::iterator it = figures.begin() ; it != figures.end(); ++it)
        std::cout << **it;

    for (std::vector<Shape*>::iterator it = figures.begin() ; it != figures.end(); ++it)
        delete *it; 

    return 0;
}

 /*
    Ellips ellips(Point(3, 4), 5,0.5);
    std::cout << ellips;  

    Circle circle(Point(3, 4), 5);
    std::cout << circle; 

    Triangle triangle(Point(3, 4), Point(10, 11), Point(15, 27));
    std::cout << triangle; 

    Parallelogram parallelogram(Point(3, 4), Point(10, 11), Point(15, 27));
    std::cout << parallelogram; 

    Rectangle rectangle(Point(3, 4), Point(10, 11), 11);
    std::cout << rectangle; 

    Square square(Point(1, 2), Point(4, 3));
    std::cout << square; 

    Romb romb(Point(1, 2), Point(4, 3), 1.57);
    std::cout << romb; */
#include<iostream>
#include"teorver.hpp"
#include"differential_equations.hpp"

int main(){

    Teorver teorver;
    Differential_equations difury;

    std::cout << teorver.calc(2.47, 0.8, 0.7) << std::endl;
    std::cout << difury.calc(1.58, 3, 0) << std::endl;

    return 0;
}
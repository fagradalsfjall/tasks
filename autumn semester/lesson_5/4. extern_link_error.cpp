#include <iostream>
#include "bow.hpp"

using namespace std;
float tension(float koefficient, float base, float real_expansion);

int main() {

    cout << "static tension(): " << Bow::tension(1, 15, 76) << endl;
    return 0;
}
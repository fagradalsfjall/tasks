#include <vector>
#include <iostream>

template <typename F, class...Other>
auto caller(F callable,Other...other)
{
    // std::cout<<sizeof(A)<<std::endl;
    // new A();

    return callable(other...);
}

int sum(int a, int b) {
    return a + b;
};

double raz(double a, double b) {
    return a - b;
};

int main()
{
    std::cout << caller(sum, 2, 3) << std::endl;
    std::cout << " " << caller(raz, 2, 3) << std::endl;

}

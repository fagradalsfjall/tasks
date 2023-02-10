#include <vector>
#include <iostream>

template <typename A, class...Other>
A *constructor(Other...other)
{
    // std::cout<<sizeof(A)<<std::endl;
    // new A();

    return new A(other...);
}

int main()
{

    std::vector<int> *uu = constructor<std::vector<int>>(2, 3);
    std::vector<int> *u1 = constructor<std::vector<int>>(5);

    std::cout << uu->size() << std::endl;
    std::cout << u1->size() << std::endl;

    delete uu;
    delete u1;

}

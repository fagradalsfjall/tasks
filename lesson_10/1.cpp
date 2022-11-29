#include<iostream>
#include<vector>

int packet_size_recursive() {return 0;};
template<class F, class...Other>
int packet_size_recursive(const F&f, const Other...other)
{
    int res_prev = packet_size_recursive(other...);
    int return_value = sizeof(f) + res_prev;
    return return_value;
}

template<class...Other>
int packet_size_svertka(const Other...other)
{
    return (sizeof(other) + ...);
}


int main () {
    int r = 3;
    int rr = 5;
    double tt = 5.2;
    std::cout << "Размер пачки " << packet_size_recursive(r, rr, tt) << std::endl;
    std::cout << "Размер пачки свертка " << packet_size_svertka(r, rr, tt) << std::endl;
    // packet_size_recursive(r, rr, 45, 65, tt,  "dfgfdgdfg", 'a', std::string("dfgiiihj"));

    return 0;
}
#include<iostream>
#include<vector>

struct Struct
{
    int arr[6000];
};


int main(){

    std::vector <Struct> vector;

    std::cout << vector.capacity() << std::endl;

    vector.reserve(13);

    int g = 1;

    int predyduschaya_capacity = vector.capacity();
    for (int i = 0; i < 8730249782687; i++){
        vector.push_back(Struct());
        int capacity = vector.capacity();
            if (capacity != predyduschaya_capacity) {
                std::cout << i << " " << vector.capacity() << " " << vector.size() <<  std::endl;
                predyduschaya_capacity = capacity;
            }

    }
// Емкость векторов при нехватке памяти для размещения новых элементов увеличивается в два раза. Capacity получаются степенями двойки.
// Если задать начальное значение вручную - заполняется до значения, установленного функцией reserve. Далее увеличивается в два раза.
// В предельном случае отличий в поведении не замечено. Программа падает раньше(
// 1664 3328 1665
// 3328 6656 3329
// 6656 13312 6657
// 13312 26624 13313
// The program 'C:\Users\salty\PROGA\3_1.exe' has exited with code 3 (0x00000003).

    return 0;
}
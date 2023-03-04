#include<iostream>
#include<array>

int hash_double(double chislo){

    uint8_t* data = (uint8_t*)(&chislo);

    uint8_t slozhili = 0;

    for (int i = 0; i < sizeof(chislo); i++){

        slozhili += data[i];

    }

return slozhili;

}

int main(){

std::cout << hash_double(1) << std::endl;
std::cout << hash_double(2) << std::endl;

const int N=256;
std::array<int, N> array;
    for (int i = 0; i < N; i++)
        array[i] = 0;

for (int i = 0; i < 1000000; i++){
    array[hash_double(i)] += 1; 

}

for (int i = 0; i < N; i++){
    std::cout << array[i] << " ";

}
    return 0;
}
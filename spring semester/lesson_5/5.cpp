#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <functional>

void print_vector(std::vector<int> &vector, std::string text, int length = 0){

    auto end = vector.end() + length;

    if (length > 0)
        end = vector.begin() + length;

    std::cout << text << " ";

    for (auto it = vector.begin(); it != end; it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


bool is_prime (int i) {
    for (int j = 2; j*j < i; j++){
        if (i % j == 0)
            return false;

    return true;
}

}


int main(){

std::vector<int> p1(10);

for (int i = 0; i < p1.size(); i++){
    p1[i] = i+1;
}

    p1.push_back(3);
    p1.push_back(5);
    p1.push_back(7);
    p1.push_back(7);

int cur_number = -1;
// std::cin >> cur_number;
while (cur_number > 0){
    p1.push_back(cur_number);
    std::cin >> cur_number;
}



print_vector(p1, "последовательность П1");
random_shuffle(p1.begin(), p1.end());
print_vector(p1, "перемешали");

random_shuffle(p1.begin(), p1.end());
print_vector(p1, "перемешали, чтоб наверняка");


std::sort(p1.begin(), p1.end()); 
auto last = std::unique(p1.begin(), p1.end());
p1.erase(last, p1.end());
print_vector(p1, "убираем дубликаты");

random_shuffle(p1.begin(), p1.end());

int nechetnye = std::count_if(p1.begin(), p1.end(), [](int i) { return i % 2 == 1; });
std::cout << "количество нечетных " << nechetnye << std::endl;

std::cout << "максимальный элемент " << *max_element(p1.begin(), p1.end()) << std::endl;
std::cout << "минимальный элемент " << *min_element(p1.begin(), p1.end()) << std::endl;


std::vector<int>::iterator it = std::find_if (p1.begin(), p1.end(), is_prime);
std::cout << "первое простое " << *it << '\n';

std::transform(p1.begin(), p1.end(), p1.begin(), [](int i) { return i*i; });
print_vector(p1, "заменили квадратами");

std::vector<int> p2(p1.size());
std::generate(p2.begin(), p2.end(), std::rand);
print_vector(p2, "последовательность П2");

int sum = std::accumulate(p2.begin(), p2.end(), 0);
std::cout << "сумма чисел в П2 " << sum << std::endl;

std::fill(p2.begin(), p2.begin() + 7, 1);
print_vector(p2, "заменили первые 4 числа на 1");


std::vector<int> p3(p1.size());
std::transform(p1.begin(), p1.end(), p2.begin(), p3.begin(), std::minus<>{});
print_vector(p3, "последовательность П3");

std::replace_if(p3.begin(), p3.end(), [](int i) { return i < 0; } , 0);
print_vector(p3, "заменили нулями отрицательные");

auto i = std::remove(p3.begin(), p3.end(), 0);
p3.erase(i, p3.end());
print_vector(p3, "убрали нули");

std::reverse(p3.begin(), p3.end());
print_vector(p3, "изменили порядок на обратный");

partial_sort( p3.begin(), p3.begin() + 3, p3.end(), std::greater<>{} );
print_vector(p3, "три наибольших", 3);


std::sort(p1.begin(), p1.end());
print_vector(p1, "отсортированная П1");
std::sort(p2.begin(), p2.end());
print_vector(p2, "отсортированная П2");

std::vector<int> p4(p1.size() + p2.size());
std::merge(p1.begin(), p1.end(), p2.begin(), p2.end(), p4.begin());
print_vector(p4, "последовательность П4");

auto itt = upper_bound(p4.begin(), p4.end(), 1 );
std::cout << "максимальная позиция для вставки единицы " << itt - p4.begin() << std::endl;

    return 0;
}

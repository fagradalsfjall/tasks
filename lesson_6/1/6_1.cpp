#include<iostream>
#include "6_1.hpp"

using namespace std;

task6_1::task6_1(int len_a, int len_v) {

a = new double[len_a];
this->len_a = len_a;
cout << "constructor" << a << endl;
v.resize(len_v);
}

task6_1::~task6_1() {
cout << "destructor" << a << endl;
delete[] a;

}

task6_1::task6_1(const task6_1& another) {  

        cout << "вызвали конструктор присваивания" << endl;      
        len_a = another.len_a;
        v = another.v;
        
        a = new double[len_a];
        for(int i = 0; i < len_a; ++i)
       { 
        a[i] = another.a[i];
       }

}

task6_1& task6_1::operator=(task6_1&& other) {

this->a=other.a;
other.a = 0;
len_a = other.len_a;
v = std::move(other.v);
cout << "вот он запущен оператор" << v.size() << endl;
return *this;
}

task6_1& task6_1::operator=(const task6_1& another)
    {

        cout << "вызвали оператор присваивания" << endl;
        len_a = another.len_a;

        v = another.v;
        delete[] a;
        a = new double[len_a];
        for(int i = 0; i < len_a; ++i)
       { 
        a[i] = another.a[i];
       }
        
        return *this;
    }



task6_1 gg() {

    task6_1 craft = task6_1(6, 4);

    return craft;

}

task6_1::task6_1(task6_1&& another)
{
    this->a=another.a;
    another.a = 0;
    len_a = another.len_a;
    v = std::move(another.v);
    cout << "вот он запущен" << v.size() << endl;
}

int main() {

    task6_1 craft = task6_1(6, 4);
    task6_1 craft_finish(craft);
    task6_1 sleep(100000000, 2);
    sleep = craft_finish;
printf("before\n");
    sleep = std::move(gg());
printf("ghfghfgh\n)");


    return 0;
}
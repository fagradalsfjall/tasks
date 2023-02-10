#include<iostream>
#include <vector>

using namespace std;
class task6_1 { 
double* a=0;
int len_a;
vector<int> v;

public:

task6_1(int len_a, int len_v);
task6_1(): task6_1(0, 0) {};

task6_1(const task6_1& another); 
task6_1(task6_1&& another); 

~task6_1();

task6_1& operator=(const task6_1& another);
task6_1& operator=(task6_1&& another);

void print();
};
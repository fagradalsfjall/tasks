#include <iostream>
using namespace std;

float addition (int f, float g){

    return (float)f + g;
    
}

float addition(float f, int g){
   
    return f + (float)g;
    
}



double average(int a, int b)

{
    return (a+b)/2.0;
}

double average(int a, int b, int c)

{
    return (a+b+c)/3.0;
}



int func(int d)

{
    return d+5;
}

double func(int d)

{
    return (double)(d+5.0);
}



int main()
{
    
    cout << addition(2, 6) << endl;
    cout << average(1, 2, 3) << endl;
    cout << average(2, 3) << endl;
    cout << func(10);

    return 0;
}

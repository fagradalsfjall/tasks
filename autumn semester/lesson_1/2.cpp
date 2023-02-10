#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    int x;
    int units_number;
    
    cout << "Какие единицы нужно перевести из СИ в СГС?" << endl << "1. Ньютон" << endl << "2. Джоуль" << endl << "3. Кулон" << endl;
    
    cin >> units_number;
    
    cout << "Введите значение ";
    cin >> x;
    
    if(units_number == 1)
    {
    
    cout << x << " Н = " << x*pow(10,5) << " дин" << endl;
    
    }
    
    if(units_number == 2)
    {
    
    cout << x << " Дж = " << x*pow(10,7) << " эрг" << endl;
    
    }
    
    if(units_number == 3)
    {
    
    cout << x << " Кл = " << x*3*pow(10,9) << " ед. СГСЭ" << endl;
    
    }

    return 0;
}
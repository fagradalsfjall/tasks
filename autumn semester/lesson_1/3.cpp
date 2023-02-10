#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, x1, x2;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    if((pow(b, 2) - 4*a*c) >= 0)
    {
        x1 = (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a);
        x2 = (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);
        
       if(x1 == x2)
        {
            cout << "x = " << x1;
        }
        
        else
        {
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
    else
    {
        cout << "No real solutions exist" << endl;
    }

    return 0;
}
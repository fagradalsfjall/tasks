#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    char ProductsName[25];
    int price;
    int temperature;
    char cashback[5];

    cout << "Product's name ";
    cin >> ProductsName;

    cout << "Product's price ";
    cin >> price;
    
    cout << "Is cash-back available for this product? (true/false) ";
    cin >> cashback;

    cout << "Maximum storing temperature ";
    cin >> temperature;

    cout << right << ProductsName << endl;
    cout.fill('.');
    cout.width(22);

    cout << left << "Price:" << right << uppercase << setw(8) << setfill('0') << hex << price <<endl;
    cout.fill('.');
    cout.width(22);

    cout << left << "Has cash-back:" << right << cashback << endl;
    cout.fill('.');
    cout.width(22);

    cout << left << "Max temperature:" << right << dec << showpos << temperature << endl;


    return 0;
}
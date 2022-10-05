#include <iostream>

using namespace std;

enum class Month {
    january, february, march, april, may, june, july, august, september, october, november, december

};

int days(Month month) {

    switch (month) {

        case Month::september:
            return 30;
        
        case Month::april:
            return 30;
            
        case Month::june:
            return 30;

        case Month::november:
            return 30;

        case Month::february:
            return 28;

        case Month::january:
            return 31;
        
        case Month::march:
            return 31;

        case Month::may:
            return 31;

        case Month::july:
            return 31;

        case Month::august:
            return 31;

        case Month::october:
            return 31;

        case Month::december:
            return 31;
    }

}

int main() {

    Month month = Month::october;
    cout << days(Month::march) << std::endl;
    cout << days(Month::september) << std::endl;

    
    return 0;
}
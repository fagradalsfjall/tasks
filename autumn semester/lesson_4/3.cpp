#include <iostream>

using namespace std;

struct date_and_time {
 
   unsigned int day: 5;
   unsigned int month: 4;
   unsigned int year: 14;
   unsigned int hours: 5;
   unsigned int minutes: 6;
   unsigned int seconds: 6;
   unsigned int seconds_2: 21;

};
struct date_and_time_reference {
    
   int day;
   int month;
   int year;
   int hours;
   int minutes;
   int seconds;

};


int main() {

    date_and_time now = {19, 9, 2022, 19, 17, 40};
    date_and_time_reference matan = {6, 10, 2022, 15, 30, 00};

    std::cout << "date_and_time " << sizeof(date_and_time) << std::endl;
    std::cout << "date_and_time_reference " << sizeof(date_and_time_reference) << std::endl;

    cout << "date_and_time "  << now.year << " " << now.month << " " << now.day << " " << now.hours << " " << now.minutes << " " << now.seconds << std::endl;    
    cout << "date_and_time_reference "  << matan.year << " " << matan.month << " " << matan.day << " " << matan.hours << " " << matan.minutes << " " << matan.seconds << std::endl;    

   return 0; 
}




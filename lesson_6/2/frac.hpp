#include<iostream>

using namespace std;
class fraction { 
    public:
signed int numerator;
unsigned int denominator;

friend ostream& operator<<(ostream& os, const fraction& frac);

public:

int get_numerator() const {
    return numerator;
};

unsigned int get_denominator() const {
    return denominator;
};


fraction(int numerator, int denominator);

float decimal () const;

friend const fraction operator*(const fraction& left, const fraction& right);
friend const fraction operator/(const fraction& left, const fraction& right);
friend fraction& operator*=(fraction& left, const fraction& right);
friend fraction& operator/=(fraction& left, const fraction& right);
friend const fraction operator+(const fraction& left, const fraction& right);
friend const fraction operator-(const fraction& left, const fraction& right);

void reduce();

};


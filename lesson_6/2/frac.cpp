#include<iostream>
#include <vector>
#include "frac.hpp"

using namespace std;

fraction::fraction(int numerator, int down):numerator(((down < 0) ? -1 : 1)* numerator), 
                                             denominator(abs(down)) {
    this->reduce();
}

ostream& operator<<(ostream& os, const fraction& frac)
{
    os <<' ' << frac.numerator << '/' << frac.denominator << " = " << frac.decimal();
    return os;
}

float fraction::decimal() const {
    return float(numerator)/denominator;

}

const fraction operator*(const fraction& left, const fraction& right) {
    return fraction(left.numerator*right.numerator, left.denominator*right.denominator);
}

const fraction operator/(const fraction& left, const fraction& right) {
    return fraction(left.numerator*right.denominator, left.denominator*right.numerator);
}

fraction& operator*=(fraction& left, const fraction& right) {
    left.numerator *= right.numerator;
    left.denominator *= right.denominator;
    left.reduce();
    return left;
}

fraction& operator/=(fraction& left, const fraction& right) {
    left.numerator *= right.denominator;
    left.denominator *= right.numerator;
    left.reduce();
    return left;
}

void prime_factors(int num) {
    vector<int> factors;
    int i;
    for (i = 2; i*i <= num; i++) {
        while (num % i == 0) {
            num /= i;
            factors.push_back(i);
        }

    }

    if (num != 1)
        factors.push_back(num);

}

int nod(int num1, int num2) {
    while (num2 > 0) {
        int a;
        a = num1%num2;
        num1 = num2;
        num2 = a;
    }
    return num1;
}

void fraction::reduce() {

    int nod_ = nod(abs(numerator), denominator);
    numerator/=nod_;
    denominator/=nod_;

}

const fraction operator+(const fraction& left, const fraction& right) {
    return fraction(left.numerator*right.denominator + right.numerator*left.denominator, left.denominator*right.denominator);
}

const fraction operator-(const fraction& left, const fraction& right) {
    return fraction(left.numerator*right.denominator - right.numerator*left.denominator, left.denominator*right.denominator);
}

int main() {

prime_factors(18);


fraction frac_first(-4, 13);
fraction frac_second(5, 41);
fraction frac_third(-5, 41);

cout << frac_first << endl ;

cout << ' ' << frac_first.decimal() << endl;

cout << "умножение " << frac_first*frac_second << endl;
cout << "деление " << frac_first/frac_second << endl;
cout << "еще деление " << frac_first/frac_third << endl;
cout << "сложение " << frac_second + frac_third << endl;
cout << "вычитание " << frac_first - frac_third << endl;

frac_first*=frac_second;
cout << ' ' << frac_first << endl;

frac_first/=frac_second;
cout << ' ' << frac_first << endl;

cout << nod(6, 14) << endl;
return 0;

}
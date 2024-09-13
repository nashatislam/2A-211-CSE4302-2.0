#include <iostream>
using namespace std;

struct fraction{
    int numerator;
    int denominator;

};


int main(void) {
    
    fraction first, second;
    char slash;

    cout << "Enter first fraction: ";
    cin >> first.numerator >> slash >> first.denominator;
    cout << "Enter second fraction: ";
    cin >> second.numerator >> slash >> second.denominator;

    cout << (first.numerator*second.denominator + first.denominator*second.numerator) << "/" << (first.denominator*second.denominator) << endl;
    
      
    return 0;
}
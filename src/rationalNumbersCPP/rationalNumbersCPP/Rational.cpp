//
//  Rational.cpp
//  rationalNumbersCPP
//


#include <iostream>
#include <iomanip>
#include "Rational.h"

using namespace std;

// By using the default parameter settings in Rational.h, this
// constructor also provides the default constructor Rational()

Rational::Rational (int num, int denom) {
    setRational(num, denom);   // Set numerator and denominator, reduce fraction, fix the sign
}   // End of Rational::Rational

// Helper function to fix zero denominator and fix the sign if the denominator is negative
// setRational uses the LCD function to reduce the fraction to the lowest common denominator

Rational Rational::setRational (int n, int d) {
    numerator = n;
    denominator = d;
    
    // If denominator == 0 then set it = 1
    if (denominator == 0)
        denominator = 1;
    
    // If denominator is negative, multiply num and denom by -1
    if (denominator < 0) {
        numerator = -numerator;       // Fix sign of numerator +/-
        denominator = -denominator;   // Denominator always +
    }   // End of negative denom
    
    // Call LCD()
    int lcd = LCD(numerator, denominator);
    
    if (denominator != 0) {
        numerator /= lcd;
        denominator /= lcd;
    }
    
    return *this;   // Return a pointer to the current object
    
}   // End of Rational::setRational

// Find the lowest common divisor using a recursive function
int Rational::LCD(int v1, int v2) {
    if (v2 == 0) return v1;
    else return LCD(v2, v1%v2);
}   // End of Ratinal::LCD

// Operator+ method
Rational Rational::operator+ (Rational right) {
    // Create local (temp) variables
    int newNumerator;
    int newDenominator;
    
    // Compute the result and save in local variables
    // Current object's numerator and denominator are not changed
    newNumerator = numerator*right.denominator + right.numerator*denominator;
    newDenominator = denominator*right.denominator;
    
    // Create new Rational object with the result and return it
    return Rational(newNumerator,newDenominator);
}   // End of Rational::operator+

// Operator+= method
Rational Rational::operator+= (Rational right) {
    // The current object is updated with the result of the +=
    numerator = numerator*right.denominator + right.numerator*denominator;
    denominator = denominator*right.denominator;
    
    // Fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}   // End of Rational::operator+=

// Operator- method does the same thing as the add method
Rational Rational::operator- (Rational right) {
    // Create local (temp) variables
    int newNumerator;
    int newDenominator;
    
    // Compute the result and save it in the local variables
    // The current object's numerator nd denominator are not changed
    newNumerator = numerator*right.denominator - right.numerator*denominator;
    newDenominator = denominator*right.denominator;
    
    // Creat new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}   // End of Rational::operator-

// Operator-= method
Rational Rational::operator-= (Rational right) {
    // The current object is updated with the result of the -=
    numerator = numerator*right.denominator - right.numerator*denominator;
    denominator = denominator*right.denominator;
    
    // Fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}   // End of Rational::operator-=

// Operator* method
Rational Rational::operator* (Rational right) {
    // Create new local (temp) variables
    int newNumerator;
    int newDenominator;
    
    // Compute the result and save to local variables
    // The current object's numerator and and denominator are not changed
    newNumerator = numerator*right.numerator;
    newDenominator = denominator*right.denominator;
    
    // Create new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}   // End of Operator*

// Operator*= method
Rational Rational::operator*= (Rational right) {
    // The current object is update with the results of the *=
    numerator = numerator*right.numerator;
    denominator = denominator*right.denominator;
    
    // Fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}   // End of Operator*=

// Operator/ method
Rational Rational::operator/ (Rational right) {
    // Create new local (temp) variables
    int newNumerator;
    int newDenominator;
    
    // Compute the result and save to local variables
    // The current object's numerator and and denominator are not changed
    newNumerator = numerator*right.denominator;
    newDenominator = denominator*right.numerator;
    
    // Create new Rational onject with the result and return it
    return Rational(newNumerator, newDenominator);
}   // End of Operator/

// Operator/= method
Rational Rational::operator/= (Rational right) {
    // The current object is updated with the result of the /=
    numerator = numerator*right.denominator;
    denominator = denominator*right.numerator;
    
    // Fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}   // End of Operator/=

// Operator== method
Rational Rational::operator== (Rational right) {
    // The object is compared for equality to the object on the right
    if (numerator == right.numerator && denominator == right.denominator)
        return true;
    else
        return false;
}   // End of Operator==

// Operator double() method
Rational::operator double() const {   // Converts rational into double
    return double(numerator)/double(denominator);
}   // End of Rational::operator double

// Display a rational number using the display() member method
void Rational::display() {
    cout << numerator << '/' << denominator;
}   // End of Rational::display

// Dispay a rational number using << and a friend function.
// Friend functions are not part of the class and their code must be
// declared outside of the class with no :: scope resolution operator.
// All functions arguments must have their class defined
ostream &operator<< (ostream &out, Rational const &r) {
    out << std::right << setw(2) << r.numerator << '/'
        << std::left << setw(2) << r.denominator;
    return out;   // This is to keep the stream flowing
}   // End of &operator<<

//
//  Rational.h
//  rationalNumbersCPP
//

#ifndef Rational_h   // If this isn't defined already
#define Rational_h   // Then define it

#include <iostream>
using namespace std;

// Start Rational
class Rational {
    /*
     *  Friend functions are actually declared outside of the scope of the
     *  class but have the right to acess public and private data and
     *  member function members that belong to the class. The friend
     *  function below gives the << operator for ostreams (including cout)
     *  the ability to output a Rational object by accessing  its member data.
     */
    
    friend ostream &operator<< (ostream &out, Rational const &r);

public:
    Rational (int num = 0, int denom = 1);   // Default constructor
    
    Rational add (const Rational right);
    Rational operator+  (const Rational right);   // +  addition operator
    Rational operator+= (const Rational right);   // += addition assignment operator
    Rational operator-  (const Rational right);   // -  subtraction operator
    Rational operator-= (const Rational right);   // -= subtraction assignment operator
    Rational operator*  (const Rational right);   // *  multiplication operator
    Rational operator*= (const Rational right);   // *= multiplication assignment operator
    Rational operator/  (const Rational right);   // /  divvision operator
    Rational operator/= (const Rational right);   // /= division assignment operator
    Rational operator== (const Rational right);   // == equality operator
    
    void display();
    operator double() const;   // Convert Rational to double
    
private:
    int numerator;
    int denominator;
    
    // Helper functions are private and not accessible by main
    int LCD (const int v1, const int v2);
    Rational setRational (const int n, const int d);
    
};   // End of Rational

#endif /* Rational_h */

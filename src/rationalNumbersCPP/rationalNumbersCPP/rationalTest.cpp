/*
 * RationalNumbersCPP Version#1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input
 * Output
 * 08 Apr 2022
 */

#include "Rational.h"   // Double quotes = find file in project folder
#include <iostream>     // angle brackets = find file in compiler folder
#include <iomanip>

using namespace std;

// Function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (Rational, Rational, Rational, const char *);

// Start main
int main(int argc, const char * argv[]) {
    
//   Class  Object
//     |      |
//     V      V
    Rational n1;
    Rational n2;
    Rational n3;
    
    // Title at the top of the display
    cout << "    n1     n2   n3\n  ==================\n" << endl;
    
    //------------ For each overloaded operator ------------------------
    //------------ initialize the values for n1, n2, and n3 ------------
    //------------ Test the operator -----------------------------------
    //------------ Display the results for n1, n2, and n3 --------------
    
    // Display values of n1, n2, and n3 before each test
    initializeNumbers (n1, n2, n3);
    displayNumbers (n1, n2, n3, "Values of n1, n2, and n3 before the start of each test");
    
    // Test operator+
    
    // Test operator+=
    
    // Test operator-
    
    // Test operator-=
    
    // Test operator*
    
    // Test operator*=
    
    // Test operator/
    
    // Test operator/=
    
    // Test operator==
    
    // Test operator double
    return 0;
}   // End main

// Initialize each of the variables before testing each Rational operator
void initializeNumbers(Rational &n1, Rational &n2, Rational &n3) {
    n1 = Rational ();       // 0 No arguments
    n2 = Rational (3, 4);   // 3/4
    n3 = Rational (2, 3);   // 2/3
}   // End of initializeNumbers

// Display each of the rational numbersusing the friend function <<
void displayNumbers (Rational n1, Rational n2, Rational n3, const char *msg) {
    cout << setw(4) << n1 << setw(4) << n2 << setw(4) << n3 << "\t" << msg << endl;
}   // End of displayNumbers

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
    cout << "==============================================================================" << endl;
    cout << " Test each overloaded operator" << endl;
    cout << "==============================================================================" << endl;
    cout << "   n1     n2    n3  \tDescription" << endl;
    cout << "==============================================================================" << endl;
    
    //------------ For each overloaded operator ------------------------
    //------------ initialize the values for n1, n2, and n3 ------------
    //------------ Test the operator -----------------------------------
    //------------ Display the results for n1, n2, and n3 --------------
    
    // Display values of n1, n2, and n3 before each test
    initializeNumbers (n1, n2, n3);
    displayNumbers (n1, n2, n3, "Values of n1, n2, and n3 before the start of each test");
    
    // Test operator+
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n1 = n2 + n3;                     // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers(n1, n2, n3, "n1 = n2 + n3 (n1 should be 17/12)");
    
    // Test operator+=
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n2 += n3;                         // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers(n1, n2, n3, "n2 += n3 (n2 should be 17/12)");
    
    // Test operator-
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n1 = n2 - n3;
    displayNumbers(n1, n2, n3, "n1 = n2 - n3 (n1 should be 1/12)");
    
    // Test operator-=
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n2 -= n3;
    displayNumbers(n1, n2, n3, "n2 -= n3 (n2 should be 1/12)");
    
    // Test operator*
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n1 = n2 * n3;
    displayNumbers(n1, n2, n3, "n1 = n2 * n3 (n1 should be 6/12)");
    
    // Test operator*=
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n2 *= n3;
    displayNumbers(n1, n2, n3, "n2 *= n3 (n2 should be 6/12)");
    
    // Test operator/
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n1 = n2 / n3;
    displayNumbers(n1, n2, n3, "n1 = n2 / n3 (n1 should be 9/8)");
    
    // Test operator/=
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    n2 /= n3;
    displayNumbers(n1, n2, n3, "n2 /= n3 (n2 should be 9/8)");
    cout << "==============================================================================" << endl;
    cout << " Test for Equality" << endl;
    cout << "==============================================================================" << endl;
    // Test operator==
    initializeNumbers (n1, n2, n3);   // Reset values EVERY test
    bool isEqual;                     // Variable for display
    isEqual = (n2 == n3);             // Should print false
    cout << std::boolalpha << " n2(" << n2 << ") is equal to n3(" << n3 << ") = " << isEqual << endl<< endl;
    cout << "==============================================================================" << endl;
    cout << " Test conversion from rational to double" << endl;
    cout << "==============================================================================" << endl;
    // Test operator double
    cout << "         n2 = " << n2 << endl;
    cout << " double(n2) = " << double(n2) << endl << endl;
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
    cout << " " << n1 << "  " << n2 << " " << n3 << "\t\t" << msg << endl;
}   // End of displayNumbers

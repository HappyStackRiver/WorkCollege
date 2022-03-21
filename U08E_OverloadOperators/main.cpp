#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Fraction.hpp"
#include "FractionTester.hpp"

string ToStr( bool val )
{
    return ( val ) ? "true" : "false";
}

int main()
{
    FractionTester tester;
    tester.RunTests();

    cout << endl << "FRACTION PROGRAM" << endl;

    Fraction a;
    cout << "Default fraction (a): " << a << endl;

    Fraction b( 3, 5 );
    cout << "Parameterized (b):    " << b << endl;

    Fraction c( a );
    cout << "Copy Constructor (c): " << c << endl;

    cout << endl << "Enter numerator and denominator, separated by a space: ";
    cin >> a;
    cout << "Value of a: " << c << endl;

    cout << endl;

    cout << "a \t\t b \t\t c" << endl;
    cout << string( 80, '-' );
    cout << a << "\t\t" << b << "\t\t" << c << endl;
    cout << left << setw( 16 ) << a.GetDecimal() << setw( 16 ) << b.GetDecimal() << setw( 16 ) << c.GetDecimal() << endl;

    float blah = c.GetDecimal();

    cout << endl << "Common denominator" << endl;
    cout << "a (original): " << a << ", a (common denom): " << a.CommonDenominatorize( b ) << endl;
    cout << "b (original): " << b << ", b (common denom): " << b.CommonDenominatorize( a ) << endl;

    cout << endl << "Math operations" << endl;
    cout << "a + b: " << a + b << endl;
    cout << "a - b: " << a - b << endl;
    cout << "a * b: " << a * b << endl;
    cout << "a / b: " << a / b << endl;

    cout << endl << "Relational operator: " << endl;
    cout << "a == b? " << ToStr( a == b ) << endl;
    cout << "a != b? " << ToStr( a != b ) << endl;
    cout << "a < b?  " << ToStr( a < b ) << endl;
    cout << "a > b?  " << ToStr( a > b ) << endl;
    cout << "a <= b? " << ToStr( a <= b ) << endl;
    cout << "a >= b? " << ToStr( a >= b ) << endl;

    return 0;
}


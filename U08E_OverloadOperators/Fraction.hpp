#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <ostream>
#include <istream>
using namespace std;

class Fraction
{
    public:
    Fraction();                         // Default constructor
    Fraction( int num, int denom );     // Parameterized constructor
    Fraction( const Fraction& other );  // Copy constructor

    void Set( int num, int denom );

    void SetNumerator( int num );
    int GetNumerator() const;

    void SetDenominator( int denom );
    int GetDenominator() const;

    float GetDecimal() const;

    Fraction CommonDenominatorize( const Fraction& other ) const;

    Fraction& operator=( const Fraction& rhs );

    friend Fraction operator+( const Fraction& left, const Fraction& right );
    friend Fraction operator-( const Fraction& left, const Fraction& right );
    friend Fraction operator*( const Fraction& left, const Fraction& right );
    friend Fraction operator/( const Fraction& left, const Fraction& right );

    friend bool operator==( const Fraction& left, const Fraction& right );
    friend bool operator!=( const Fraction& left, const Fraction& right );
    friend bool operator<( const Fraction& left, const Fraction& right );
    friend bool operator>( const Fraction& left, const Fraction& right );
    friend bool operator<=( const Fraction& left, const Fraction& right );
    friend bool operator>=( const Fraction& left, const Fraction& right );

    friend ostream& operator<<( ostream& out, const Fraction& item );
    friend istream& operator>>( istream& in, Fraction& item );

    private:
    int m_num;
    int m_denom;

    friend class FractionTester;
};

#endif

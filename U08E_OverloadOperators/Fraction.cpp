#include "Fraction.hpp"

Fraction::Fraction()
{
    m_num = 1;
    m_denom = 1;
}

Fraction::Fraction( int num, int denom )
{
    m_num = num;
    m_denom = denom;
}

Fraction::Fraction( const Fraction& other )
{
    m_num = other.m_num;
    m_denom = other.m_denom;
}

void Fraction::Set( int num, int denom )
{
    m_num = num;
    m_denom = denom;
}

void Fraction::SetNumerator( int num )
{
    m_num = num;
}

int Fraction::GetNumerator() const
{
    return m_num; // TODO: Replace me (placeholder)
}

void Fraction::SetDenominator( int denom )
{
    if (denom != 0)
    {
        m_denom = denom;
    }
}

int Fraction::GetDenominator() const
{
    return m_denom; // TODO: Replace me (placeholder)
}

float Fraction::GetDecimal() const
{
    return (float)m_num/(float)m_denom; // TODO: Replace me (placeholder)
}

Fraction Fraction::CommonDenominatorize( const Fraction& other ) const
{
    Fraction common(*this * Fraction(other.GetDenominator(), other.GetDenominator()));
    return common;
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    SetNumerator(rhs.GetNumerator());
    SetDenominator(rhs.GetDenominator());
    
        return *this; // TODO: Replace me (placeholder)
}

Fraction operator+( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    return Fraction(commonLeft.GetNumerator() + commonRight.GetNumerator(), commonLeft.GetDenominator()); // TODO: Replace me (placeholder)
}

Fraction operator-( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    return Fraction(commonLeft.GetNumerator() - commonRight.GetNumerator(), commonLeft.GetDenominator()); // TODO: Replace me (placeholder)
}

Fraction operator*( const Fraction& left, const Fraction& right )
{
    return Fraction(left.GetNumerator()*right.GetNumerator(), left.GetDenominator()*right.GetDenominator()); // TODO: Replace me (placeholder)
}

Fraction operator/( const Fraction& left, const Fraction& right )
{
    return Fraction(left.GetNumerator()*right.GetDenominator(), left.GetDenominator()*right.GetNumerator()); // TODO: Replace me (placeholder)
}

bool operator==( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    if (commonLeft.GetNumerator() == commonRight.GetNumerator() && commonLeft.GetDenominator() == commonRight.GetDenominator())
    {
        return true;
    }
    else
    {
        return false;
    } // TODO: Replace me (placeholder)
}

bool operator!=( const Fraction& left, const Fraction& right )
{
    return !(left == right); // TODO: Replace me (placeholder)
}

bool operator<( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    if (commonLeft.GetNumerator() < commonRight.GetNumerator())
    {
        return true;
    }
    else
    {
        return false;
    } // TODO: Replace me (placeholder)
}

bool operator>( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    if (commonLeft.GetNumerator() > commonRight.GetNumerator())
    {
        return true;
    }
    else
    {
        return false;
    } // TODO: Replace me (placeholder)
}

bool operator<=( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    if (commonLeft.GetNumerator() <= commonRight.GetNumerator())
    {
        return true;
    }
    else
    {
        return false;
    } // TODO: Replace me (placeholder)
}

bool operator>=( const Fraction& left, const Fraction& right )
{
    Fraction commonLeft = left.CommonDenominatorize(right);
    Fraction commonRight = right.CommonDenominatorize(left);

    if (commonLeft.GetNumerator() >= commonRight.GetNumerator())
    {
        return true;
    }
    else
    {
        return false;
    } // TODO: Replace me (placeholder)
}

ostream& operator<<( ostream& out, const Fraction& item)
{
    out << item.m_num << "/" << item.m_denom;
    return out;
}

istream& operator>>( istream& in, Fraction& item)
{
    in >> item.m_num >> item.m_denom;
    return in;
}

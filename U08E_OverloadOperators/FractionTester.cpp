#include "FractionTester.hpp"
#include "Fraction.hpp"

#include <iostream>
using namespace std;

void FractionTester::RunTests()
{
    Test_DefaultConstructor();
    Test_ParameterizedConstructor();
    Test_CopyConstructor();
    Test_Set();
    Test_SetNumerator();
    Test_GetNumerator();
    Test_SetDenominator();
    Test_GetDenominator();
    Test_GetDecimal();
    Test_CommonDenominatorize();
    Test_Assignment();
    Test_Add();
    Test_Subtract();
    Test_Multiply();
    Test_Divide();
    Test_IsEqual();
    Test_IsNotEqual();
    Test_IsLessThan();
    Test_IsGreaterThan();
    Test_IsLessThanOrEqualTo();
    Test_IsGreaterThanOrEqualTo();
}

void FractionTester::Test_DefaultConstructor()
{
    cout << endl << string( 80, '-' ) << "* Test_DefaultConstructor" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac;

        int expectedNum = 1;
        int expectedDenom = 1;

        int actNum = frac.m_num;
        int actDenom = frac.m_denom;

        if (actNum == expectedNum && actDenom == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

        cout << "\t input:               Fraction frac" << endl;
        cout << "\t expected output:     " << expectedNum << ", " << expectedDenom << endl;
        cout << "\t actual output:       " << actNum << ", " << actDenom << endl;

    } // test end
}

void FractionTester::Test_ParameterizedConstructor()
{
    cout << endl << string( 80, '-' ) << "* Test_ParameterizedConstructor" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;

        int inputNum = 2;
        int inputDenom = 3;

        Fraction frac(inputNum, inputDenom);

        int expectedNum = 2;
        int expectedDenom = 3;

        int actNum = frac.m_num;
        int actDenom = frac.m_denom;

        if (actNum == expectedNum && actDenom == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

        cout << "\t input:               Fraction frac" << endl;
        cout << "\t expected output:     " << expectedNum << ", " << expectedDenom << endl;
        cout << "\t actual output:       " << actNum << ", " << actDenom << endl;
    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;

        int inputNum = 6;
        int inputDenom = 4;

        Fraction frac(inputNum, inputDenom);

        int expectedNum = 6;
        int expectedDenom = 4;

        int actNum = frac.m_num;
        int actDenom = frac.m_denom;

        if (actNum == expectedNum && actDenom == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

        cout << "\t input:               Fraction frac" << endl;
        cout << "\t expected output:     " << expectedNum << ", " << expectedDenom << endl;
        cout << "\t actual output:       " << actNum << ", " << actDenom << endl;
    } // test end
}

void FractionTester::Test_CopyConstructor()
{
    cout << endl << string( 80, '-' ) << "* Test_ParameterizedConstructor" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1(3, 5);
        Fraction frac2(frac1);

        int expectNum = frac1.GetNumerator();
        int expectDenom = frac1.GetDenominator();

        int actNumer = frac2.GetNumerator();
        int actDenom = frac2.GetDenominator();

        if( actNumer == expectNum && actDenom == expectDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1(3, 5);
        Fraction frac2(frac1);

        int expectNum = frac1.GetNumerator();
        int expectDenom = frac1.GetDenominator();

        int actNumer = frac2.GetNumerator();
        int actDenom = frac2.GetDenominator();

        if (actNumer == expectNum && actDenom == expectDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end
}

void FractionTester::Test_Set()
{
    cout << endl << string( 80, '-' ) << "* Test_Set" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        
        Fraction frac;
        frac.Set(1, 2);

        int expectNum = 1;
        int expectDenom = 2;

        if (frac.GetNumerator() == expectNum && frac.GetDenominator() == expectDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end

    { // test begin
        cout << endl << "TEST 2" << endl;

        Fraction frac;
        frac.Set(2, 3);

        int expectNum = 2;
        int expectDenom = 3;

        if (frac.GetNumerator() == expectNum && frac.GetDenominator() == expectDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end
}

void FractionTester::Test_SetNumerator()
{
    cout << endl << string( 80, '-' ) << "* Test_SetNumerator" << endl;

    { // test begin
        cout << endl << "TEST 1: Use SetNumerator( 3 ), validate that m_num is 3... ";

        // Do the operation
        Fraction frac;
        int input = 3;
        frac.SetNumerator( input );

        int expectedOutput = 3;
        int actualOutput = frac.m_num;

        // Check if it worked
        if ( actualOutput == expectedOutput )
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

        cout << "\t input: " << input << endl;
        cout << "\t expected output: " << expectedOutput << endl;
        cout << "\t actual output: " << actualOutput << endl;
    } // test end
}

void FractionTester::Test_GetNumerator()
{
    cout << endl << string( 80, '-' ) << "* Test_GetNumerator" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        
        Fraction frac1;
        frac1.SetNumerator(10);

        int expectNum = 10;

        if (expectNum == frac1.GetNumerator())
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_SetDenominator()
{
    cout << endl << string( 80, '-' ) << "* Test_SetDenominator" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac;
        frac.SetDenominator(10);
        int expectDenom = 10;

        if (frac.GetDenominator() == expectDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end

    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac;
        frac.SetDenominator(10);
        int expectDenom = 10;
        frac.SetDenominator(0);

        if (frac.GetDenominator() == expectDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end

}

void FractionTester::Test_GetDenominator()
{
    cout << endl << string( 80, '-' ) << "* Test_GetDenominator" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;

        Fraction frac1;
        frac1.SetDenominator(10);

        int expectNum = 10;

        if (expectNum == frac1.GetDenominator())
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_GetDecimal()
{
    cout << endl << string( 80, '-' ) << "* Test_GetDecimal" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac;
        frac.m_num = 5;
        frac.m_denom = 10;

        float expectedDec = .5;

        if (frac.GetDecimal() == expectedDec)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac;
        frac.m_num = 8;
        frac.m_denom = 2;

        float expectedDec = 4;

        if (frac.GetDecimal() == expectedDec)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_CommonDenominatorize()
{
    cout << endl << string( 80, '-' ) << "* Test_CommonDenominatorize" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 2;
        frac2.m_denom = 3;

        Fraction result = frac1.CommonDenominatorize(frac2);

        int expectedNum = 3;
        int expectedDec = 6;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDec)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_Assignment()
{
    cout << endl << string( 80, '-' ) << "* Test_Assignment" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 5;
        frac1 = frac2;

        if (frac1.GetNumerator() == frac2.GetNumerator() && frac1.GetDenominator() == frac2.GetDenominator())
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_Add()
{
    cout << endl << string( 80, '-' ) << "* Test_Add" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 3;
        frac1.m_denom = 5;

        Fraction frac2;
        frac2.m_num = 7;
        frac2.m_denom = 11;

        int expectedNum = 68;
        int expectedDenom = 55;

        Fraction result = frac1 + frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 1;
        frac2.m_denom = 4;

        int expectedNum = 6;
        int expectedDenom = 8;

        Fraction result = frac1 + frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end
}

void FractionTester::Test_Subtract()
{
    cout << endl << string( 80, '-' ) << "* Test_Subtract" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 1;
        frac2.m_denom = 4;

        int expectedNum = 2;
        int expectedDenom = 8;

        Fraction result = frac1 - frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_Multiply()
{
    cout << endl << string( 80, '-' ) << "* Test_Multiply" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 1;
        frac2.m_denom = 4;

        int expectedNum = 1;
        int expectedDenom = 8;

        Fraction result = frac1 * frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 3;
        frac1.m_denom = 5;

        Fraction frac2;
        frac2.m_num = 7;
        frac2.m_denom = 11;

        int expectedNum = 21;
        int expectedDenom = 55;

        Fraction result = frac1 * frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end
}

void FractionTester::Test_Divide()
{
    cout << endl << string( 80, '-' ) << "* Test_Divide" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 1;
        frac2.m_denom = 4;

        int expectedNum = 2;
        int expectedDenom = 4;

        Fraction result = frac1 / frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 3;
        frac1.m_denom = 5;

        Fraction frac2;
        frac2.m_num = 7;
        frac2.m_denom = 11;

        int expectedNum = 33;
        int expectedDenom = 35;

        Fraction result = frac1 / frac2;

        if (result.GetNumerator() == expectedNum && result.GetDenominator() == expectedDenom)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // test end
}

void FractionTester::Test_IsEqual()
{
    cout << endl << string( 80, '-' ) << "* Test_IsEqual" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 6;
        frac2.m_denom = 12;


        if (frac1 == frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 12;


        if (frac1 == frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end

}

void FractionTester::Test_IsNotEqual()
{
    cout << endl << string( 80, '-' ) << "* Test_IsNotEqual" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 6;
        frac2.m_denom = 12;


        if (frac1 != frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 12;


        if (frac1 != frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_IsLessThan()
{
    cout << endl << string( 80, '-' ) << "* Test_IsLessThan" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 6;
        frac2.m_denom = 12;


        if (frac1 < frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 12;


        if (frac1 < frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_IsGreaterThan()
{
    cout << endl << string( 80, '-' ) << "* Test_IsGreaterThan" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 6;
        frac2.m_denom = 12;


        if (frac1 > frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 12;


        if (frac1 > frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_IsLessThanOrEqualTo()
{
    cout << endl << string( 80, '-' ) << "* Test_IsLessThanOrEqualTo" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 6;
        frac2.m_denom = 12;


        if (frac1 <= frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 12;


        if (frac1 <= frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

void FractionTester::Test_IsGreaterThanOrEqualTo()
{
    cout << endl << string( 80, '-' ) << "* Test_IsGreaterThanOrEqualTo" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 6;
        frac2.m_denom = 12;


        if (frac1 >= frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
    { // test begin
        cout << endl << "TEST 2" << endl;
        Fraction frac1;
        frac1.m_num = 1;
        frac1.m_denom = 2;

        Fraction frac2;
        frac2.m_num = 3;
        frac2.m_denom = 12;


        if (frac1 >= frac2)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }

    } // test end
}

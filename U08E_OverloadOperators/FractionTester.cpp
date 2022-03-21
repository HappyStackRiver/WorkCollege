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
    } // test end
}

void FractionTester::Test_ParameterizedConstructor()
{
    cout << endl << string( 80, '-' ) << "* Test_ParameterizedConstructor" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_CopyConstructor()
{
    cout << endl << string( 80, '-' ) << "* Test_ParameterizedConstructor" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_Set()
{
    cout << endl << string( 80, '-' ) << "* Test_Set" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
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
    } // test end
}

void FractionTester::Test_SetDenominator()
{
    cout << endl << string( 80, '-' ) << "* Test_SetDenominator" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_GetDenominator()
{
    cout << endl << string( 80, '-' ) << "* Test_GetDenominator" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_GetDecimal()
{
    cout << endl << string( 80, '-' ) << "* Test_GetDecimal" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_CommonDenominatorize()
{
    cout << endl << string( 80, '-' ) << "* Test_CommonDenominatorize" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_Assignment()
{
    cout << endl << string( 80, '-' ) << "* Test_Assignment" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_Add()
{
    cout << endl << string( 80, '-' ) << "* Test_Add" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_Subtract()
{
    cout << endl << string( 80, '-' ) << "* Test_Subtract" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_Multiply()
{
    cout << endl << string( 80, '-' ) << "* Test_Multiply" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_Divide()
{
    cout << endl << string( 80, '-' ) << "* Test_Divide" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_IsEqual()
{
    cout << endl << string( 80, '-' ) << "* Test_IsEqual" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_IsNotEqual()
{
    cout << endl << string( 80, '-' ) << "* Test_IsNotEqual" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_IsLessThan()
{
    cout << endl << string( 80, '-' ) << "* Test_IsLessThan" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_IsGreaterThan()
{
    cout << endl << string( 80, '-' ) << "* Test_IsGreaterThan" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_IsLessThanOrEqualTo()
{
    cout << endl << string( 80, '-' ) << "* Test_IsLessThanOrEqualTo" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

void FractionTester::Test_IsGreaterThanOrEqualTo()
{
    cout << endl << string( 80, '-' ) << "* Test_IsGreaterThanOrEqualTo" << endl;

    { // test begin
        cout << endl << "TEST 1" << endl;
    } // test end
}

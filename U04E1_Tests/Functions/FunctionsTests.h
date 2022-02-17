#ifndef _FUNCTIONS_TESTS_H
#define _FUNCTIONS_TESTS_H

#include <iostream>
using namespace std;

#include "Functions.h"
#include "../Utilities/Helper.hpp"

void Test_IsOverdrawn()
{
    cout << endl << string( 80, '-' ) << endl << "Test_IsOverdrawn" << endl;

    { // Begin test 1
        cout << endl << "Test 1:" << endl;
        float input_balance = 100;
        bool expectedOutput = false;
        bool actualOutput = IsOverdrawn( input_balance );

        cout << "- input_balance: " << input_balance << endl;
        cout << "- expectedOutput: " << expectedOutput << endl;
        cout << "- actualOutput: " << actualOutput << endl;
        cout << "Result: ";

        if ( actualOutput == expectedOutput )
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // End test 1

    { // Begin test 2
        cout << endl << "Test 2:" << endl;
        float input_balance = 0;
        bool expectedOutput = false;
        bool actualOutput = IsOverdrawn(input_balance);

        cout << "- input_balance: " << input_balance << endl;
        cout << "- expectedOutput: " << expectedOutput << endl;
        cout << "- actualOutput: " << actualOutput << endl;
        cout << "Result: ";

        if (actualOutput == expectedOutput)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // End test 2

    { // Begin test 3
        cout << endl << "Test 3:" << endl;
        float input_balance = -50;
        bool expectedOutput = true;
        bool actualOutput = IsOverdrawn(input_balance);

        cout << "- input_balance: " << input_balance << endl;
        cout << "- expectedOutput: " << expectedOutput << endl;
        cout << "- actualOutput: " << actualOutput << endl;
        cout << "Result: ";

        if (actualOutput == expectedOutput)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // End test 3
}

void Test_AdjustIngredients()
{
    cout << endl << string( 80, '-' ) << endl << "Test_AdjustIngredients" << endl;

}

void Test_IsInputValid()
{
    cout << endl << string(80, '-') << endl << "Test_IsInputValid" << endl;

    { // Begin test 1
        cout << endl << "Test 1:" << endl;
        int input_choice = 5;
        int input_min = 1;
        int input_max = 10;
        bool expectedOutput = true;
        bool actualOutput = IsInputValid( input_choice, input_min, input_max );

        cout << "- input_choice: " << input_choice << endl;
        cout << "- input_min: " << input_min << endl;
        cout << "- input_max: " << input_max << endl;
        cout << "- expectedOutput: " << expectedOutput << endl;
        cout << "- actualOutput: " << actualOutput << endl;
        cout << "Result: ";

        if (actualOutput == expectedOutput)
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // End test 1

}

void Test_Average()
{
    cout << endl << string( 80, '-' ) << endl << "Test_Average" << endl;

    { // Begin test 1
        cout << endl << "Test 1:" << endl;
        float input_arr[] = { 0.5, 0.25, 0.25, 1.5 };
        int input_arraySize = 4;
        float expectedOutput = 2.5;
        float actualOutput = Average( input_arr, input_arraySize );

        cout << "- input_arr: " << Helper::ArrayToString( input_arr, input_arraySize ) << endl;
        cout << "- input_arraySize: " << input_arraySize << endl;
        cout << "- expectedOutput: " << expectedOutput << endl;
        cout << "- actualOutput: " << actualOutput << endl;
        cout << "Result: ";

        if ( actualOutput == expectedOutput )
        {
            cout << "PASS" << endl;
        }
        else
        {
            cout << "FAIL" << endl;
        }
    } // End test 1

}

void Test_Summation()
{
    cout << endl << string( 80, '-' ) << endl << "Test_Summation" << endl;

}

#endif

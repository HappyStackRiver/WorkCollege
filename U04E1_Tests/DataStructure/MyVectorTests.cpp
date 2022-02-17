#include "MyVectorTests.h"

#include <iostream>
using namespace std;

void MyVectorTester::Test_Constructor()
{
    cout << endl << string( 80, '-' ) << endl << "Test_Constructor" << endl;
    
    { // Begin test 1
        cout << endl << "Test 1: Check that items get initialized properly after constructor" << endl;

        int* expected_m_array = nullptr;
        int expected_m_arraySize = 0;
        int expected_m_itemCount = 0;

        MyVector<int> mv;

        int* actual_m_array = mv.m_array;
        int actual_m_arraySize = mv.m_arraySize;
        int actual_m_itemCount = mv.m_itemCount;

        cout << "- expected_m_array:        " << expected_m_array << endl;
        cout << "- actual_m_array:          " << actual_m_array << endl;

        cout << "- expected_m_arraySize:    " << expected_m_arraySize << endl;
        cout << "- actual_m_arraySize:      " << actual_m_arraySize << endl;

        cout << "- expected_m_itemCount:    " << expected_m_itemCount << endl;
        cout << "- actual_m_itemCount:      " << actual_m_itemCount << endl;
        cout << "Result: ";

        if (expected_m_array != actual_m_array)
        {
            cout << "FAIL" << endl;
        }
        else if (expected_m_arraySize != actual_m_arraySize)
        {
            cout << "FAIL" << endl;
        }
        else if (expected_m_itemCount != actual_m_itemCount)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    } // End test 1
}

void MyVectorTester::Test_AllocateMemory()
{
    cout << endl << string( 80, '-' ) << endl << "Test_AllocateMemory" << endl;
    { // Begin test 1
        cout << endl << "Test 1: Check that items are initialized after AllocateMemory" << endl;

        int input_size = 5;

        int expected_m_arraySize = 5;
        int expected_m_itemCount = 0;
        // Expecting m_array to point NOT nullptr.

        MyVector<int> mv;
        mv.AllocateMemory(input_size);

        int actual_m_arraySize = mv.m_arraySize;
        int actual_m_itemCount = mv.m_itemCount;

        cout << "- input_size:              " << input_size << endl;

        cout << "- expected_m_arraySize:    " << expected_m_arraySize << endl;
        cout << "- actual_m_arraySize:      " << actual_m_arraySize << endl;

        cout << "- expected_m_itemCount:    " << expected_m_itemCount << endl;
        cout << "- actual_m_itemCount:      " << actual_m_itemCount << endl;

        cout << "- expected m_array:    NOT NULL" << endl;
        cout << "- actual m_array:      " << mv.m_array << endl;

        cout << "Result: ";

        if (actual_m_arraySize != expected_m_arraySize)
        {
            cout << "FAIL" << endl;
        }
        else if (actual_m_itemCount != expected_m_itemCount)
        {
            cout << "FAIL" << endl;
        }
        else if (mv.m_array == nullptr)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    { // Begin test 2
        cout << endl << "Test 2: Check that exception is thrown when m_array is already pointing to an address" << endl;

        bool expected_exception = true;
        bool actual_exception = false;

        MyVector<int> mv;
        int bob[50];
        mv.m_array = bob;

        try
        {
            mv.AllocateMemory(10);
        }
        catch (...)
        {
            actual_exception = true;
        }

        cout << "- expected_exception:    " << expected_exception << endl;
        cout << "- actual_exception:      " << actual_exception << endl;

        cout << "Result: ";

        if (expected_exception != actual_exception)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }

        // fix the array before deallocation :)
        mv.m_array = nullptr;
    } // End test 2
}

void MyVectorTester::Test_DeallocateMemory()
{
    cout << endl << string( 80, '-' ) << endl << "Test_DeallocateMemory" << endl;
    int* expected_m_array = nullptr;
    int expected_m_arraySize = 0;
    int expected_m_itemCount = 0;
    MyVector<int> mv;

    int actual_m_arraySize = mv.m_arraySize;
    int actual_m_itemCount = mv.m_itemCount;

    cout << "- expected_m_arraySize:    " << expected_m_arraySize << endl;
    cout << "- actual_m_arraySize:      " << actual_m_arraySize << endl;

    cout << "- expected_m_itemCount:    " << expected_m_itemCount << endl;
    cout << "- actual_m_itemCount:      " << actual_m_itemCount << endl;

    cout << "- expected m_array:    0" << endl;
    cout << "- actual m_array:      " << mv.m_array << endl;
    cout << "Result: ";

    if (expected_m_array != 0)
    {
        cout << "FAIL" << endl;
    }
    else if (expected_m_arraySize != actual_m_arraySize)
    {
        cout << "FAIL" << endl;
    }
    else if (expected_m_itemCount != actual_m_itemCount)
    {
        cout << "FAIL" << endl;
    }
    else
    {
        cout << "PASS" << endl;
    }
}

void MyVectorTester::Test_PushBack()
{
    cout << endl << string( 80, '-' ) << endl << "Test_PushBack" << endl;
    { // Begin test 1
        cout << endl << "Test 1: Check that items are inserted into correct positions" << endl;
        MyVector<int> mv;
        mv.PushBack(0);
        mv.PushBack(10);
        mv.PushBack(20);

        int expected_pos0 = 0;
        int expected_pos1 = 10;
        int expected_pos2 = 20;

        int actual_pos0 = mv.m_array[0];
        int actual_pos1 = mv.m_array[1];
        int actual_pos2 = mv.m_array[2];

        cout << "- expected_pos0:    " << expected_pos0 << endl;
        cout << "- actual_pos0:      " << actual_pos0 << endl;

        cout << "- expected_pos1:    " << expected_pos1 << endl;
        cout << "- actual_pos1:      " << actual_pos1 << endl;

        cout << "- expected_pos2:    " << expected_pos2 << endl;
        cout << "- actual_pos2:      " << actual_pos2 << endl;
        cout << "Result: ";

        if (actual_pos0 != expected_pos0)
        {
            cout << "FAIL" << endl;
        }
        else if (actual_pos1 != expected_pos1)
        {
            cout << "FAIL" << endl;
        }
        else if (actual_pos2 != expected_pos2)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    } // End test 1

}

void MyVectorTester::Test_PopAt()
{
    cout << endl << string( 80, '-' ) << endl << "Test_PopAt" << endl;
    { // Begin test 1
        cout << endl << "Test 1: Check that item is successfully removed" << endl;
        MyVector<int> mv;
        mv.PushBack(0);
        mv.PushBack(10);
        mv.PushBack(20);
        mv.PopAt(1);

        int expected_pos0 = 0;
        int expected_pos1 = 20;

        int actual_pos0 = mv.m_array[0];
        int actual_pos1 = mv.m_array[1];

        cout << "- expected_pos0:    " << expected_pos0 << endl;
        cout << "- actual_pos0:      " << actual_pos0 << endl;

        cout << "- expected_pos1:    " << expected_pos1 << endl;
        cout << "- actual_pos1:      " << actual_pos1 << endl;
        cout << "Result: ";

        if (actual_pos0 != expected_pos0)
        {
            cout << "FAIL" << endl;
        }
        else if (actual_pos1 != expected_pos1)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    { // Begin test 2
        cout << endl << "Test 2: Check that exception is thrown when m_array is already pointing to an address" << endl;

        bool expected_exception = true;
        bool actual_exception = false;

        MyVector<int> mv;
        int bob[50];
        mv.m_array = bob;

        try
        {
            mv.PopAt(100);
        }
        catch (...)
        {
            actual_exception = true;
        }

        cout << "- expected_exception:    " << expected_exception << endl;
        cout << "- actual_exception:      " << actual_exception << endl;

        cout << "Result: ";

        if (expected_exception != actual_exception)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }

        // fix the array before deallocation :)
        mv.m_array = nullptr;
    }
}

void MyVectorTester::Test_GetAt()
{
    cout << endl << string( 80, '-' ) << endl << "Test_GetAt" << endl;
    { // Begin test 1
        cout << endl << "Test 1: Check that item is successfully removed" << endl;
        MyVector<int> mv;
        mv.PushBack(0);
        mv.PushBack(10);
        mv.PushBack(20);
        mv.GetAt(1);

        int expected_getAt = 0;
        int expected_getAt1 = 10;

        int actual_getAt = mv.m_array[0];
        int actual_getAt1 = mv.m_array[1];

        cout << "- expected_getAt:    " << expected_getAt << endl;
        cout << "- actual_getAt:      " << actual_getAt << endl;

        cout << "- expected_getAt:    " << expected_getAt1 << endl;
        cout << "- actual_getAt:      " << actual_getAt1 << endl;
        cout << "Result: ";

        if (actual_getAt != expected_getAt)
        {
            cout << "FAIL" << endl;
        }
        else if (actual_getAt1 != expected_getAt1)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    { // Begin test 2
        cout << endl << "Test 2: Check that exception is thrown when m_array is already pointing to an address" << endl;

        bool expected_exception = true;
        bool actual_exception = false;

        MyVector<int> mv;
        int bob[50];
        mv.m_array = bob;

        try
        {
            mv.GetAt(100);
        }
        catch (...)
        {
            actual_exception = true;
        }

        cout << "- expected_exception:    " << expected_exception << endl;
        cout << "- actual_exception:      " << actual_exception << endl;

        cout << "Result: ";

        if (expected_exception != actual_exception)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }

        // fix the array before deallocation :)
        mv.m_array = nullptr;
    }
}

void MyVectorTester::Test_Size()
{
    cout << endl << string( 80, '-' ) << endl << "Test_Size" << endl;
    { // Begin test 1
        cout << endl << "Test 1: Check that item is successfully removed" << endl;
        MyVector<int> mv;
        mv.PushBack(0);
        mv.PushBack(10);
        mv.PushBack(20);
        mv.Size();

        int expected_size = 3;

        int actual_size = mv.Size();


        cout << "- expected_size:    " << expected_size << endl;
        cout << "- actual_size:      " << actual_size << endl;


        cout << "Result: ";

        if (actual_size != expected_size)
        {
            cout << "FAIL" << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }

    
}

void MyVectorTester::Test_Resize()
{
    cout << endl << string( 80, '-' ) << endl << "Test_Resize" << endl;
    MyVector<int> mv;
    mv.AllocateMemory( 2 );
    mv.PushBack( 1 );
    mv.PushBack( 2 );
    mv.PushBack( 3 );

    int expected_pos0 = 1;
    int expected_pos1 = 2;
    int expected_pos2 = 3;

    int actual_pos0 = mv.m_array[0];
    int actual_pos1 = mv.m_array[1];
    int actual_pos2 = mv.m_array[2];

    cout << "- expected_pos0:    " << expected_pos0 << endl;
    cout << "- actual_pos0:      " << actual_pos0 << endl;

    cout << "- expected_pos1:    " << expected_pos1 << endl;
    cout << "- actual_pos1:      " << actual_pos1 << endl;

    cout << "- expected_pos2:    " << expected_pos1 << endl;
    cout << "- actual_pos2:      " << actual_pos1 << endl;
    
    
    cout << "Result: ";

    if (actual_pos0 != expected_pos0)
    {
        cout << "FAIL" << endl;
    }
    else
    {
        cout << "PASS" << endl;
    }
}

void MyVectorTester::Test_IsFull()
{
    cout << endl << string( 80, '-' ) << endl << "Test_IsFull" << endl;
    MyVector<int> mv;
    mv.m_arraySize = 5;
    mv.m_itemCount = 2;

    if (mv.m_arraySize != mv.m_itemCount)
    {
        cout << "FAIL";
    }
    else
    {
        cout << "PASS";
    }


}

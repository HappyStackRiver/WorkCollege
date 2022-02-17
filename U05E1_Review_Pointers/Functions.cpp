#include "Functions.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
using namespace std;


void Program1_ExploringAddresses()
{
    /*
    ABOUT MEMORY ADDRESSES
    The & symbol, when placed before a variable name, is known as the "address-of operator".
    It is used to get the address of that variable in memory.

    Pointer variables store addresses in memory, and so they are used to point to
    different variables' addresses at different times in a program.

    When a pointer is NOT in use, it is best practice to point it to "nullptr" to avoid memory errors.
    */

    cout << endl << "EXPLORING ADDRESSES" << endl << string( 80, '-' ) << endl;

    int int1 = 25, int2 = 50, int3 = 75;        // Integer variables.
    int * ptrInt = nullptr;                     // Pointer variable, initialized to nullptr for safety.
    bool done = false;

    cout << "OPTIONS" << endl
        << "1. Point ptrInt to int1's address" << endl
        << "2. Point ptrInt to int2's address" << endl
        << "3. Point ptrInt to int3's address" << endl
        << "4. Point ptrInt to nullptr" << endl
        << "0. Quit subprogram" << endl;

    while ( !done )
    {
        cout << endl;
        cout << left << setw( 20 ) << "Variables: "     << setw( 20 ) << "int1"               << setw( 20 ) << "int2"            << setw( 20 ) << "int3" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << left << setw( 20 ) << "Values:    " << setw( 20 ) << int1            << setw( 20 ) << int2         << setw( 20 ) << int3 << endl;
        cout << left << setw( 20 ) << "Addresses: " << setw( 20 ) << int1            << setw( 20 ) << int2         << setw( 20 ) << int3 << endl;

        cout << endl << "ptrInt is pointing to address: " << ptrInt << endl << endl;

        int choice;
        cout << ">> ";
        cin >> choice;
        cout << "You entered: " << choice << endl;

        // Students implement this part
        // If they chose 0, quit the subprogram (done = true).
        // For 1, set the pointer ptrInt to point to the address of int1.
        // For 2, point to int2.
        // For 3, point to int3.
        // For 4, point to nullptr.

        if ( choice == 0 ) { done = true; }

        cout << endl << endl;
    }
}

void Program2_DereferencingPointers()
{
    /*
    ABOUT DEREFERENCING POINTERS
    The * symbol, when written before a pointer variable's name, is known as the "dereference operator".

    When a pointer is pointing to some address in memory we can look at the
    address it's pointing to, but we can also look INTO that address to read and write
    data at that address. When we do this, it's called "dereferencing" the pointer.
    */

    cout << endl << "DEREFERENCING POINTERS" << string( 80, '-' ) << endl;

    string student1 = "Anuraj S.", student2 = "Rahaf A.", student3 = "Alexa S.";    // String variables.
    string * ptrStudent = nullptr;                                                  // a string pointer, initialized to nullptr.
    bool done = false;

    cout << "OPTIONS" << endl
        << "1. Point ptrStudent to student1's address" << endl
        << "2. Point ptrStudent to student2's address" << endl
        << "3. Point ptrStudent to student3's address" << endl
        << "4. Point ptrStudent to nullptr" << endl
        << "5. Read from ptrStudent" << endl
        << "6. Write to ptrStudent" << endl
        << "0. Quit subprogram" << endl;

    while ( !done )
    {
        cout << endl << "Students:" << endl;
        cout << left << setw( 26 ) << "student1"                << setw( 26 ) << "student2"            << setw( 26 ) << "student3" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << left << setw( 26 ) << student1                  << setw( 26 ) << student2               << setw( 26 ) << student3 << endl;
        cout << left << setw( 26 ) << &student1                 << setw( 26 ) << &student2              << setw( 26 ) << &student3 << endl;

        cout << endl << "ptrStudent is pointing to address: " << ptrStudent << endl << endl;

        int choice;
        cout << ">> ";
        cin >> choice;
        cout << "You entered: " << choice << endl;

        // Students implement this part
        // For option 0, quit the subprogram (done = true).
        // For option 1, set the pointer ptrStudent to point to the address of student1.
        // For option 2, point to student2.
        // For option 3, point to student3.
        // For option 4, point to nullptr.
        // For option 5:
        //  * If ptrStudent is pointing to nullptr, display an error message.
        //  * otherwise, display the address that ptrStudent is pointing to and the value that address is storing.
        // For option 6:
        //  * If ptrStudent is pointing to nullptr, display an error message.
        //  * otherwise, ask the user to enter a new name for the student and store it via dereferencing ptrStudent.

        if ( choice == 0 ) { done = true; }

        cout << endl << endl;
    }
}

void Program3_PointersAndClasses()
{
    /*
    ABOUT POINTERS AND CLASSES:
    The -> operator is a special operator that does two things: It dereferences a class AND accesses a member of the class.
    If we have a pointer to a class, we can access a member like this:
        classPtr->Display();
    Or we could do it the long way:
        (*classPtr).Display();
    */

    cout << endl << "CLASSES AND POINTERS" << string( 80, '-' ) << endl;

    Employee
        employee1( "Rai S.",    13.45 ),
        employee2( "Rose M.",   15.50 ),
        employee3( "Andre N.",  15.15 );
    Employee * ptrEmployee = nullptr;
    bool done = false;

    cout << "OPTIONS" << endl
        << "1. Point ptrEmployee to employee1's address" << endl
        << "2. Point ptrEmployee to employee2's address" << endl
        << "3. Point ptrEmployee to employee3's address" << endl
        << "4. Point ptrEmployee to nullptr" << endl
        << "5. Read from ptrEmployee" << endl
        << "6. Write to ptrEmployee" << endl
        << "0. Quit subprogram" << endl;

    while ( !done )
    {
        cout << endl << "Employees:" << endl;

        cout << left << setw( 26 ) << "employee1"               << setw( 26 ) << "employee2"            << setw( 26 ) << "employee3" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << left << setw( 26 ) << employee1.name            << setw( 26 ) << employee2.name         << setw( 26 ) << employee3.name << endl;
        cout << left << setw( 26 ) << employee1.payPerHour      << setw( 26 ) << employee2.payPerHour   << setw( 26 ) << employee3.payPerHour << endl;
        cout << left << setw( 26 ) << &employee1.payPerHour     << setw( 26 ) << &employee2             << setw( 26 ) << &employee3 << endl;

        cout << endl << "ptrEmployee is pointing to address: " << ptrEmployee << endl << endl;

        int choice;
        cout << ">> ";
        cin >> choice;
        cout << "You entered: " << choice << endl;

        // Students implement this part
        // For 0, quit the subprogram (done = true).
        // For 1, set ptrEmployee to point to the address of employee1.
        // For 2, point to employee2.
        // For 3, point to employee3.
        // For 4, point to nullptr.
        // For 5, do the following:
        //  * If ptrEmployee is pointing to nullptr, display an error message.
        //  * otherwise, call the Display() function of ptrEmployee.
        // For 6, do the following:
        //  * If ptrEmployee is pointing to nullptr, display an error message.
        //  * otherwise, ask if they want to (1) update the name, or (2) update the pay per hour.
        //  * if their choice was 1:
        //      * Ask them to enter a new employee name. Store it at ptrEmployee->name.
        //  * if their choice was 2:
        //      * Ask them to enter a new wage. Store it at ptrEmployee->payPerHour.

        if ( choice == 0 ) { done = true; }

        cout << endl << endl;
    }
}

void Program4_DynamicVariables()
{
    /*
    ABOUT DYNAMIC VARIABLES:
    We can dynamically allocate space for a single variable on HEAP MEMORY by using pointers.
    This is usually useful for writing certain DATA STRUCTURES, liked Linked Lists and Trees.

    Remember that when we manually ALLOCATE space for a variable (using the "new" keyword)
    we need to also manually DEALLOCATE space before the pointer loses scope (using the "delete" keyword).
    */

    cout << endl << "DYNAMICALLY ALLOCATING MEMORY FOR VARIABLES" << endl << string( 80, '-' ) << endl;

    cout << "CREATE NODES AND LINK THEM:" << endl;
    cout << "* Create firstNode (A)" << endl;
    // Allocate space for one Node object via a pointer. Set its data value to "A".

    cout << "* Create firstNode->ptrNext (B)" << endl;
    // Allocate space for another Node object via the first node's ->ptrNext pointer. Set its data value to "B".

    cout << "* Create firstNode->ptrNext->ptrNext (C)" << endl;
    // Allocate space for another Node object via the first node's ->ptrNext->ptrNext pointer. Set its data value to "C.

    cout << endl << "ITERATE THROUGH NODES:" << endl;
    // Create a pointer named ptrCurrent to point to the existing firstNode.
    // While ptrCurrent is not equal to nullptr, display the data of the current item (ptrCurrent->data),
    // and then traverse forwards (ptrCurrent = ptrCurrent->ptrNext).

    cout << endl << "FREE MEMORY:" << endl;
    cout << "* Delete firstNode->ptrNext->ptrNext" << endl;
    // Free memory of the node at firstNode->ptrNext->ptrNext and afterward set it to point to nullptr

    cout << "* Delete firstNode->ptrNext" << endl;
    // Free memory of the node at firstNode->ptrNext and afterward set it to point to nullptr

    cout << "* Delete firstNode" << endl;
    // Free memory of the node at firstNode and afterward set it to point to nullptr

    cout << endl << "Press ENTER to continue." << endl;
    string a;
    cin.ignore();
    getline( cin, a );
}

void Program5_DynamicArrays()
{
    /*
    ABOUT DYNAMIC ARRAYS:
    Similarly, we can dynamically allocate space for an array on HEAP MEMORY by using pointers.
    This is how we create arrays that can be resized without knowing its size at compile-time.

    Remember that when we manually ALLOCATE space for a variable (using the "new []" keyword)
    we need to also manually DEALLOCATE space before the pointer loses scope (using the "delete []" keyword).
    */

    cout << endl << "DYNAMICALLY ALLOCATING MEMORY FOR ARRAYS" << endl << string( 80, '-' ) << endl;

    int arraySize = 3;
    int itemCount = 0;
    // Allocate space for a dynamic array named "arr", of size "arraySize", which stores strings.

    cin.ignore();

    bool done = false;
    while ( !done )
    {
        cout << endl << string( 40, '-' ) << endl;

        // Display array information
        cout << "ARRAY SIZE: " << arraySize << ", ITEM COUNT: " << itemCount << endl;
        cout << "ARRAY CONTENTS:" << endl;
        for ( int i = 0; i < itemCount; i++ )
        {
            // TODO
        }
        cout << endl << endl;

        cout << "Enter a new item to add, or QUIT to quit: ";
        string text;
        getline( cin, text );

        if ( text == "QUIT" )
        {
            done = true;
        }
        else
        {
            // Add a new item to the array, increment itemCount
            // TODO
        }

        // Check if full, resize if so
        if ( itemCount == arraySize )
        {
            cout << "* NEED TO RESIZE" << endl;
            int newSize = arraySize + 3;
            // TODO

            cout << "* COPY DATA FROM OLD ARRAY TO NEW ARRAY" << endl;
            for ( int i = 0; i < arraySize; i++ )
            {
            // TODO
            }

            cout << "* FREE THE OLD MEMORY" << endl;
            // TODO

            cout << "* UPDATE POINTER TO NEW MEMORY" << endl;
            // TODO

            cout << "* UPDATE ARRAYSIZE" << endl;
            // TODO
        }
    }

    cout << endl << "FREE REMAINING MEMORY BEFORE LEAVING!!" << endl;
    // Deallocate memory before the pointer goes out of scope
}

void Program6_UniquePointers()
{
    /*
    ABOUT UNIQUE POINTERS
    Smart pointers keep track of their memory management and will automatically
    deallocate any allocated memory as part of its destruction.

    A UNIQUE POINTER is a solo owner of a space of memory. No other objects are
    allowed to manage that memory block, because the unique pointer will deallocate
    that memory when IT goes out of scope.
    */
    cout << endl << "UNIQUE POINTERS" << endl << string( 80, '-' ) << endl;

    // Copy/paste the Program5_DynamicArrays code in here, we are going to modify it.
}

void Program7_SharedPointers()
{
    /*
    ABOUT SHARED POINTERS
    Shared pointers are another type of smart pointer. With a shared pointer,
    different objects can keep track of the same block of memory, and that
    memory is only dynamically deallocated when ALL shared pointers pointing
    to it go out of scope.
    */
    cout << endl << "SHARED POINTERS" << endl << string( 80, '-' ) << endl;

    // Copy/paste the Program4_DynamicVariables code in here, we are going to modify it.
}

void Program8_TextAdventureMap()
{
    cout << endl << "TEXT ADVENTURE MAP" << endl << string( 80, '-' ) << endl;

    // Create a set of shared_ptrs to Zone objects

    // Point Zones to their neighbors

    // Create a currentLocation pointer and point it to one zone

    bool done = false;
    while ( !done )
    {
        cout << endl << string( 40, '-' ) << endl;
        cout << "CURRENT LOCATION: ";
        // Display current location name

        // Display which directions we can move to

        cout << endl << "Enter N/S/E/W to move, or QUIT to quit: ";
        string choice;
        cin >> choice;

        if ( choice == "QUIT" )
        {
            done = true;
        }

        // Let user move north, south, east, or west


        else
        {
            cout << "CANNOT MOVE THAT DIRECTION!!" << endl;
        }
    }

    cout << endl << "BYE!" << endl;
}









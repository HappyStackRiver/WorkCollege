#include <iostream>
#include <iomanip>
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

    cout << "EXPLORING ADDRESSES" << endl << string( 80, '#' ) << endl;

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

        // Students implement this part
        int choice;
        cout << ">> ";
        cin >> choice;
        cout << "You entered: " << choice << endl;

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
    cout << "DEREFERENCING POINTERS" << string( 80, '#' ) << endl;

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

        // Students implement this part
        int choice;
        cout << ">> ";
        cin >> choice;
        cout << "You entered: " << choice << endl;

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

struct Employee
{
    string name;
    float payPerHour;

    Employee( string n, float pph )
    {
        name = n;
        payPerHour = pph;
    }

    void Display()
    {
        cout << name << ", $" << payPerHour << "/hr" << endl;
    }
};

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
    cout << "CLASSES AND POINTERS" << string( 80, '#' ) << endl;

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

        // Students implement this part
        int choice;
        cout << ">> ";
        cin >> choice;
        cout << "You entered: " << choice << endl;

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

int main()
{
  bool done = false;
  while ( !done )
  {
    cout << "MAIN MENU" << endl << string( 80, '#' ) << endl;
    cout << "1. Exploring addresses" << endl;
    cout << "2. Dereferencing pointers" << endl;
    cout << "3. Pointers and classes" << endl;
    cout << endl;
    cout << "0. Exit" << endl;
    cout << endl;

    cout << ">> ";
    int choice;
    cin >> choice;

    if      ( choice == 0 ) { done = true; }
    else if ( choice == 1 ) { Program1_ExploringAddresses(); }
    else if ( choice == 2 ) { Program2_DereferencingPointers(); }
    else if ( choice == 3 ) { Program3_PointersAndClasses(); }
  }
}

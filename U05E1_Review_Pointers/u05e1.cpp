#include <iostream>
using namespace std;

#include "Functions.h"

int main()
{
  bool done = false;
  while ( !done )
  {
    cout << endl << endl << string( 80, '#' ) << endl << "MAIN MENU" << endl << string( 80, '#' ) << endl;
    cout << "1. Program1_ExploringAddresses" << endl;
    cout << "2. Program2_DereferencingPointers" << endl;
    cout << "3. Program3_PointersAndClasses" << endl;
    cout << "4. Program4_DynamicVariables" << endl;
    cout << "5. Program5_DynamicArrays" << endl;
    cout << "6. Program6_UniquePointers" << endl;
    cout << "7. Program7_SharedPointers" << endl;
    cout << "8. Program8_TextAdventureMap" << endl;
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
    else if ( choice == 4 ) { Program4_DynamicVariables(); }
    else if ( choice == 5 ) { Program5_DynamicArrays(); }
    else if ( choice == 6 ) { Program6_UniquePointers(); }
    else if ( choice == 7 ) { Program7_SharedPointers(); }
    else if ( choice == 8 ) { Program8_TextAdventureMap(); }
  }
}

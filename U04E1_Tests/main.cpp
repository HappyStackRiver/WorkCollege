#include <iostream>
using namespace std;

#include "Functions/FunctionsTests.h"
#include "DataStructure/MyVectorTests.h"

int main()
{
    Test_IsOverdrawn();
    Test_AdjustIngredients();
    Test_IsInputValid();
    Test_Average();
    Test_Summation();

    MyVectorTester tester;
    tester.Test_Constructor();
    tester.Test_PushBack();
    tester.Test_PopAt();
    tester.Test_GetAt();
    tester.Test_Size();
    tester.Test_Resize();
    tester.Test_IsFull();
    tester.Test_AllocateMemory();
    tester.Test_DeallocateMemory();

    return 0;
}

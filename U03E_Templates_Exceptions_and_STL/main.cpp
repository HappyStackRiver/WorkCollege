#include <iostream>
using namespace std;

#include "StoreProgram/Program.h"

int main()
{
    Program program;
    program.Start();

    Product product1;
    product1.name = "Video game";
    product1.price = 69.99;
    cout << "Product 1:" << endl;
    cout << product1.name << endl;
    cout << product1.price << endl;

    Product product2("Notebook", 1.23);
    cout << "Product 2:" << endl;
    cout << product2.name << endl;
    cout << product2.price << endl;

    return 0;
}

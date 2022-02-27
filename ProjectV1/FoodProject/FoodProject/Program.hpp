#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP

#include <iostream>
#include <fstream>

#include "Customer.hpp"
#include "Restaurant.hpp"
#include "Order.hpp"

using namespace std;

class Program
{
	public:
		void start();
		void runDriver();
		void runCustomer();
		//initial menus
	private:
		void loadData();
		void saveData();
		//loading and saving the data we put in the program via text file

		void clearScreen();
		
		void addCustomer();
		void addOrder();

		void editCustomer();
		void editCustomerName(int, string);
		void editCustomerPhone(int, int);
		void editCustomerAddress(int, string);

		bool logIn();
		void logOutCustomer();
		//customer options

		bool logInDriver();
		void addRestaurant();
		void viewAllOrders();
		void currentOrder();
		void viewCustomers();
		void exitDriverMenu();
		void logOutDriver();
		//driver options

};

void Program::start()
{
	bool done = false;

	while (!done)
	{
		cout << string(80, '-') << endl << "MAIN MENU" << endl << endl;

		cout << "0. Quit" << endl;
		cout << "1. Run as Driver" << endl;
		cout << "2. Run as Customer" << endl;

		int input = -1;

		do
		{
			cout << endl << "ENTER YOUR CHOICE (" << 0 << " - " << 2 << "): ";
			cin >> input;
		} while (input < 0 || input > 3);


		switch (input)
		{
		case 0:     done = true;        break;
		case 1:     runDriver();        break;
		case 2:     runCustomer();     break;
		}
	}
}


void Program::runDriver()
{
	bool done = false;
	while (!done)
	{
		clearScreen();

		int input = -1;

			clearScreen();
			cout << string(80, '-') << endl << "Welcome Robert!" << endl;
			cout << endl << string(80, '-') << endl << "OPTIONS:" << endl;
			cout << "0. Save and Quit" << endl;
			cout << "1. Add Restaurant" << endl;
			cout << "2. View All Orders" << endl;
			cout << "3. View All Customers" << endl;
			cout << "4. Get Next Order" << endl;

			cin >> input;

			switch (input)
			{
			case 1:     addRestaurant();            break;
			case 2:     viewAllOrders();       break;
			case 3:     viewCustomers();       break;
			case 4:     currentOrder();       break;
			case 0:		logOutDriver();
				done = true;
				break;
			}

	}
}
//options menu for the driver

bool Program::logInDriver()
{
	return true;
}
void Program::addRestaurant()
{

}
void Program::viewAllOrders()
{

}
void Program::currentOrder()
{

}
void Program::viewCustomers()
{

}
void Program::exitDriverMenu()
{
}
void Program::logOutDriver()
{

}

void Program::runCustomer()
{
	bool done = false;
	while (!done)
	{
		clearScreen();
		cout << string(80, '-') << endl << "Welcome" << endl;

		int input = -1;
		while (logIn())
		{
			clearScreen();
			cout << endl << string(80, '-') << endl << "OPTIONS:" << endl;
			cout << "0. Save and Quit" << endl;
			cout << "1. Update Customer Information" << endl;
			cout << "2. Create New Order" << endl;
			cin >> input;

			switch (input)
			{
			case 1:     editCustomer();            break;
			case 2:     addOrder();       break;
			case 0:		logOutCustomer();
				done = true;
				break;
			}
		}

	}
}
//options menu for the customer

bool Program::logIn()
{
	return true;
}


void Program::editCustomer()
{

}

void Program::addOrder()
{

}

void Program::logOutCustomer()
{

}


void Program::clearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("cls");
#else
	system("clear");
#endif
}


#endif


#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <chrono>

#include "Customer.hpp"
#include "Restaurant.hpp"
#include "Order.hpp"
#include "CsvParser.hpp"


using namespace std;

class Program
{
	public:
		void start();
		void runDriver();
		void runCustomer();
		//initial menus
	private:
		void loadDataCust();
		void loadDataRestaurant();
		void saveDataCustomer();
		void saveDataRestaurant();
		//loading and saving the data we put in the program via text file

		void clearScreen();
		
		void addOrder(int, int);

		void editCustomer(int);

		bool logIn();
		void logOutCustomer();
		//customer options

		bool logInDriver();
		void addRestaurant();
		void viewAllOrders();
		void currentOrder();
		void viewCustomers();
		void logOutDriver();
		//driver options

		map <int, Customer> m_customers;
		map <int, Restaurant> m_restaurants;
		queue <Order> m_orders;

};

void Program::start()
{
	bool done = false;
	loadDataCust();
	loadDataRestaurant();
	while (!done)
	{
		std::cout << string(80, '-') << endl << "MAIN MENU" << endl << endl;

		std::cout << "0. Quit" << endl;
		std::cout << "1. Run as Driver" << endl;
		std::cout << "2. Run as Customer" << endl;

		int input = -1;

		do
		{
			std::cout << endl << "ENTER YOUR CHOICE (" << 0 << " - " << 2 << "): ";
			std::cin >> input;
		} while (input < 0 || input > 3);


		switch (input)
		{
		case 0:     done = true;        break;
		case 1:     runDriver();        break;
		case 2:     runCustomer();     break;
		}
	}
	return;
}
void Program::loadDataCust()
{
	CsvDocument doc;
	int id;
	string name;
	int phone;
	string address;

	try
	{
		doc = CsvParser::Parse("Customers.csv");
	}
	catch (...)
	{
		// No customer file; new customer list.
		return;
	}

	// Load customer data
	Customer newCustomer;


	for (const auto& row : doc.rows)
	{
		for (int col = 0; col < row.size(); col++)
		{
			// What field are we looking at? Convert to the correct data type in our object.
			if (doc.header[col] == "id") {
				id = Helper::StringToInt(row[col]); 
				newCustomer.setId(id);
			}
			else if (doc.header[col] == "name") { 
				name = row[col];
				newCustomer.setName(name);

			}
			else if (doc.header[col] == "phone") { 
				phone = Helper::StringToInt(row[col]);
				newCustomer.setPhone(phone); 
			}
			else if (doc.header[col] == "address") {
				address = row[col];
				newCustomer.setAddress(address);
			}
		}

		// Save customer to the map
		m_customers[newCustomer.getId()] = newCustomer;
	}

	std::cout << m_customers.size() << " customers loaded" << endl;


}

void Program::loadDataRestaurant()
{
	CsvDocument doc;

	string name;
	string address;
	int id;

	try
	{
		doc = CsvParser::Parse("Restaurants.csv");
	}
	catch (...)
	{
		// No Restaurant file; new customer list.
		return;
	}

	// Load restaurant data
	Restaurant newRestaurant;


	for (const auto& row : doc.rows)
	{
		for (int col = 0; col < row.size(); col++)
		{
			// What field are we looking at? Convert to the correct data type in our object.
			if (doc.header[col] == "id") {
				id = Helper::StringToInt(row[col]);
				newRestaurant.setId(id);
			}
			else if (doc.header[col] == "name") {
				name = row[col];
				newRestaurant.setName(name);

			}
			else if (doc.header[col] == "address") {
				address = row[col];
				newRestaurant.setAddress(address);
			}
		}

		// Save customer to the map
		m_restaurants[newRestaurant.getIdRest()] = newRestaurant;
	}

	std::cout << m_restaurants.size() << " Restaurants loaded" << endl;


}

void Program::saveDataCustomer()
{
	CsvDocument doc;
	string id;
	string name;
	string phone;
	string address;


	// Specify what the fields are in the document
	doc.header.push_back("id");
	doc.header.push_back("name");
	doc.header.push_back("phone");
	doc.header.push_back("address");

	for (const auto& customer : m_customers)
	{
		// Create a list of cells for one customer row entry
		vector<string> cells;
		cells.push_back(Helper::ToString(customer.second.getId()));  // id
		cells.push_back(customer.second.getName());                    // name
		phone = Helper::ToString(customer.second.getPhone());
		cells.push_back(phone);                   // email
		cells.push_back(customer.second.getAddress());				  // address
		doc.rows.push_back(cells);
	}

	CsvParser::Save("Customers.csv", doc);
}

void Program::saveDataRestaurant()
{
	CsvDocument doc;
	string name;
	string address;


	// Specify what the fields are in the document
	doc.header.push_back("id");
	doc.header.push_back("name");
	doc.header.push_back("address");

	for (const auto& restaurant : m_restaurants)
	{
		// Create a list of cells for one customer row entry
		vector<string> cells;

		cells.push_back(Helper::ToString(restaurant.second.getIdRest()));						 // ID
		cells.push_back(restaurant.second.getName());                    // name
		cells.push_back(restaurant.second.getAddress());				  // address
		doc.rows.push_back(cells);
	}

	CsvParser::Save("Restaurants.csv", doc);
}

void Program::runDriver()
{
	if (logInDriver() == true)
	{
		bool done = false;
		while (!done)
		{

			int input = -1;

			clearScreen();
			std::cout << string(80, '-') << endl << "Welcome Robert!" << endl;
			std::cout << endl << string(80, '-') << endl << "OPTIONS:" << endl;
			std::cout << "0. Save and Quit" << endl;
			std::cout << "1. Add Restaurant" << endl;
			std::cout << "2. View All Orders" << endl;
			std::cout << "3. View All Customers" << endl;
			std::cout << "4. Get Next Order" << endl;

			std::cin >> input;

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
}
//options menu for the driver

bool Program::logInDriver()
{
	string input;
	std::cout << "Verify that you are a driver" << endl;
	std::cout << "What is your name?" << endl;
	
	std::cin >> input;

	if (input == "Robert")
	{
		return true;
	}
	else
		return false;
}
void Program::addRestaurant()
{
	clearScreen();
	string resName;
	string resAddress;
	int resId;

	string end;
	std::cin.ignore();
	std::cout << "Enter the name of the Restaurant:" << endl;
	std::getline(std::cin, resName);

	std::cout << "Enter the address of the Restaurant:" << endl;
	std::getline(std::cin,resAddress);

	std::cout << "Enter the ID of the Restaurant:" << endl;
	std::cin >> resId;
	Restaurant newRestaurant(resName, resAddress, resId);
	m_restaurants[newRestaurant.getIdRest()] = newRestaurant;
	std::cout << resName << " was successfully added!";
	std::cout << endl << "Press any key to continue";
	std::getline(std::cin,end);

}
void Program::viewAllOrders()

{
	queue <Order> temp = m_orders;
	size_t size = temp.size();

	if (m_orders.empty())
	{
		std::cout << "No pending orders" << endl;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << "Customer name: " << temp.front().customerloc->getName() << endl;
		std::cout << "Customer Address: " << temp.front().customerloc->getName() << endl;
		std::cout << "Restaurant: " << temp.front().restaurantloc->getName() << endl;
		temp.pop();

	}

	string storage;
	cin.ignore();
	std::getline(std::cin, storage);
}
void Program::currentOrder()
{
	std::cout << "Order" << endl;
	std::cout << m_orders.front().customerloc->getName() << endl;
	std::cout << "to: " << m_orders.front().customerloc->getAddress() << endl;

	std::cout << "Restaurant" << endl;
	std::cout << m_orders.front().restaurantloc->getName() << endl;

	std::cout << "Enter 0 to go back or 1 to complete order and get the next" << endl;
	int temp;
	std::cin >> temp;
	if (temp == 1)
	{
		m_orders.pop();
		std::cout << "Order complete, press Enter to continue";
		cin.ignore();
		string fill;
		std::getline(std::cin, fill);
		currentOrder();
	}
	else
	{
		return;
	}
}
void Program::viewCustomers()
{
	std::cout << "The following is all customers" << endl;
	size_t size = m_customers.size();

	for (const auto& customer : m_customers)
	{
		// customer.second
		std::cout << customer.second.getName() << endl;
		std::cout << customer.second.getPhone() << endl;
		std::cout << customer.second.getAddress() << endl;
	}
	

	std::cout << "Press any key and enter";
	string temp;
	cin.ignore();
	std::getline(std::cin, temp);
}

void Program::logOutDriver()
{
	saveDataRestaurant();
	start();
}

void Program::runCustomer()
{
	bool done = false;
	bool valid = false;
	int location;
	while (!done)
	{
		clearScreen();

		std::cout << string(80, '-') << endl << "Welcome" << endl;

		int input = -1;
		while (logIn())
		{
			std::cout << "Enter ID: ";
			std::cin >> input;


			if (m_customers.find(input) != m_customers.end())
			{
				location = input;
				// Customer found
			}
			else
			{
				continue;// Customer not found
			}


			valid = true;


			clearScreen();
			std::cout << endl << string(80, '-') << endl << "OPTIONS:" << endl;
			std::cout << "0. Save and Quit" << endl;
			std::cout << "1. Update Customer Information" << endl;
			std::cout << "2. Create New Order" << endl;

			std::cout << "Enter your selection: " << endl;

			std::cin >> input;

			switch (input)
			{
			case 1:     editCustomer(location);            break;
			case 2: {
				std::cout << "The following is all restaurants" << endl;
				size_t size = m_restaurants.size();

				for (int i = 1; i <= size; i++)
				{
					std::cout << "ID: " << m_restaurants[i].getIdRest() << endl;
					std::cout << m_restaurants[i].getName() << endl;
					std::cout << m_restaurants[i].getAddress() << endl << endl;;

				}

				std::cout << "Enter the ID of the restaurant you would like to order from: ";
				int restaurantId;
				std::cin >> restaurantId;
				addOrder(location, restaurantId);       break;
			}
			case 0:		logOutCustomer();
				done = true;
				break;
			}
		}
		std::cout << "Log in failed";
		runCustomer();


	}
}
//options menu for the customer

bool Program::logIn()
{
	int inputVal;
	string text = "";
	int num;
	std::cout << "New or returning user?" << endl;
	std::cout << "Enter 0 for new user, 1 for Returning User" << endl;
	std::cin >> inputVal;
	while (inputVal < 0 || inputVal > 1)
	{
		std::cout << "Invalid input, try again: ";
		std::cin >> inputVal;
		return false;
	}



		switch (inputVal)
		{
		case 0:
		{
			int newid = 0;
			bool found = false;

			std::cout << "Enter unique ID made up of numbers" << endl;
			std::cin >> newid;

			if (m_customers.find(newid) != m_customers.end())
			{

				std::cout << "Customer exists";
				return false;
				// Customer found
			}
			else
			{
				Customer newCustomer;
				newCustomer.setId(newid);
				std::cin.ignore();

				std::cout << "Enter your name: ";
				std::getline (std::cin,text);
				newCustomer.setName(text);

				std::cout << "Enter your address: ";
				std::getline(std::cin, text);
				newCustomer.setAddress(text);

				std::cout << "Enter your number: ";
				std::cin >> num;
				newCustomer.setPhone(num);

				m_customers[newid] = newCustomer;

				// Customer not found
			}

			std::cout << "New account was created do not forget your unique ID" << endl;
			return true;
		}
		case 1:
		{
			return true;
		}

		}


}


void Program::editCustomer(int id)
{
	clearScreen();
	int newPhone;
	string newAddress;

	int input;

	std::cout << "Would you like to change your address or your phone number?" << endl;
	std::cout << "Enter 1 for Address, 2 for phone number." << endl;

	std::cin >> input;

	switch (input)
	{
		case 1:
		{
			std::cout << "Enter new address as a string" << endl;
			std::cin >> newAddress;
				m_customers[id].setAddress(newAddress);
				break;
		}
		case 2:
		{
			std::cout << "Enter new phone number as an integer" << endl;
			std::cin >> newPhone;
			m_customers[id].setPhone(newPhone);
				break;
		}
		default:
		{
			std::cout << "Customer information was not able to be edited" << endl;
				break;
		}
	}

}

void Program::addOrder(int location, int restID)
{
	Order newOrder;
	newOrder.customerloc = &m_customers[location];
	newOrder.restaurantloc = &m_restaurants[restID];

	m_orders.push(newOrder);
	std::cout << "Order Added" << endl;
}

void Program::logOutCustomer()
{
	saveDataCustomer();
	start();
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


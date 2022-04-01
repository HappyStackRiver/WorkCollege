#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <chrono>

#include "Customer.hpp"
#include "Restaurant.hpp"
#include "Order.hpp"
#include "Driver.hpp"
#include "CsvParser.hpp"


using namespace std;

class Program
{
	public:
		void start();
		void runDriver();
		void runCustomer();
		void runAdmin();
		//initial menus
	private:
		void loadDataCust();
		void loadDataRestaurant();
		void saveDataCustomer();
		void saveDataRestaurant();

		void loadDataDriver();//new driver stuff
		void saveDataDriver();//new driver stuff
		//loading and saving the data we put in the program via text file

		void clearScreen();
		
		void addOrder(int, int);

		void editCustomer(int);

		void viewCustOrders();

		bool logIn();
		void logOutCustomer();
		//customer options

		bool logInDriver();
		void addRestaurant();
		void editRestaurant(int);

		void viewAllOrders();
		void currentOrder();

		void viewCustomers();
		void viewRestaurants();
		void viewDrivers();
		void viewAllOld();

		void logOutDriver();
		//driver options

		map <int, Customer> m_customers;
		map <int, Restaurant> m_restaurants;
		map <int, Driver> m_drivers;
		queue <Order> m_orders;
		queue <Order> m_specificOrders;
		queue <Order> m_driverHistory;
		queue <Order> m_customerHistory;
		queue <Order> m_allHistory;
		int fee  = 5;
		int pay = 2;

};

void Program::start()
{
	bool done = false;
	loadDataCust();
	loadDataRestaurant();
	loadDataDriver();
	while (!done)
	{
		std::cout << string(80, '-') << endl << "MAIN MENU" << endl << endl;

		std::cout << "0. Quit" << endl;
		std::cout << "1. Run as Driver" << endl;
		std::cout << "2. Run as Customer" << endl;
		std::cout << "3. Run as Admin" << endl;

		int input = -1;

		do
		{
			std::cout << endl << "ENTER YOUR CHOICE (" << 0 << " - " << 3 << "): ";
			std::cin >> input;
		} while (input < 0 || input > 3);


		switch (input)
		{
		case 0:     done = true;        break;
		case 1:     runDriver();        break;
		case 2:     runCustomer();     break;
		case 3:		runAdmin();		   break;
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
	int price;

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
			else if (doc.header[col] == "price") {
				price = Helper::StringToInt(row[col]);
				newRestaurant.setPrice(price);
			}
		}

		// Save customer to the map
		m_restaurants[newRestaurant.getIdRest()] = newRestaurant;
	}

	std::cout << m_restaurants.size() << " Restaurants loaded" << endl;


}

void Program::loadDataDriver()
{
	CsvDocument doc;

	string name;
	int id;

	try
	{
		doc = CsvParser::Parse("Drivers.csv");
	}
	catch (...)
	{
		// No Driver file; new driver list.
		return;
	}

	// Load driver data
	Driver newDriver;


	for (const auto& row : doc.rows)
	{
		for (int col = 0; col < row.size(); col++)
		{
			// What field are we looking at? Convert to the correct data type in our object.
			if (doc.header[col] == "id") {
				id = Helper::StringToInt(row[col]);
				newDriver.setId(id);
			}
			else if (doc.header[col] == "name") {
				name = row[col];
				newDriver.setName(name);

			}
		}

		// Save customer to the map
		m_drivers[newDriver.getId()] = newDriver;
	}

	std::cout << m_restaurants.size() << " Drivers loaded" << endl;


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
	doc.header.push_back("price");

	for (const auto& restaurant : m_restaurants)
	{
		// Create a list of cells for one customer row entry
		vector<string> cells;

		cells.push_back(Helper::ToString(restaurant.second.getIdRest()));						 // ID
		cells.push_back(restaurant.second.getName());                    // name
		cells.push_back(restaurant.second.getAddress());				  // address
		cells.push_back(Helper::ToString(restaurant.second.getPrice()));
		doc.rows.push_back(cells);
	}

	CsvParser::Save("Restaurants.csv", doc);
}

void Program::saveDataDriver()
{
	CsvDocument doc;
	string name;


	// Specify what the fields are in the document
	doc.header.push_back("id");
	doc.header.push_back("name");

	for (const auto& drivers : m_drivers)
	{
		// Create a list of cells for one customer row entry
		vector<string> cells;

		cells.push_back(Helper::ToString(drivers.second.getId()));						 // ID
		cells.push_back(drivers.second.getName());                    // name
		doc.rows.push_back(cells);
	}

	CsvParser::Save("Drivers.csv", doc);
}

void Program::runAdmin()
{
	cout << "Enter the proper name of the Admin" << endl;
	string nameVer;
	cin >> nameVer;
	if (nameVer != "Raymond")
	{
		cout << "Incorrect name" << endl;
		start();
	}
	else
	{
		cout << "ADMIN VIEW" << endl << endl;
		cout << "0. LOG OUT" << endl << endl;
		cout << "1. VIEW ALL RESTAURANTS" << endl;
		cout << "2. ADD RESTAURANT" << endl;
		cout << "3. EDIT RESTAURANT" << endl;
		cout << endl << "4. VIEW ALL CUSTOMERS" << endl;
		cout << "5. VIEW ALL DRIVERS" << endl;
		cout << "6. VIEW COMPLETED ORDER HISTORY" << endl;
		cout << "7. SET DELIVERY FEE" << endl;
		cout << "8. SET DRIVER PAYMENT" << endl;

		int input;
		cin >> input;

		switch (input)
		{
		case 0:
			start();
			;
		case 1:
			viewRestaurants()
				;
		case 2:
			addRestaurant()
				;
		case 3:
		{
			cout << "Restaurant editing" << endl;
			cout << "Enter the ID of the restaurant you are editing" << endl;
			int choice;
			cin >> choice;
			editRestaurant(choice)
				; }
		case 4:
			viewCustomers()
				;
		case 5:
			viewDrivers()
				;
		case 6:
		{
			viewAllOld()
				; }
		case 7:
		{
			cout << "Enter the amount the new delivery fee" << endl;
			int newFee;
			cin >> newFee;
			fee = newFee;
			cout << "The new fee updated"
			; }
		case 8:
			cout << "Enter the amount the new delivery pay" << endl;
			int newPay;
			cin >> newPay;
			pay = newPay;
			cout << "The new pay updated"
				;

		}
	}

}
void Program::viewAllOld()
{
	queue <Order> temp = m_driverHistory;
	size_t size = temp.size();

	if (m_driverHistory.empty())
	{
		std::cout << "No completed orders yet" << endl;
		std::cout << "Press any key and enter" << endl;
		string storage;
		cin.ignore();
		std::getline(std::cin, storage);
		return;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << "---" << i << "---" << endl;
		std::cout << "Customer name: " << temp.front().customerloc->getName() << endl;
		std::cout << "Customer Address: " << temp.front().customerloc->getName() << endl;
		std::cout << "Restaurant: " << temp.front().restaurantloc->getName() << endl;
		std::cout << "Price: " << temp.front().restaurantloc->getPrice() << endl;
		std::cout << "Fee: " << fee << endl;
		std::cout << "Driver Pay: " << pay << endl;
		std::cout << "Profit: " << temp.front().restaurantloc->getPrice() - fee - pay << endl << endl;
		temp.pop();

	}
	std::cout << "Press any key and enter" << endl;
	string storage;
	cin.ignore();
	std::getline(std::cin, storage);
}

void Program::runDriver()
{
	bool done = false;
	bool valid = false;
	int location;
	while (!done)
	{
		clearScreen();

		std::cout << string(80, '-') << endl << "Welcome" << endl;

		int input = -1;
		while (logInDriver())
		{
			std::cout << "Enter ID: ";
			std::cin >> input;


			if (m_drivers.find(input) != m_drivers.end())
			{
				location = input;
				// driver found
			}
			else
			{
				continue;// Driver not found
			}

					valid = true;


					clearScreen();
					std::cout << "Hello " << m_drivers[location].getName() << endl;
					std::cout << endl << string(80, '-') << endl << "OPTIONS:" << endl;
					std::cout << "0. Save and Quit" << endl;
					std::cout << "1. Get Next order" << endl;
					std::cout << "2. View Delivery History" << endl;

					std::cout << "Enter your selection: " << endl;

					std::cin >> input;

					switch (input)
					{
					case 1:     currentOrder();            break;
					case 2: continue;
					case 0:		logOutDriver();
						done = true;
						break;
					}
				}
				std::cout << "Log in failed";
				runDriver();


			}
}
//options menu for the driver

bool Program::logInDriver()
{

		int inputVal;
		string text = "";
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

			if (m_drivers.find(newid) != m_drivers.end())
			{

				std::cout << "Driver exists";
				return false;
				// Driver found
			}
			else
			{
				Driver newDriver;
				newDriver.setId(newid);
				std::cin.ignore();

				std::cout << "Enter your name: ";
				std::getline(std::cin, text);
				newDriver.setName(text);

				m_drivers[newid] = newDriver;

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
		return false;
}

void Program::addRestaurant()
{
	clearScreen();
	string resName;
	string resAddress;
	int resId;
	int resPrice;

	string end;
	std::cin.ignore();
	std::cout << "Enter the name of the Restaurant:" << endl;
	std::getline(std::cin, resName);

	std::cout << "Enter the address of the Restaurant:" << endl;
	std::getline(std::cin,resAddress);

	std::cout << "Enter the ID of the Restaurant:" << endl;
	std::cin >> resId;

	std::cout << "Enter the price of the Restaurant" << endl;
	std::cin >> resPrice;

	Restaurant newRestaurant(resName, resAddress, resId, resPrice);
	m_restaurants[newRestaurant.getIdRest()] = newRestaurant;
	std::cout << resName << " was successfully added!";
	std::cout << endl << "Press any key to continue";
	std::string fin;
	std::getline(std::cin,fin);
	saveDataRestaurant();
	runAdmin();

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
		m_driverHistory.push(m_orders.front());
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
void Program::viewRestaurants()
{
	std::cout << "The following is all restaurants" << endl;
	size_t size = m_restaurants.size();

	for (const auto& restaurant : m_restaurants)
	{
		// customer.second
		std::cout << restaurant.second.getName() << endl;
		std::cout << restaurant.second.getAddress() << endl;
		std::cout << restaurant.second.getIdRest() << endl << endl;
	}


	std::cout << "Press any key and enter";
	string temp;
	cin.ignore();
	std::getline(std::cin, temp);
	runAdmin();
}

void Program::viewDrivers()
{
	std::cout << "The following is all drivers" << endl;
	size_t size = m_drivers.size();

	for (const auto& drivers : m_drivers)
	{
		// customer.second
		std::cout << drivers.second.getName() << endl;
		std::cout << drivers.second.getId() << endl << endl;
	}


	std::cout << "Press any key and enter";
	string temp;
	cin.ignore();
	std::getline(std::cin, temp);
	runAdmin();
}

void Program::logOutDriver()
{
	saveDataDriver();
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
			std::cout << "Welcome " << m_customers[location].getName() << endl;
			std::cout << "Current Phone Number: " << m_customers[location].getPhone() << endl;
			std::cout << endl << string(80, '-') << endl << "OPTIONS:" << endl;
			std::cout << "0. Save and Quit" << endl;
			std::cout << "1. Update Customer Information" << endl;
			std::cout << "2. Create New Order" << endl;
			std::cout << "3. View Order History" << endl;

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
			case 3:		viewCustOrders();
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
		return false;
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
	saveDataCustomer();

}

void Program::editRestaurant(int id)
{
	clearScreen();
	string name;
	string newAddress;
	int price;
	if (m_restaurants.find(id) != m_restaurants.end())
	{
		cout << "What would you like to change about the restaurant?" << endl;
		cout << "If you would like to change the name, press 1" << endl;
		cout << "If you would like to change the restaurant price, press 2" << endl;
		cout << "If you would like to change the restaurant address, press 3" << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
		{
			cout << "Enter new name as a string" << endl;
			cin.ignore();
			getline(cin, name);
			m_restaurants[id].setName(name);
			break;
		}
		case 2:
		{
			cout << "Enter new price as an integer" << endl;
			std::cin >> price;
			m_restaurants[id].setPrice(price);
			break;
		}
		case 3:
			std::cout << "Enter new address as a string" << endl;
			std::cin >> newAddress;
			m_restaurants[id].setAddress(newAddress);
			break;
		}
	}
	else
	{
		cout << "Restaurant ID not Valid" << endl;
	}
	saveDataRestaurant();
	runAdmin();

}

void Program::addOrder(int location, int restID)
{
	Order newOrder;
	newOrder.customerloc = &m_customers[location];
	newOrder.restaurantloc = &m_restaurants[restID];

	m_orders.push(newOrder);
	m_specificOrders.push(newOrder);

	std::cout << "Order Added" << endl;
}

void Program::viewCustOrders()

{
	queue <Order> temp = m_specificOrders;
	size_t size = temp.size();

	if (m_specificOrders.empty())
	{
		std::cout << "No recent orders" << endl;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << "Customer name: " << temp.front().customerloc->getName() << endl;
		std::cout << "Customer Address: " << temp.front().customerloc->getName() << endl;
		std::cout << "Restaurant: " << temp.front().restaurantloc->getName() << endl;
		std::cout << "Meal Price: $" << temp.front().restaurantloc->getPrice() << endl;
		std::cout << "Fee: $" << fee << endl;
		std::cout << "Total: $" << (temp.front().restaurantloc->getPrice()) + fee << endl;
		temp.pop();

	}

	string storage;
	cin.ignore();
	std::getline(std::cin, storage);
	runAdmin();
}

void Program::logOutCustomer()
{
	saveDataCustomer();
	while (!m_specificOrders.empty())//add logic to pop all from the specific orders queue
	{
		m_specificOrders.pop();
	}
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


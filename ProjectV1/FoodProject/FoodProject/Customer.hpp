#ifndef _CUSTOMER_HPP
#define _CUSTOMER_HPP
 
#include<iostream>
#include<string>

using namespace std;

class Customer
{
	private:
		string customerName;
		int customerPhoneNumber;
		string customerAddress;
		int customerId;

	public:
		Customer();//default constructor
		Customer(string, int, string, int);
		//parameter constructor to make a new customer class with new parameters
		
		string getName();
		int getPhone();
		string getAddress();
		//getter functions to retrieve the information stored in the class

		void setName(string);
		void setPhone(int);
		void setAddress(string);
		void setId(int);
		//setter functions to set the 
};


Customer::Customer()
{
	customerName = "";
	customerAddress = "";
	customerPhoneNumber = 0000000000;
}

Customer::Customer(string inputName, int inputPhone, string inputAddress, int inputId)
{
	setName(inputName);
	setPhone(inputPhone);
	setAddress(inputAddress);
	setId(inputId);

}
string Customer::getName()
{
	return customerName;
}

int Customer::getPhone()
{
	return customerPhoneNumber;
}

string Customer::getAddress()
{
	return customerAddress;
}

void Customer::setName(string name)
{
	customerName = name;
}

void Customer::setId(int inputId)
{
	customerId = inputId;
}

void Customer::setPhone(int phone)
{
	customerPhoneNumber = phone;
}
void Customer::setAddress(string address)
{
	customerAddress = address;
}
#endif
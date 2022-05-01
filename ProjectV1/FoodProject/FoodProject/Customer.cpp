#include "Customer.h"

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
string Customer::getName() const
{
	return customerName;
}

int Customer::getPhone() const
{
	return customerPhoneNumber;
}

string Customer::getAddress() const
{
	return customerAddress;
}

int Customer::getId() const
{
	return customerId;
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
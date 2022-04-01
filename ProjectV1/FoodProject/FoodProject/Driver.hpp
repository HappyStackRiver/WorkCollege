#ifndef _DRIVER_HPP
#define _DRIVER_HPP

#include<iostream>
#include<string>
#include<queue>
#include "Order.hpp"

using namespace std;

class Driver
{
private:
	string driverName;
	int driverId;

public:
	Driver();//default constructor
	Driver(string, int);
	//parameter constructor to make a new customer class with new parameters

	string getName() const;
	int getId() const;
	//getter functions to retrieve the information stored in the class

	void setName(string);
	void setId(int);
	//setter functions to set the 
	queue<Order> history;
};


Driver::Driver()
{
	driverName = "";
}

Driver::Driver(string inputName, int inputId)
{
	setName(inputName);
	setId(inputId);

}
string Driver::getName() const
{
	return driverName;
}

int Driver::getId() const
{
	return driverId;
}

void Driver::setName(string name)
{
	driverName = name;
}

void Driver::setId(int inputId)
{
	driverId = inputId;
}
#endif
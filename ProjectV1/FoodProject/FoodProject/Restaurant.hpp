#ifndef _RESTAURANT_HPP
#define _RESTAURANT_HPP

#include<iostream>
#include<string>

using namespace std;

class Restaurant
{
private:
	string restaurantName;
	string restaurantAddress;

public:
	Restaurant();//default constructor
	Restaurant(string, string);
	//parameter constructor to make a new customer class with new parameters

	string getName();
	string getAddress();
	//getter functions to retrieve the information stored in the class

	void setName(string);
	void setAddress(string);
	//setter functions to set the 
};


Restaurant::Restaurant()
{
	restaurantName = "";
	restaurantAddress = "";
}

Restaurant::Restaurant(string inputName, string inputAddress)
{
	setName(inputName);
	setAddress(inputAddress);
}

string Restaurant::getName()
{
	return restaurantName;
}

string Restaurant::getAddress()
{
	return restaurantAddress;
}

void Restaurant::setName(string name)
{
	restaurantName = name;
}

void Restaurant::setAddress(string address)
{
	restaurantAddress = address;
}
#endif
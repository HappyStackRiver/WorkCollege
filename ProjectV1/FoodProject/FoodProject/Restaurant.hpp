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
	int restId;

public:
	Restaurant();//default constructor
	Restaurant(string, string,int);
	//parameter constructor to make a new customer class with new parameters

	string getName() const;
	string getAddress() const;
	int getIdRest() const;
	//getter functions to retrieve the information stored in the class

	void setName(string);
	void setAddress(string);
	void setId(int);
	//setter functions to set the 
};


Restaurant::Restaurant()
{
	restaurantName = "";
	restaurantAddress = "";
}

Restaurant::Restaurant(string inputName, string inputAddress, int inputID)
{
	setName(inputName);
	setAddress(inputAddress);
	setId(inputID);
}

string Restaurant::getName() const
{
	return restaurantName;
}

string Restaurant::getAddress() const
{
	return restaurantAddress;
}

int Restaurant::getIdRest() const
{
	return restId;
}

void Restaurant::setName(string name)
{
	restaurantName = name;
}

void Restaurant::setAddress(string address)
{
	restaurantAddress = address;
}
void Restaurant::setId(int inputID)
{
	restId = inputID;
}
#endif
#ifndef _RESTAURANT_H
#define _RESTAURANT_H

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

#endif
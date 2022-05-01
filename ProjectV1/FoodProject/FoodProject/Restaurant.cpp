#include "Restaurant.h"

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


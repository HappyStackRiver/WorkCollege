#ifndef _MEALS_H
#define _MEALS_H

#include<iostream>
#include<string>

using namespace std;

class Meals
{
private:
	string mealName;
	int mealPrice;
	int mealId;

public:
	Meals();//default constructor
	Meals(string, int, int);
	//parameter constructor to make a new customer class with new parameters

	string getName() const;
	int getIdMeal() const;
	int getPrice() const;
	//getter functions to retrieve the information stored in the class

	void setName(string);
	void setId(int);
	void setPrice(int);
	//setter functions to set the 
};
#endif
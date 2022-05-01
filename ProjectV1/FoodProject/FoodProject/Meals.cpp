#include "Meals.h"

Meals::Meals()
{
	mealName = "";
	mealPrice = 0;
}

Meals::Meals(string inputName, int inputPrice, int inputID)
{
	setName(inputName);
	setPrice(inputPrice);
	setId(inputID);
}

string Meals::getName() const
{
	return mealName;
}
int Meals::getPrice() const
{
	return mealPrice;
}
int Meals::getIdMeal() const
{
	return mealId;
}

void Meals::setName(string name)
{
	mealName = name;
}

void Meals::setId(int inputID)
{
	mealId = inputID;
}

void Meals::setPrice(int input)
{
	mealPrice = input;
}
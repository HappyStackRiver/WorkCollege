#ifndef _ORDER_HPP
#define _ORDER_HPP
#include <vector>
#include "Customer.h"
#include "Restaurant.h"
#include "Meals.h"
#include <queue>
#include <iostream>

using namespace std;

struct Order
{
	Customer* customerloc;
	Restaurant* restaurantloc;
	int mealID;
	Order();
};
Order::Order()
{

	customerloc = nullptr;
	restaurantloc = nullptr;
	mealID = 0;
}

#endif // 

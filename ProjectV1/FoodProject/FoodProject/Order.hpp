#ifndef _ORDER_HPP
#define _ORDER_HPP
#include <vector>
#include "Customer.hpp"
#include "Restaurant.hpp"
#include <queue>
#include <iostream>

using namespace std;

struct Order
{
	Customer* customerloc;
	Restaurant* restaurantloc;
	Order();
};
Order::Order()
{

	customerloc = nullptr;

	restaurantloc = nullptr;
}

#endif // 

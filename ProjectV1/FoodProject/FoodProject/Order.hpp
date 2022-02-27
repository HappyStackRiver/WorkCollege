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
	Order *nextPtr;
	class Customer;
	class Restaurant;
};

#endif // 

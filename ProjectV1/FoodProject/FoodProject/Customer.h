#ifndef _CUSTOMER_H
#define _CUSTOMER_H
 
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Customer
{
	private:
		string customerName;
		int customerPhoneNumber;
		string customerAddress;
		int customerId;


	public:
		Customer();//default constructor
		Customer(string, int, string, int);
		//parameter constructor to make a new customer class with new parameters
		
		string getName() const;
		int getPhone() const;
		string getAddress() const;
		int getId() const;
		//getter functions to retrieve the information stored in the class

		void setName(string);
		void setPhone(int);
		void setAddress(string);
		void setId(int);
		//setter functions to set the 
};
#endif
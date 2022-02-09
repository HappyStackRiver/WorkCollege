#include "ShoppingCart.h"

#include <iostream>
#include <iomanip>
using namespace std;

void ShoppingCart::AddToCart(const Product& product)
{
	m_cart.push_back(product);
}

void ShoppingCart::RemoveFromCart(int index)
{
	m_cart.erase(m_cart.begin() + index);
}

void ShoppingCart::Display() const
{
    if (m_cart.size() == 0)
    {
        throw std::logic_error("The cart is empty");
    }

    cout << left
        << setw(20) << "#"
        << setw(20) << "NAME"
        << setw(20) << "PRICE" << endl;

    cout << string(80, '-') << endl;

    for (size_t i = 0; i < m_cart.size(); i++)
    {
        const Product& product = m_cart[i];
        cout << left
            << setw(20) << (i + 1)
            << setw(20) << product.name
            << setw(20) << product.price << endl;
    }

}

size_t ShoppingCart::GetItemCount() const
{
    return m_cart.size();
}

float ShoppingCart::GetTotalCost() const
{
    float totalCosts = 0;
    for (size_t i = 0; i < m_cart.size(); i++)
    {
        totalCosts = totalCosts + m_cart[i].price;
    }
}

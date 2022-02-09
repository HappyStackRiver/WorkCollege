#include "ShoppingCart.h"

#include <iostream>
#include <iomanip>
using namespace std;

void ShoppingCart::AddToCart(const Product& product)
{
	m_cart.PushBack(product);
}

void ShoppingCart::RemoveFromCart(int index)
{
	m_cart.PopAt(index);
}

void ShoppingCart::Display() const
{
    if (m_cart.Size() == 0)
    {
        cout << "The cart is empty";
        return;
    }

    cout << left
        << setw(20) << "#"
        << setw(20) << "NAME"
        << setw(20) << "PRICE" << endl;

    cout << string(80, '-') << endl;

    for (size_t i = 0; i < m_cart.Size(); i++)
    {
        const Product& product = m_cart.GetAt(i);
        cout << left
            << setw(20) << (i + 1)
            << setw(20) << product.name
            << setw(20) << product.price << endl;
    }

}

size_t ShoppingCart::GetItemCount() const
{
    return m_cart.Size();
}

float ShoppingCart::GetTotalCost() const
{
    float totalCosts = 0;
    for (size_t i = 0; i < m_cart.Size(); i++)
    {
        totalCosts = totalCosts + m_cart.GetAt(i).price;
    }
    return totalCosts;
}

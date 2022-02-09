#ifndef _SHOPPING_CART_H
#define _SHOPPING_CART_H

#include <vector>
using namespace std;

#include "Product.h"
#include "../DataStructure/MyVector.h"

class ShoppingCart
{
public:
    void AddToCart(const Product& product);
    void RemoveFromCart(int index);
    void Display()                              const;
    size_t GetItemCount()                       const;
    float GetTotalCost()                        const;

private:
    MyVector<Product> m_cart;
};

#endif

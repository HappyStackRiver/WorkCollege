#ifndef _STORE_H
#define _STORE_H

#include <map>
#include <string>
using namespace std;

#include "Product.h"

class Store
{
public:
    bool HasProduct(string name) const noexcept;
    bool HasProduct(int id) const noexcept;
    const Product& GetProductByName(string name) const;
    const Product& GetProductById(int id) const;
    size_t GetProductCount() const;
    void Display() const noexcept;

    void SaveData() noexcept;
    void LoadData() noexcept;

    void AddProduct(int id, string name, float price) noexcept;
    void UpdateProduct(int id, string name, float price);
    void RemoveProduct(int id);

private:
    map<int, Product> m_products;
};

#endif

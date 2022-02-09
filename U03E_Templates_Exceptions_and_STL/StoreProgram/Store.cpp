#include "Store.h"

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "../Utilities/Helper.hpp"
#include "../Exceptions/ProductNotFoundException.h"

bool Store::HasProduct(string name) const noexcept
{
    for (auto& product : m_products)
    {
        if (product.second.name == name)
        {
            return true;
        }
    }
    return false;
}

bool Store::HasProduct(int id) const noexcept
{
    return (m_products.find(id) != m_products.end());
}

const Product& Store::GetProductByName(string name) const
{
    for (auto& product : m_products)
    {
        if (product.second.name == name)
        {
            return product.second;
        }
    }
    throw ProductNotFoundException("Product name \"" + name + "\"not found");
}

const Product& Store::GetProductById(int id) const
{
    try
    {
        return m_products.at(id);
    }
    catch (const out_of_range& ex)
    {
        throw ProductNotFoundException("Product id " + Helper::ToString(id) + " not found!");
    }

}

size_t Store::GetProductCount() const
{
    return m_products.size();
}

void Store::Display() const noexcept
{
    if (GetProductCount() == 0)
    {
        cout << "The store is empty";
        return;
    }
    cout << left
        << setw(20) << "ID"
        << setw(20) << "NAME"
        << setw(20) << "PRICE" << endl;

    cout << string(80, '-') << endl;

    for (auto& item : m_products)
    {
        cout << left
            << setw(20) << item.first
            << setw(20) << item.second.name
            << setw(20) << item.second.price << endl;
    }

}

void Store::LoadData() noexcept
{
    ifstream input("../SAVEDATA/data.txt");

    if (input.fail())
    {
        return;
    }

    int id;
    float price;
    string name;

    while (input >> id)
    {
        input.ignore();
        getline(input, name);
        input >> price;
        AddProduct(id, name, price);
    }

    cout << GetProductCount() << " product(s) loaded" << endl;
}

void Store::AddProduct(int id, string name, float price) noexcept
{
    m_products[id].price = price;
    m_products[id].name = name;
}

void Store::UpdateProduct(int id, string name, float price)
{
    if (!HasProduct(id))
    {
        throw ProductNotFoundException("Product id " + Helper::ToString(id) + " not found! (In void Store::UpdateProduct( int id, string name, float price ))");
    }

    m_products[id].price = price;
    m_products[id].name = name;

}

void Store::RemoveProduct(int id)
{
    if (!HasProduct(id))
    {
        throw ProductNotFoundException("Product id " + Helper::ToString(id) + " not found! (In void Store::UpdateProduct( int id, string name, float price ))");
    }
    m_products.erase(id);
}

void Store::SaveData() noexcept
{
    ofstream output("../SAVEDATA/data.txt");

    for (auto& product : m_products)
    {
        output << product.first << endl
            << product.second.name << endl
            << product.second.price << endl << endl;
    }

    cout << GetProductCount() << " product(s) saved" << endl;
}

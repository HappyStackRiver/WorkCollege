#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "Store.h"
#include "ShoppingCart.h"

class Program
{
public:
    Program();
    ~Program();

    void Setup() noexcept;
    void Cleanup() noexcept;

    void Start() noexcept;
    void Run_Admin() noexcept;
    void Run_Customer() noexcept;

private:
    string m_storeName;
    Store m_store;
    ShoppingCart m_shoppingCart;

    void LoadData() noexcept;
    void SaveData() noexcept;

    // Menus
    void Menu_AddProduct() noexcept;
    void Menu_EditProduct() noexcept;
    void Menu_RemoveProduct() noexcept;

    void Menu_Checkout() noexcept;
    void Menu_AddProductToCart() noexcept;
    void Menu_RemoveProductFromCart() noexcept;

    // Display helpers
    void DisplayStoreInventory() const noexcept;
    void DisplayYourCart() const noexcept;
    void DisplayOptions_Admin() const noexcept;
    void DisplayOptions_Customer() const noexcept;
    void ClearScreen() const noexcept;
    void DisplayMenuHeader( const string& text ) const noexcept;

    // Input helpers
    int Get_IntBetweenRange( int min, int max ) const noexcept;
    int Get_ProductId() const noexcept;
    void HitEnterToContinue() const noexcept;
};

#endif

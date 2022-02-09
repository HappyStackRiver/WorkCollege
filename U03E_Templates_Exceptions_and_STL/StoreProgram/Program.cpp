#include "Program.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "../Exceptions/ProductNotFoundException.h"

Program::Program()
{
    Setup();
}

Program::~Program()
{
    Cleanup();
}

void Program::Setup() noexcept
{
    m_storeName = "OVERLAND PIZZA";
    m_store.LoadData();
}

void Program::Cleanup() noexcept
{
    m_store.SaveData();
}

void Program::Start() noexcept
{
    bool done = false;

    while ( !done )
    {
        cout << string( 80, '-' ) << endl << "MAIN MENU" << endl << endl;

        cout << "0. Quit" << endl;
        cout << "1. Run store program - AS ADMIN" << endl;
        cout << "2. Run store program - AS CUSTOMER" << endl;

        int choice = Get_IntBetweenRange( 0, 2 );

        switch( choice )
        {
            case 0:     done = true;        break;
            case 1:     Run_Admin();        break;
            case 2:     Run_Customer();     break;
        }
    }
}

void Program::Run_Customer() noexcept
{
    bool done = false;
    while ( !done )
    {
        ClearScreen();
        DisplayMenuHeader( "WELCOME TO " + m_storeName + "!" );

        DisplayStoreInventory();
        DisplayYourCart();
        DisplayOptions_Customer();

        int choice = Get_IntBetweenRange( 0, 2 );

        switch( choice )
        {
            case 1:     Menu_AddProductToCart();            break;
            case 2:     Menu_RemoveProductFromCart();       break;
            case 0:
                Menu_Checkout();
                done = true;
                break;
        }
    }
}

void Program::Run_Admin() noexcept
{
    bool done = false;
    while ( !done )
    {
        ClearScreen();
        DisplayMenuHeader( m_storeName + " ADMIN MENU" );

        DisplayStoreInventory();
        DisplayYourCart();
        DisplayOptions_Admin();

        int choice = Get_IntBetweenRange( 0, 3 );

        switch( choice )
        {
            case 1:     Menu_AddProduct();          break;
            case 2:     Menu_EditProduct();         break;
            case 3:     Menu_RemoveProduct();       break;
            case 0:     done = true;                break;
        }
    }
}

void Program::DisplayStoreInventory() const noexcept
{
    cout << endl << string( 80, '-' ) << endl << "STORE INVENTORY:" << endl;
    m_store.Display();
}

void Program::DisplayYourCart() const noexcept
{
    cout << endl << string( 80, '-' ) << endl << "YOUR CART:" << endl;
    m_shoppingCart.Display();
}

void Program::DisplayOptions_Admin() const noexcept
{
    cout << endl << string( 80, '-' ) << endl << "OPTIONS:" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add product" << endl;
    cout << "2. Edit product" << endl;
    cout << "3. Remove product" << endl;
}

void Program::DisplayOptions_Customer() const noexcept
{
    cout << endl << string( 80, '-' ) << endl << "OPTIONS:" << endl;
    cout << "0. Checkout and quit" << endl;
    cout << "1. Add product to cart" << endl;
    cout << "2. Remove product from cart" << endl;
}

int Program::Get_IntBetweenRange( int min, int max ) const noexcept
{
    int input;

    do
    {
        cout << endl << "ENTER YOUR CHOICE (" << min << " - " << max << "): ";
        cin >> input;
    } while ( input < min || input > max );

    return input;
}

int Program::Get_ProductId() const noexcept
{
    DisplayStoreInventory();

    cout << endl << "What is the UNIQUE ID of the product? ...";
    int id;
    cin >> id;

    return id;
}

void Program::Menu_AddProduct() noexcept
{
    ClearScreen();
    DisplayMenuHeader( "ADD PRODUCT" );

    int id;
    string name;
    float price;

    cout << "What is the UNIQUE ID of the product? ...";
    cin >> id;

 
    while ( m_store.HasProduct( id ) )
    {
        cout << "ERROR: that unique ID is already in use by another product!" << endl;
        cout << endl << "What is the UNIQUE ID of the item? ";
        cin >> id;
    }

    cout << "What is the name of the product? ........";
    cin.ignore();
    getline( cin, name );

    cout << "What is the price of the product? .......$";
    cin >> price;


    m_store.AddProduct( id, name, price );

    cout << endl << "Product added." << endl;
    HitEnterToContinue();
}

void Program::Menu_EditProduct() noexcept
{
    ClearScreen();
    DisplayMenuHeader( "EDIT PRODUCT" );

    int id = Get_ProductId();

    cout << endl << "Update which?" << endl;
    cout << "1. Update name" << endl;
    cout << "2. Update price" << endl;
    int choice = Get_IntBetweenRange( 1, 2 );

    // TODO: Store -- Get product, store name and price in these local variables

    string name = m_store.GetProductById(id).name;
    float price = m_store.GetProductById(id).price;

    if ( choice == 1 )
    {
        cout << "New product name: ";
        cin.ignore();
        getline( cin, name );
    }
    else if ( choice == 2 )
    {
        cout << "New product price: $";
        cin >> price;
    }

    try
    {
        m_store.UpdateProduct(id, name, price);
    }
    catch( const ProductNotFoundException& ex )
    {
        cout << "** ERROR: " << ex.what() << endl;
        return;
    }

    cout << endl << "Product updated." << endl;
    HitEnterToContinue();
}

void Program::Menu_RemoveProduct() noexcept
{
    ClearScreen();
    DisplayMenuHeader( "REMOVE PRODUCT FROM STORE" );

    int id = Get_ProductId();

    try
    {
        m_store.RemoveProduct(id);
    }
    catch( const ProductNotFoundException& ex )
    {
        cout << "** ERROR: " << ex.what() << endl;
        return;
    }

    cout << endl << "Product updated." << endl;
    HitEnterToContinue();
}

void Program::Menu_Checkout() noexcept
{
    ClearScreen();
    DisplayMenuHeader( "CHECKOUT" );

    DisplayYourCart();

    // TODO: Shopping cart -- get total cost
    float totalCost = m_shoppingCart.GetTotalCost();
    const float TAX = 0.091;                                // OP KS tax rate is 9.1%
    float pricePlusTax = totalCost + ( totalCost * TAX );

    cout << endl << endl;
    cout << "Subtotal..... $" << fixed << setprecision( 2 ) << totalCost << endl;
    cout << "Tax rate..... " << ( TAX * 100 ) << "%" << endl;
    cout << "Total due.... $" << fixed << setprecision( 2 ) << pricePlusTax << endl;

    cout << endl << "Thank you for shopping with us!" << endl;
    HitEnterToContinue();
}

void Program::Menu_AddProductToCart() noexcept
{
    ClearScreen();
    DisplayMenuHeader( "ADD PRODUCT TO CART" );

    int id = Get_ProductId();

    // TODO: Store -- Get product by id
    // TODO: Shopping cart -- add product to cart
    m_shoppingCart.AddToCart(m_store.GetProductById(id));

    cout << endl << "Product added to cart." << endl;
    HitEnterToContinue();
}

void Program::Menu_RemoveProductFromCart() noexcept
{
    ClearScreen();
    DisplayMenuHeader( "REMOVE PRODUCT FROM CART" );

    DisplayYourCart();
    // TODO: Shopping cart -- get item count
    int index = Get_IntBetweenRange( 1, m_shoppingCart.GetItemCount() ) - 1;

    m_shoppingCart.RemoveFromCart(index);

    // TODO: Shopping cart -- remove item from cart

    cout << endl << "Product removed from cart." << endl;
    HitEnterToContinue();
}

void Program::ClearScreen() const noexcept
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Program::DisplayMenuHeader( const string& text ) const noexcept
{
    cout << string( 80, '-' ) << endl << text << endl;
}

void Program::HitEnterToContinue() const noexcept
{
    cout << "Hit ENTER to continue." << endl;
    cin.ignore();
    string blah;
    getline( cin, blah );
}


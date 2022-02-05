#include "ZombieGame.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void ZombieGame::Setup()
{
    srand( time( NULL ) );

    cout << "Z O M B I E  -  A P O C A L Y P S E" << endl;
    cout << "Enter your name: ";
    getline( cin, m_name );

    m_day = 1;
    m_food = 5;
    m_maxHealth = 100;
    m_health = m_maxHealth;
    m_location = "Overland Park";
    m_done = false;
}

void ZombieGame::Run()
{
    Setup();

    // Game loop
    while ( !m_done )
    {
        Menu_Main();
    }
}

int ZombieGame::GetValidInput( int min, int max )
{
    cout << "CHOICE (" << min << "-" << max << "): ";
    int choice;
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "INVALID SELECTION. TRY AGAIN: ";
        cin >> choice;
    }

    return choice;
}

void ZombieGame::Menu_Main()
{
    DisplayStats();
    int choice = GetValidInput( 1, 2 );

    switch( choice )
    {
        case 1: Menu_Scavenge();    break;
        case 2: Menu_Move();        break;
    }

    cout << endl << "Press ENTER to continue...";
    cin.ignore();
    string dump;
    getline( cin, dump );

    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
}

void ZombieGame::Menu_Scavenge()
{
    cout << "* You scavenge here." << endl;
    // Random event occurring
    int randomChance = rand() % 5;
    int mod;
    if ( randomChance == 0 )
    {
        mod = rand() % 3 + 2;
        cout << "* You find a stash of food. (+" << mod << " food)" << endl;
        m_food += mod;
    }
    else if ( randomChance == 1 )
    {
        mod = rand() % 8 + 2;
        cout << "* A zombie surprises you!" << endl;
        cout << "* You get hurt in the encounter. (-" << mod << " health)" << endl;
        m_health -= mod;
    }
    else if ( randomChance == 2 )
    {
        mod = rand() % 3 + 2;
        cout << "* You find some medical supplies. (+" << mod << " health)" << endl;
        m_health += mod;
    }
    else if ( randomChance == 3 )
    {
        mod = rand() % 4 + 2;
        cout << "* Another scavenger ambushes you!" << endl;
        cout << "* They take some supplies from you. (-" << mod << " food)" << endl;
        m_food -= mod;
    }
    else if ( randomChance == 4 )
    {
        cout << "* You don't find anything." << endl;
    }
}

void ZombieGame::Menu_Move()
{
    bool moved = false;

    while ( !moved )
    {
        cout << "Walk to where?" << endl;
        cout << "1. Overland Park" << endl;
        cout << "2. Raytown" << endl;
        cout << "3. Kansas City" << endl;
        cout << "4. Gladstone" << endl;

        int choice = GetValidInput( 1, 4 );

        if ( choice == 1 )
        {
            if ( m_location == "Overland Park" )
            {
                cout << "You're already there!" << endl << endl;
            }
            else
            {
                m_location = "Overland Park";
                moved = true;
            }
        }
        else if ( choice == 2 )
        {
            if ( m_location == "Raytown" )
            {
                cout << "You're already there!" << endl << endl;
            }
            else
            {
                m_location = "Raytown";
                moved = true;
            }
        }
        else if ( choice == 3 )
        {
            if ( m_location == "Kansas City" )
            {
                cout << "You're already there!" << endl << endl;
            }
            else
            {
                m_location = "Kansas City";
                moved = true;
            }
        }
        else if ( choice == 4 )
        {
            if ( m_location == "Gladstone" )
            {
                cout << "You're already there!" << endl << endl;
            }
            else
            {
                m_location = "Gladstone";
                moved = true;
            }
        }
        else
        {
            cout << "Invalid selection!" << endl << endl;
        }
    }

    cout << endl << "* You travel to " << m_location << "." << endl;

    // Random event occurring
    int randomChance = rand() % 5;
    if ( randomChance == 0 )
    {
        cout << "* A zombie attacks!" << endl;
        cout << "* You fight it off." << endl;
    }
    else if ( randomChance == 1 )
    {
        int mod = rand() % 8 + 2;
        cout << "* A zombie attacks!" << endl;
        cout << "* It bites you as you fight it! (-" << mod << " health)" << endl;
        m_health -= mod;
    }
    else if ( randomChance == 2 )
    {
        int mod = rand() % 3 + 2;
        cout << "* You find another scavenger and trade goods. (+" << mod << " food)" << endl;
        m_food += mod;
    }
    else if ( randomChance == 3 )
    {
        int mod = rand() % 4 + 2;
        cout << "* You find a safe building to rest in temporarily. (+" << mod << " health)" << endl;
        m_health += mod;
    }
    else if ( randomChance == 4 )
    {
        cout << "* The journey is uneventful." << endl;
    }
}

void ZombieGame::Menu_EndOfDay()
{
    cout << "* The day passes (+1 day)." << endl;
    m_day++;

    if ( m_food > 0 )
    {
        cout << "* You eat a meal (-1 food)." << endl;
        m_food--;
        m_health++;
    }
    else
    {
        int mod = rand() % 4 + 1;
        cout << "* You are starving! (-" << mod << " health)" << endl;
        m_health -= mod;
    }

    // Check for special states
    if ( m_health > m_maxHealth )
    {
        m_health = m_maxHealth;
    }

    if ( m_food <= 0 )
    {
        m_food = 0;
    }

    if ( m_health <= 0 )
    {
        cout << "* You have died." << endl;
        m_done = true;
    }
    else if ( m_day >= 20 )
    {
        cout << endl;
        cout << "In the morning, a group of scavengers find you." << endl;
        cout << "They have a fortification nearby and are rebuilding a society." << endl;
        cout << endl << "You agree to live in their town." << endl;
        m_done = true;
    }

}

void ZombieGame::DisplayStats()
{
    cout << "----------------------------------------" << endl;
    cout << left << setw( 3 ) << "-- " << setw( 35 ) << m_name << "--" << endl;
    cout << left
        << setw( 6 ) << "-- Day "   << setw( 4 ) << m_day
        << setw( 6 ) << "Food: "    << setw( 4 ) << m_food
        << setw( 8 ) << "Health: "  << setw( 2 ) << m_health << setw( 1 ) << "/" << setw( 2 ) << m_maxHealth
        << right << setw( 6 ) << "--" << endl;
    cout << left
        << setw( 10 ) << "-- Location: " << setw( 20 ) << m_location
        << right << setw( 7 ) << "--" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-- 1. Scavenge here                   --" << endl;
    cout << "-- 2. Travel elseware                 --" << endl;
    cout << "----------------------------------------" << endl;
    for ( int i = 0; i < 15; i++ )
    {
        cout << endl;
    }
}






#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void DisplayMenu( int day, int food, int health, int maxHealth, string name, string location );

int main()
{
    // Init variables
    bool done = false;
    bool successfulAction = false;
    int food = 5;
    int mod;
    string name = "ME";
    string location = "Overland Park";
    string dump;
    int maxHealth = 20;
    int health = maxHealth;
    int day = 1;
    int choice;
    srand( time( NULL ) );

    // Game start
    cout << "Z O M B I E  -  A P O C A L Y P S E" << endl;
    cout << "Enter your name: ";
    getline( cin, name );

    cout << endl;

    // Game loop
    while ( !done )
    {
        successfulAction = false;
        DisplayMenu( day, food, health, maxHealth, name, location );
        cout << "CHOICE: ";
        cin >> choice;

        cout << endl;
        if ( choice == 1 )          // Scavenge
        {
            successfulAction = true;
            cout << "* You scavenge here." << endl;
            // Random event occurring
            int randomChance = rand() % 5;
            if ( randomChance == 0 )
            {
                mod = rand() % 3 + 2;
                cout << "* You find a stash of food. (+" << mod << " food)" << endl;
                food += mod;
            }
            else if ( randomChance == 1 )
            {
                mod = rand() % 8 + 2;
                cout << "* A zombie surprises you!" << endl;
                cout << "* You get hurt in the encounter. (-" << mod << " health)" << endl;
                health -= mod;
            }
            else if ( randomChance == 2 )
            {
                mod = rand() % 3 + 2;
                cout << "* You find some medical supplies. (+" << mod << " health)" << endl;
                health += mod;
            }
            else if ( randomChance == 3 )
            {
                mod = rand() % 4 + 2;
                cout << "* Another scavenger ambushes you!" << endl;
                cout << "* They take some supplies from you. (-" << mod << " food)" << endl;
                food -= mod;
            }
            else if ( randomChance == 4 )
            {
                cout << "* You don't find anything." << endl;
            }
        }


        else if ( choice == 2 )     // Move
        {
            cout << "Walk to where?" << endl;
            cout << "1. Overland Park" << endl;
            cout << "2. Raytown" << endl;
            cout << "3. Kansas City" << endl;
            cout << "4. Gladstone" << endl;

            cout << endl << "CHOICE: ";
            cin >> choice;

            bool moved = false;

            if ( choice == 1 )
            {
                if ( location == "Overland Park" )
                {
                    cout << "You're already there!" << endl;
                }
                else
                {
                    location = "Overland Park";
                    moved = true;
                }
            }
            else if ( choice == 2 )
            {
                if ( location == "Raytown" )
                {
                    cout << "You're already there!" << endl;
                }
                else
                {
                    location = "Raytown";
                    moved = true;
                }
            }
            else if ( choice == 3 )
            {
                if ( location == "Kansas City" )
                {
                    cout << "You're already there!" << endl;
                }
                else
                {
                    location = "Kansas City";
                    moved = true;
                }
            }
            else if ( choice == 4 )
            {
                if ( location == "Gladstone" )
                {
                    cout << "You're already there!" << endl;
                }
                else
                {
                    location = "Gladstone";
                    moved = true;
                }
            }
            else
            {
                cout << "Invalid selection!" << endl;
            }

            if ( moved )
            {
                successfulAction = true;
                cout << endl << "* You travel to " << location << "." << endl;
                // Random event occurring
                int randomChance = rand() % 5;
                if ( randomChance == 0 )
                {
                    cout << "* A zombie attacks!" << endl;
                    cout << "* You fight it off." << endl;
                }
                else if ( randomChance == 1 )
                {
                    mod = rand() % 8 + 2;
                    cout << "* A zombie attacks!" << endl;
                    cout << "* It bites you as you fight it! (-" << mod << " health)" << endl;
                    health -= mod;
                }
                else if ( randomChance == 2 )
                {
                    mod = rand() % 3 + 2;
                    cout << "* You find another scavenger and trade goods. (+" << mod << " food)" << endl;
                    food += mod;
                }
                else if ( randomChance == 3 )
                {
                    mod = rand() % 4 + 2;
                    cout << "* You find a safe building to rest in temporarily. (+" << mod << " health)" << endl;
                    health += mod;
                }
                else if ( randomChance == 4 )
                {
                    cout << "* The journey is uneventful." << endl;
                }

            }
        }
        else
        {
            cout << "Invalid choice" << endl;
        }

        if ( !successfulAction )
        {
            continue;
        }





        cout << "* The day passes (+1 day)." << endl;
        day++;

        if ( food > 0 )
        {
            cout << "* You eat a meal (-1 food)." << endl;
            food--;
            health++;
        }
        else
        {
            mod = rand() % 4 + 1;
            cout << "* You are starving! (-" << mod << " health)" << endl;
            health -= mod;
        }

        // Check for special states
        if ( health > maxHealth )
        {
            health = maxHealth;
        }

        if ( food <= 0 )
        {
            food = 0;
        }

        if ( health <= 0 )
        {
            cout << "* You have died." << endl;
            done = true;
        }
        else if ( day >= 20 )
        {
            cout << endl;
            cout << "In the morning, a group of scavengers find you." << endl;
            cout << "They have a fortification nearby and are rebuilding a society." << endl;
            cout << endl << "You agree to live in their town." << endl;
            done = true;
        }


        cout << endl << "Press ENTER to continue...";
        cin.ignore();
        getline( cin, dump );

        cout << "----------------------------------------" << endl;
        cout << "----------------------------------------" << endl;
    }

    cout << endl << endl << "You survived the apocalpyse on your own for " << day << " days." << endl;

    return 0;
}

void DisplayMenu( int day, int food, int health, int maxHealth, string name, string location )
{
    cout << "----------------------------------------" << endl;
    cout << left << setw( 3 ) << "-- " << setw( 35 ) << name << "--" << endl;
    cout << left
        << setw( 6 ) << "-- Day "   << setw( 4 ) << day
        << setw( 6 ) << "Food: "    << setw( 4 ) << food
        << setw( 8 ) << "Health: "  << setw( 2 ) << health << setw( 1 ) << "/" << setw( 2 ) << maxHealth
        << right << setw( 6 ) << "--" << endl;
    cout << left
        << setw( 10 ) << "-- Location: " << setw( 20 ) << location
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

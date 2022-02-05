#ifndef _ZOMBIE_GAME_H
#define _ZOMBIE_GAME_H

#include <string>
using namespace std;

class ZombieGame
{
public:
    void Setup();
    void Run();
    void DisplayStats();
    void Menu_Main();
    void Menu_Scavenge();
    void Menu_Move();
    void Menu_EndOfDay();

private:
    int m_day;
    int m_food;
    int m_maxHealth;
    int m_health;
    string m_location;
    string m_name;
    bool m_done;

    int GetValidInput( int min, int max );
};

#endif // _ZOMBIE_GAME_H

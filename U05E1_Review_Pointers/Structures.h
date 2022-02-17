#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include <memory>
#include <string>
#include <iostream>
using namespace std;

struct Employee
{
    string name;
    float payPerHour;

    Employee( string n, float pph )
    {
        name = n;
        payPerHour = pph;
    }

    void Display()
    {
        cout << name << ", $" << payPerHour << "/hr" << endl;
    }
};

struct Node
{
    Node()
    {
        ptrNext = nullptr;
    }

    Node( string value )
    {
        data = value;
        ptrNext = nullptr;
    }

    Node* ptrNext;
    string data;
};

struct SmartNode
{
    SmartNode()
    {
    }

    SmartNode( string value )
    {
        data = value;
    }

    shared_ptr<SmartNode> ptrNext;
    string data;
};

struct Zone
{
    Zone()
    {
    }

    Zone( string value )
    {
        name = value;
    }

    string name;
    shared_ptr<Zone> ptrToEast;
    shared_ptr<Zone> ptrToWest;
    shared_ptr<Zone> ptrToNorth;
    shared_ptr<Zone> ptrToSouth;
};

#endif

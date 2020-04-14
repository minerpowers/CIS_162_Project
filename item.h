#ifndef ITEM_H
#define ITEM_H

#include<iostream>
#include<string>
using namespace std;

class Item{
private:
    string name;

public:
    Item(){name = " ";}
    void setName(string n){name = n;}
    string getName(){return name;}
};

#endif // ITEM_H

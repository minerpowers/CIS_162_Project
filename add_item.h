#ifndef ADD_ITEM_H
#define ADD_ITEM_H
//#include"database.h"
#include"Item.h"
#include<vector>


/***************************************************************
* Name        : add_item.h
* Author      : Ben Miner
* Created     : March 2020
* Description : Function for adding a new item and
*               Function for promting and editing Item
*               member variables
***************************************************************/
// prototypes
void itemName(Item&);
void itemCategory(Item&);
void itemAisle(Item&);
void itemLoc(Item&);

/**************************************************************
* Name: newItem
* Description: primary function for creating a new item
* Input: list of Items passed by referance
* Output: none
***************************************************************/
Item newItem(){
    Item items;
    itemName(items);
    itemCategory(items);
    itemAisle(items);
    itemLoc(items);
    return items;
}
/**************************************************************
* Name: itemName
* Description: prompt the user to set the name member of an Item
* Input: Item passed by referance
* Output: none
***************************************************************/
void itemName(Item &x){
    string name;
    cout << "What is the Item?\n"
         <<"Enter Item name:\t";
    cin >> name;
    x.setName(name);
    return;
}
/**************************************************************
* Name: itemCategory
* Description: prompt the user to set type member of an Item
* Input: Item passed by referance
* Output: none
***************************************************************/
void itemCategory(Item &x){
    string category;
    int choice;
    do{
        cout << "What type of item is it?\n"
             <<"1: produce\n"
             <<"2: Deli\n"
             <<"3: Dry Goods\n"
             <<"4: Dairy\n"
             <<"5: frozen\n"
             << "Enter category\t";
        cin >> choice;
        switch (choice) {
        case 1: x.setCategory("Produce");
            break;
        case 2: x.setCategory("Deli");
            break;
        case 3: x.setCategory("Dry Goods");
            break;
        case 4: x.setCategory("Dairy");
            break;
        case 5: x.setCategory("Frozen");
            break;
        default: cout<<"invalid choice\n";
        }
    }while(!isnumber(choice) && (choice<1 || choice>5));

    return;
}
/**************************************************************
* Name: itemAisle
* Description: prompt the user to set aisle member of an Item
* Input: Item passed by referance
* Output: none
***************************************************************/
void itemAisle(Item &x){
    int aisle;
    do{
        cout << "What Aisle is it in?\n";
        cin >> aisle;
    }while(aisle < 0 || aisle > 150);
    x.setAisle(aisle);
    return;
}
/**************************************************************
* Name: itemLoc
* Description: prompt the user to set ailseLoc member of an Item
* Input: Item passed by referance
* Output: none
***************************************************************/
void itemLoc(Item &x){
    int loc;
    do {
        cout << "About where in the aisle is it?\n"
             << "1: Front third\n"
             << "2: Middle third\n"
             << "3: Back third\n";
        cin >> loc;
    } while (loc < 1 || loc > 3);
    x.setAisleLoc(loc);
    return;
}
#endif // ADD_ITEM_H

/**************************************************************
* Name        : Project Name
* Author      : Ben Miner
* Created     : Spring 2020
* Course      : CIS 152, CIS 164
* Version     : 1.0
* OS          : Mac OSX
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : This program overall description here
*               Input:  list and describe
*               Output: list and describe
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include "add_item.h"
#include"database.h"
#include"Item.h"
#include"ShopList.h"
#include"makeShopList.h"
#include<vector>

void menu_addItem();                // cunction to call add_item.h
void print_ShopList(ShopList&);     // functio to print the shopping list
//void testData();
DbManager db;
int main()
{

    ShopList shoppingList;
    vector<Item> allItems;
    //testData();
    try {
        allItems = db.getItem();
    } catch (string error) {
        cout<< error;
    }
    int choice;
    do{
        choice=0;
        cout<<"What do you want to do?\n"
            <<"\t1: Make a shopping list\n"
            <<"\t2: Add new item\n"
            <<"\t3: Print shopping list\n"
            <<"\t4: Exit Program\n"
            <<"Enter Number\t";
        cin>>choice;
        switch (choice) {
        case 1: makeList(allItems,shoppingList,0);
            break;
        case 2: menu_addItem();
            break;
        case 3: print_ShopList(shoppingList);
            break;
        case 4: break;
        default: cout<<"Invalid input\n";
            break;
        }
    }while(choice!=4);
     return 0;
}

void menu_addItem(){
    Item item = newItem();
    try {
        db.addItem(item);
    } catch (string err) {
        cout << err;
    }
    int choice;
    do{

        cout<<"Do you want to add another item?\n"
           <<"1: Yes\n"
          <<"2: No\n"
         <<"Enter 1 or 2\t";
        cin>>choice;
        switch (choice) {
        case 1: item = newItem();
            try {
                db.addItem(item);
            } catch (string err) {
                    cout << err;
            }
            break;
        case 2: return;
        default:cout<<"Invalid input\n";
        }
    }while(choice==1);
    return;
}

void print_ShopList(ShopList &list){
    if (!list.isEmpty()){
        cout<<"aisle "<<" category "<<" item "<<endl;
            list.PrintList();
    }
}
/* data for testing
void testData(){
    Item apple("apple","Produce",0,1);
    Item banana("banana","Produce",0,1);
    Item milk("milk","Dairy",26,3);
    Item icecream("icecream","Frozen",22,2);
    Item froDin("frozen Dinners","Frozen",20,1);
    Item PB("Peanut Butter","Dry Goods",2,1);
    Item bread("bread","Dry Goods",1,2);
    Item slCh("sliced cheese","Deli",0,1);
    Item flour("flour","Dry Goods",8,1);
    Item sugar("sugar","Dry Goods",8,3);
    Item life("life ceareal","Dry Goods",10,2);
    Item loops("fruit loops","Dry Goods",10,3);
    Item chex("chex","Dry Goods",10,1);
    Item yog("yogurt","Dairy",24,1);
    db.addItem(apple);
    db.addItem(banana);
    db.addItem(milk);
    db.addItem(icecream);
    db.addItem(froDin);
    db.addItem(PB);
    db.addItem(bread);
    db.addItem(slCh);
    db.addItem(flour);
    db.addItem(sugar);
    db.addItem(life);
    db.addItem(life);
    db.addItem(loops);
    db.addItem(chex);
    db.addItem(yog);
    return;
}*/

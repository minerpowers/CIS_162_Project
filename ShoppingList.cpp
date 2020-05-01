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

void menu_addItem(vector<Item>&);
void print_ShopList(ShopList&);
void testData(vector<Item>&);
int main()
{
    ShopList shoppingList;
    vector<Item> allItems;
    testData(allItems);
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
        case 2: menu_addItem(allItems);
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

void menu_addItem(vector<Item> &items){
    items.push_back(newItem());
    int choice;
    do{

        cout<<"Do you want to add another item?\n"
           <<"1: Yes\n"
          <<"2: No\n"
         <<"Enter 1 or 2\t";
        cin>>choice;
        switch (choice) {
        case 1: items.push_back(newItem());
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
// data for testing
void testData(vector<Item> &items){
    Item apple("apple","Produce",0,1);
    items.push_back(apple);
    Item banana("banana","Produce",0,1);
    items.push_back(banana);
    Item milk("milk","Dairy",26,3);
    items.push_back(milk);
    Item icecream("icecream","Frozen",22,2);
    items.push_back(icecream);
    Item froDin("frozen Dinners","Frozen",20,1);
    items.push_back(froDin);
    Item PB("Peanut Butter","Dry Goods",2,1);
    items.push_back(PB);
    Item bread("bread","Dry Goods",1,2);
    items.push_back(bread);
    Item slCh("sliced cheese","Deli",0,1);
    items.push_back(slCh);
    Item flour("flour","Dry Goods",8,1);
    items.push_back(flour);
    Item sugar("sugar","Dry Goods",8,3);
    items.push_back(sugar);
    Item life("life ceareal","Dry Goods",10,2);
    items.push_back(life);
    Item loops("fruit loops","Dry Goods",10,3);
    items.push_back(loops);
    Item chex("chex","Dry Goods",10,1);
    items.push_back(chex);
    Item yog("yogurt","Dairy",24,1);
    items.push_back(yog);
    return;
}

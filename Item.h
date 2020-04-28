#ifndef ITEM_H
#define ITEM_H
/***************************************************************
* Name        : Item
* Author      : Ben Miner
* Created     : March 2020
***************************************************************/
#include<iostream>
#include<string>
using namespace std;

class Item{
private:
    string name;            //name of the item
    string category;        //type of item (produce, dry goods, frozen)
    int aisle;              //store aisle number of the item
    int aisleLoc;           //prioritize aisle 1 front to 5 back
public:
    /***************************************************************
    * Class Functions
    ***************************************************************/
    /**************************************************************
    * Setter Funtion
    * Description: set class varible members
    * Input: string name, type
    *        int aisle, aisleLoc
    * Output: none
    ***************************************************************/
    void setName(string n){name = n;}
    void setCategory(string t){category = t;}
    void setAisle(int a){aisle = a;}
    void setAisleLoc(int l){aisleLoc = l;}
    /**************************************************************
    * Gettrer Function
    * Description: get class variable members
    * Input: none
    * Output: string name, type
    *         int aisle, aisleLoc
    ***************************************************************/
    string getName(){return name;}
    string getCategory(){return category;}
    int getAisle(){return aisle;}
    int getAisleLoc(){return aisleLoc;}

    void printItem(){
        cout << name<<"\t"
             << category<<"\t"
             << aisle<<"\t"
             << aisleLoc<<endl;
        return;
    }
    bool operator<(const Item &second){
        if (aisle<second.aisle){
            return true;
        }
        else if(aisle==second.aisle && aisleLoc<second.aisleLoc){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator==(const Item &item2){
        if( aisle==item2.aisle){
            return true;
        }
        else{return false;}
    }
};
#endif // ITEM_H

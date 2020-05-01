/***************************************************************
* Name        : ShopList
* Author      : Ben Miner
* Created     : April 2020
***************************************************************/
#ifndef SHOPLIST_H
#define SHOPLIST_H
#include"Item.h"
#include<vector>
#include<iterator>

class ShopList{
private:
    vector<Item> listVector;
public:
    ShopList(){}
    /**************************************************************
    * Name: enqueu
    * Description: add item to the back of shopList
    * Input: Item object
    * Output: none
    ***************************************************************/
    void enqueu(Item item){
        listVector.push_back(item);
        selectSort();
    }
    /**************************************************************
    * Name: dequeu
    * Description: remove item from the front of shopList
    * Input: none
    * Output: none
    ***************************************************************/
    void dequeu(){
        if(listVector.empty()==true){
            string error = "Shpping list is empty\n";
            throw error;
        }
        listVector.erase(listVector.begin());
    }
    /**************************************************************
    * Name: size
    * Description: returns the sise of the shopList
    * Input: none
    * Output: int size
    ***************************************************************/
    int size(){
        int size = listVector.size();
        return size;
    }
    /**************************************************************
    * Name: sort
    * Description: sort the items of the shopList by aisle then aisleLoc
    * Input: none
    * Output: none
    ***************************************************************/
    void selectSort(){
        int i, j, minIndex;
        int size = listVector.size();
        for (i=0; i < size; i++){
            minIndex = i;
            for (j=i+1; j < size; j++){
                if(listVector[j]<listVector[minIndex]){
                    minIndex = j;
                    Item temp=listVector[minIndex];
                    listVector[minIndex]=listVector[i];
                    listVector[i]=temp;
                }
            }
        }
    }
    /**************************************************************
    * Name: print
    * Description: print the items in the shopLost
    * Input: none
    * Output: disply items in a list
    ***************************************************************/
    void PrintList(){
        vector<Item>::iterator it;
        for (it=listVector.begin();it!=listVector.end();it++){
            it->printItem();
        }
    }
    bool isEmpty(){
        if(listVector.empty()==true){return true;}
        else{return false;}
    }
};

#endif // SHOPLIST_H

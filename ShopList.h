#ifndef SHOPLIST_H
#define SHOPLIST_H
#include"Item.h"
#include<vector>
#include<iterator>
//#include<algorithm>

class ShopList{
private:
    vector<Item> listVector;
public:
    ShopList(){
    }
    ~ShopList(){
    }
    void enqueu(Item item){
        listVector.push_back(item);
    }
    void dequeu(){
        if(listVector.empty()==true){
            throw "Shopping list is empty";
        }
        listVector.erase(listVector.begin());
    }
    int size(){
        int size = listVector.size();
        return size;
    }
    void sort(){
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
    void swap(Item *a, Item *b){
        Item temp = *a;
        *a = *b;
        *b = temp;
    }
    void PrintList(){
        vector<Item>::iterator it;
        for (it=listVector.begin();it!=listVector.end();it++){
            it->printItem();
        }
    }
};

#endif // SHOPLIST_H

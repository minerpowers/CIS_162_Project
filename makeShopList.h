/***************************************************************
* Name        : makeShopList
* Author      : Ben Miner
* Created     : April 2020
***************************************************************/
#ifndef MAKESHOPLIST_H
#define MAKESHOPLIST_H
#include"database.h"
#include"ShopList.h"
/**************************************************************
* Name: displayList
* Description: display 10 items from a vector to be used with
*               makeList switch
* Input: vector of Items, and int for shifting the list up and
*           down by 10
* Output: disply a list for user interface
***************************************************************/
void displayList(vector<Item> shoplist, int n){
    int count = 1;
    cout<<"What do you want to add\n";
    for(size_t i=n; (i<n+10)&&(i<shoplist.size()); i++){
        cout << count <<": "<<shoplist[i].getName()<<endl;
        count++;
    }
    cout << "11:  next"<<endl
         << "12:  back"<<endl
         << "13:  done"<<endl
         << "enter selection number"<<endl;
}
/**************************************************************
* Name: makeList
* Description: the main user interface for adding items to a
*               shopping list
* Input: vector of Item, ShopList, int n(for adjusting list by 10)
* Output: none (shopList is altered by reference)
***************************************************************/
void makeList(vector<Item> shoplist, ShopList &list,int n){
        int choice;
        int count;
        displayList(shoplist, n);
        do{
            count = 1;

            cin>>choice;
            switch (choice) {
            case 1: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 2: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 3:list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 4:list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 5: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 6: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 7: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 8: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 9:list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 10: list.enqueu(shoplist[choice-1+n]);
                cout<< "item added";
                break;
            case 11: displayList(shoplist,n+10);
                n=n+10;
                break;
            case 12: displayList(shoplist,n-10);
                n=n-10;
                break;
            case 13: break;
            default: cout<<"invalid choice\n";
                break;
            }
        } while(choice!=13);
        return;
}

#endif // MAKESHOPLIST_H

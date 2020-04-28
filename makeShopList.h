#ifndef MAKESHOPLIST_H
#define MAKESHOPLIST_H
#include"database.h"
#include"ShopList.h"
void makeList(vector<Item>,ShopList&,int);
ShopList newList(){
    ShopList list;
    cout<<"open dataBase\n";
    DbManager dataBase;
    vector<Item> DBitems;
    cout<<"call dataBase.getItems\n";
    DBitems = dataBase.getItem();
    vector<Item>::iterator it;
    cout<<"\nprint DBitems\n\n";
    for (it=DBitems.begin();it!=DBitems.end();it++){
        it->printItem();
    }
    cout<<"call makeList\n";
    makeList(DBitems,list,0);
    return list;
}
//create vector of items to build shopping list
void makeList(vector<Item> DBitems, ShopList &list,int n){
    cout<<"in makeList\n";
        int choice;
        int count = 1;
        int last = DBitems.size();
    cout<<"start for loop\n";
        for(int i=n; (i<10)||(i<last); i++){
            cout << count <<": "<<DBitems[i].getName()<<endl;
            count++;
        }
        cout << "11:  next"<<endl
             << "12:  back"<<endl
             << "13:  done"<<endl;
        cin >>choice;
        if (choice==11){
            makeList(DBitems,list,n+10);
        }
        else if (choice==12) {
            makeList(DBitems,list,n-10);
        }
        else if(choice==13){
            return;
        }
        while(choice<11){
            list.enqueu(DBitems[choice+1+n]);
            cout<< "item added";
        }
}

#endif // MAKESHOPLIST_H

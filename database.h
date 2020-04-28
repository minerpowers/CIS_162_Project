#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<vector>
#include"Item.h"

class DbManager{
private:
    QSqlDatabase dataBase;
    QString name, category, aisle, aisleLoc;
public:
    DbManager(){
        dataBase = QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("../src/Project.db");
        if(!dataBase.open()){
            qDebug()<<"Error: connecton with database failed";
            return;
        }
        else{
            qDebug()<<"Database: connection ok";
            return;
        }
    }
    void addItem(Item item){
        name=QString::fromStdString(item.getName());
        category=QString::fromStdString(item.getCategory());
        aisle=QString::number(item.getAisle());
        aisleLoc=QString::number(item.getAisleLoc());
        QSqlQuery query;
        query.prepare("INSERT INTO Produce_item(name, category, aisle, aisleLoc) "
                      "VALUES (:name, :category, :aisle, :aisleLoc)");
        query.bindValue(":name", name);
        query.bindValue(":category", category);
        query.bindValue(":aisle", aisle);
        query.bindValue(":aisleLoc", aisleLoc);
        query.exec();
    }
    bool dataExists(Item item){
        name=QString::fromStdString(item.getName());
        QSqlQuery query("SELECT name FROM Produce_item WHERE name =(:name)");
        query.bindValue(":name", name);
        if(query.exec()){
            if(query.next()){
                return true;
            }
        }
        return false;
    }

    bool isOpen(){
        if(dataBase.isOpen()){
            return true;
        }
        return false;
    }
    vector<Item> getItem(){
        Item item;
        vector<Item> itemVec;
        QSqlQuery query;
                query.prepare("SELECT * FROM Produce_item");
        while(query.next()){
            QString name =query.value("name").toString();
            QString category= query.value("category").toString();
            QString aisle = query.value("aisle").toString();
            QString aisleLoc = query.value("aisleLoc").toString();
            item.setName(name.toStdString());
            item.setCategory(category.toStdString());
            item.setAisle(aisle.split(" ")[0].toInt());
            item.setAisleLoc(aisle.split(" ")[0].toInt());
            itemVec.push_back(item);
        }
        query.exec();
        return itemVec;
    }
};

#endif // DATABASE_H

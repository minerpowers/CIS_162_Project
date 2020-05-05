/***************************************************************
* Name        : DbManager
* Author      : Ben Miner
* Created     : April 2020
***************************************************************/
#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include<QSqlDriver>
#include<QSqlError>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<vector>
#include"Item.h"

class DbManager{
private:
    QSqlDatabase dataBase;
public:
    /**************************************************************
    * Name: DbManager
    * Description: set database name and open
    * Input parameters: none
    ***************************************************************/
    DbManager(){
        dataBase = QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("../src/Project.db");
        if(!dataBase.open()){
            qDebug()<<"Error: connecton with database failed";
            return;
        }
        else{
            qDebug()<<"Database: connection ok";
            QSqlQuery query;
            query.prepare("CREATE TABLE IF NOT EXISTS items (name VARCHAR(30), category VARCHAR(30), aisle INTEGER, aisleLoc INTEGER)");
            if(!query.exec()){
                qDebug() << query.lastError();
            }
            else{
                qDebug() << "Table Created";
            }
        }
    }
    /**************************************************************
     * Name: ~DbManager
     * Description: deconstructor close database
     * Input parameters: none
     ***************************************************************/
    ~DbManager(){
        dataBase.close();
    }
    /***************************************************************
    * Class Functions
    ***************************************************************/
    /**************************************************************
    * Name: addItem
    * Description: add an object to the database
    * Input: Item
    * Output: none
    ***************************************************************/
    void addItem(Item item){
        if (isOpen()){
            if(dataExists(item.getName())){
                string error = "items areety exists\n";
                throw error;
            }
            else{
                QString name=QString::fromStdString(item.getName());
                QString category=QString::fromStdString(item.getCategory());
                QString aisle=QString::number(item.getAisle());
                QString aisleLoc=QString::number(item.getAisleLoc());
                QSqlQuery query;
                query.prepare("INSERT INTO Items(name, category, aisle, aisleLoc) VALUES (:name, :category, :aisle, :aisleLoc)");
                query.bindValue(":name", name);
                query.bindValue(":category", category);
                query.bindValue(":aisle", aisle);
                query.bindValue(":aisleLoc", aisleLoc);
                query.exec();
                qDebug()<< "Item added\n";
            }
        }
        else{
            string error = "no conection to database\n\n";
            throw error;
        }
    }
    /**************************************************************
    * Name: dataExists
    * Description: check if a record exists by compairing the object
    *               name member
    * Input: string
    * Output: bool
    ***************************************************************/
    bool dataExists(string item){
        bool exists = false;
        QString name=QString::fromStdString(item);
        QSqlQuery query;
        query.prepare("SELECT name FROM Items WHERE name =(:name)");
        query.bindValue(":name",name);
        if(query.exec()){
            if(query.next()){
                exists = true;
            }
        }
        return exists;
    }
    /**************************************************************
    * Name: isOpen
    * Description: check of the database is open
    * Input: none
    * Output: bool true if open
    ***************************************************************/
    bool isOpen(){
        if(dataBase.isOpen()){
            return true;
        }
        return false;
    }
    /**************************************************************
    * Name: getItem
    * Description: copy data from data base to a vector
    * Input: none
    * Output: vector of Items
    ***************************************************************/
    vector<Item> getItem(){
        vector<Item> itemVec;
        if (isOpen()){
            Item item;
            QSqlQuery query;
            query.exec("SELECT name, category, aisle, aisleLoc FROM Items");
            while(query.next()){
                QString name = query.value(0).toString();
                QString category= query.value(1).toString();
                int aisle = query.value(2).toInt();
                int aisleLoc = query.value(3).toInt();
                qDebug()<<name<<category<<aisle<<aisleLoc;
                item.setName(name.toStdString());
                item.setCategory(category.toStdString());
                item.setAisle(aisle);
                item.setAisleLoc(aisleLoc);
                itemVec.push_back(item);
            }
        }
        else{
            string error = "no conection to database\n\n";
            throw error;
        }
        return itemVec;
    }

};

#endif // DATABASE_H

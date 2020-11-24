#pragma once
#include<iostream>
#include <stdlib.h>
#include <iomanip> 
#include<regex>
#include<string>
using namespace std;

enum class CRUD
{
    SHOW = 1,
    ADD,
    UPDATE,
    DELETE,
    BACK
};


class CRUDManagementModel
{
protected:
    string categoryName;
public:
    CRUDManagementModel(/* args */);
    ~CRUDManagementModel();

    void run();
    virtual bool addItem();
    virtual void showItemList();
    virtual bool updateItem();
    virtual bool deleteItem();

};



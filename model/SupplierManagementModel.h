#pragma once
#include <iostream>
#include "CRUDManagementModel.h"
#include"../dataaccess/SuppliersData.h"
using namespace std;

#define filename "RawDatas/Suppliers.txt"
class SupplierManagementModel : public CRUDManagementModel
{
private:
    SuppliersData *suppliersData;
public:
    static SupplierManagementModel *instance;

public:
    static SupplierManagementModel *getInstance();
    SupplierManagementModel(/* args */);
    ~SupplierManagementModel();

    bool addItem();
    void showItemList();
    bool updateItem();
    bool deleteItem();
};

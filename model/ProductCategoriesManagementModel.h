#pragma once
#include "CRUDManagementModel.h"
#include "../dataaccess/CategoriesData.h"

class ProductCategoriesManagementModel : public CRUDManagementModel
{
private:
    CategoriesData *categoriesData;
public:
    static ProductCategoriesManagementModel *instance;

public:
    static ProductCategoriesManagementModel *getInstance();
    ProductCategoriesManagementModel(/* args */);
    ~ProductCategoriesManagementModel();
    bool addItem();
    void showItemList();
    bool updateItem();
    bool deleteItem();
};
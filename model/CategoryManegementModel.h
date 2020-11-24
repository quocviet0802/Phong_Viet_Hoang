#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "../dataaccess/SuppliersData.h"
#include "SupplierManagementModel.h"
#include "ProductCategoriesManagementModel.h"
#include "TableManagementModel.h"
#include <regex>
using namespace std;

enum class CATEGORY_FUNCTION
{
    SUPPLIER_MANAGEMENT = 1,
    CATEGORIES_MANAGEMENT,
    SHOW_LIST,
    BACK
};

class CategoryManegementModel
{
private:
    /* data */

public:
    static CategoryManegementModel *instance;
    SupplierManagementModel *supplierManagementModel;
    ProductCategoriesManagementModel *productCategoriesManagementModel;

public:
    static CategoryManegementModel *getInstance();
    void run();
    CategoryManegementModel(/* args */);
    ~CategoryManegementModel();

private:
};

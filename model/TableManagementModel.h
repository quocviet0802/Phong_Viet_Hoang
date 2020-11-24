#pragma once
#include<iostream>
#include"../dataaccess/CustomersData.h"
#include"../dataaccess/CategoriesData.h"
#include"../dataaccess/EmployeesData.h"
#include"../dataaccess/OrdersData.h"
#include"../dataaccess/OrderDetailsData.h"
#include"../dataaccess/ProductsData.h"
#include"../dataaccess/ShippersData.h"
#include"../dataaccess/SuppliersData.h"
#include <iomanip> 
using namespace std;

enum class TABLE
{
    CUSTOMER = 1,
    CATEGORY,
    EMPLOYEE,
    ORDERDETAIL,
    ORDER,
    PRODUCT,
    SHIPPER,
    SUPPLIER,
    BACK
};


class TableManagementModel
{
private:
    /* data */
public:
    TableManagementModel(/* args */);
    ~TableManagementModel();
    void run();
};


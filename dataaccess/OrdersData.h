/** @file OrdersData.h
 *  @brief OrdersData stores all Order objects
 *  
 *  @author Phi Nguyen Viet
 *  @bug No known bugs.
 */

#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<vector>
#include"../businessobjects/Order.h"
using namespace std;

// #define PATH_FILE "RawDatas/OrdersData_csv.csv"

class OrdersData
{
public: 
    static OrdersData *instance;
private:
    vector<Order> OrderList;
    int maxID;
public:
    
    static OrdersData *getInstance();
    OrdersData(/* args */);
    ~OrdersData();

    bool importDataFromCSVFile();
    bool importDataFromJsonFile();
    bool exportDataToFile();
    Order* getOrderByID(int OrderID);
    int createOrder(int CustomerID,int EmployeeID,string OrderDate,int ShipperID);
    bool updateOrder(int OrderID,int CustomerID,int EmployeeID,string OrderDate,int ShipperID);
    bool deleteOrder(int OrderID);
    vector<Order> getOrderList();

    void printAll();
};

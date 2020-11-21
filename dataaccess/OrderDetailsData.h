#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<vector>
#include"../businessobjects/OrderDetails.h"
using namespace std;

// #define PATH_FILE "RawDatas/OrderDetailsData_csv.csv"

class OrderDetailsData
{
public: 
    static OrderDetailsData *instance;
private:
    vector<OrderDetails> OrderDetailsList;
    int maxID;
public:
    
    static OrderDetailsData *getInstance();
    OrderDetailsData(/* args */);
    ~OrderDetailsData();

    bool importDataFromCSVFile();
    bool importDataFromJsonFile();
    bool exportDataToFile();
    OrderDetails* getOrderDetailsByID(int OrderDetailID);
    int createOrderDetail(int OrderID,int ProductID,int Quantity);
    bool updateOrderDetail(int OrderDetailID,int OrderID,int ProductID,int Quantity);
    bool deleteOrderDetail(int OrderDetailID);

    void printAll();
};

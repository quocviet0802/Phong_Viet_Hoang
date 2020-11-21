#pragma once
#include <iostream>
#include"../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Order
{
public:
    int OrderID,CustomerID,EmployeeID,ShipperID;
    string OrderDate;

public:
    Order();
    Order(int OrderID,int CustomerID,int EmployeeID,string OrderDate,int ShipperID);
    json toJson();
    ~Order();
};
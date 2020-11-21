#pragma once
#include <iostream>
#include"../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class OrderDetails
{
public:
    int OrderDetailID,OrderID,ProductID,Quantity;

public:
    OrderDetails();
    OrderDetails(int OrderDetailID,int OrderID,int ProductID,int Quantity);
    json toJson();
    ~OrderDetails();
};



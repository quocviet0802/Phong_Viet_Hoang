#pragma once
#include <iostream>
#include"../libs/json.hpp"
using namespace std;
using json = nlohmann::json;
class Product
{
public:
    int ProductID,SupplierID,CategoryID;
    double Price;
    string Unit,ProductName;

public:
    Product();
    Product(int ProductID,string ProductName,int SupplierID,int CategoryID,string Unit,double Price);
    json toJson();
    ~Product();
};
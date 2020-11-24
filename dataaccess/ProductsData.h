/** @file ProductsData.h
 *  @brief ProductsData stores all Product objects
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
#include"../businessobjects/Product.h"
using namespace std;

// #define PATH_FILE "RawDatas/ProductsData_csv.csv"

class ProductsData
{
public: 
    static ProductsData *instance;
private:
    vector<Product> ProductList;
    int maxID;
public:
    
    static ProductsData *getInstance();
    ProductsData(/* args */);
    ~ProductsData();

    bool importDataFromCSVFile();
    bool importDataFromJsonFile();
    bool exportDataToFile();
    Product* getProductByID(int ProductID);
    int createProduct(string ProductName,int SupplierID,int CategoryID,string Unit,double Price);
    bool updateProduct(int ProductID,string ProductName,int SupplierID,int CategoryID,string Unit,double Price);
    bool deleteProduct(int ProductID);
    vector<Product> getProductList();

    void printAll();
    void printList();
};

#include "Products.h"
#include <iostream>

using namespace std;

vector<Products*> Products::ListProducts;

Products::Products(){
}
Products::Products(int ProductId, string ProductName, int SupplierId, int CategoryId, string Unit, double Price){
    this->ProductId = ProductId;
    this->ProductName = ProductName;
    this->SupplierId = SupplierId;
    this->CategoryId = CategoryId;
    this->Unit = Unit;
    this->Price = Price;
}


/*
@file Products.cpp
@ function AddListProducts  is describing for adding
  a new product into a vector of type is Products
@author VietMQ
*/
void Products::AddListProducts(Products *item){
    ListProducts.push_back(item);
}
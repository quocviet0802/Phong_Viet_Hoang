#ifndef _Products_h
#define _Products_h

#include <string>
#include <vector>

using namespace std;

class Products{
public:
    int ProductId, SupplierId, CategoryId;
    double Price;
    string ProductName, Unit;
    
public:
    static vector<Products*> ListProducts;
    Products();
    Products(int ProductId, string ProductName, int SupplierId, int CategoryId, string Unit, double Price);
    // int GetProductsByProductID(int);
    static void AddListProducts(Products *item);
    ostream& operator << (ostream& out, Products item);
    
};


#endif
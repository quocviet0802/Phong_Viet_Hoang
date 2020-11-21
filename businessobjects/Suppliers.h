#ifndef _Suppliers_h
#define _Suppliers_h

#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Suppliers{
public:
    int SupplierID;
    string SupplierName, ContactName, Address, City, PostalCode, Country, Phone;
public:
    Suppliers();
    Suppliers(int, string, string, string, string, string, string, string);
    string ToString();
    json ToJson();
};


#endif
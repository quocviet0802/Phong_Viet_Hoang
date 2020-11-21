#include "Suppliers.h"
#include <iostream>

using namespace std;

Suppliers::Suppliers(){
}
Suppliers::Suppliers(int SupplierID, string SupplierName, string ContactName, string Address, string City, string PostalCode, string Country, string Phone){
    this->SupplierID = SupplierID;
    this->SupplierName = SupplierName;
    this->ContactName = ContactName;
    this->Address = Address;
    this->City = City;
    this->PostalCode = PostalCode;
    this->Country = Country;
    this->Phone = Phone;
}

string Suppliers::ToString(){
    string s;
    s += "{";
    s += to_string(SupplierID) + ", ";
    s += SupplierName + ", ";
    s += ContactName + ", ";
    s += Address + ", ";
    s += City + ", ";
    s += PostalCode + ", ";
    s += Country + ", ";
    s += Phone + ", ";
    s += "}";
    return s;
}

json Suppliers::ToJson(){
    json j;
    j["SupplierID"] = SupplierID;
    j["SupplierName"] = SupplierName;
    j["ContactName"] = ContactName;
    j["Address"] = Address;
    j["City"] = City;
    j["PostalCode"] = PostalCode;
    j["Country"] = Country;
    j["Phone"] = Phone;
    return j;
}
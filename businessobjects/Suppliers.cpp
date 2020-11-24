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


/** @brief Function converts this object to string.
 *  
 *  Function converts this object to string 
 *  *  @return a string;
 *  Example: Suppliers p(2, "Pepsi", "Charlotte", 49 Gilber, "Londona", "EC1 4SD", "UK", "(171) 555-2222")
 *       -> {"SupplierID":2,"SupplierName":"Pepsi","ContactName":"Charlotte","Address":"49 Gilber","City":"Londona","PostalCode":"EC1 4SD","Country":"UK", "Phone":"(171) 555-2222"}
 */
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


/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: Suppliers p(2, "Pepsi", "Charlotte", 49 Gilber, "Londona", "EC1 4SD", "UK", "(171) 555-2222")
 *       -> {"SupplierID":2,"SupplierName":"Pepsi","ContactName":"Charlotte","Address":"49 Gilber","City":"Londona","PostalCode":"EC1 4SD","Country":"UK", "Phone":"(171) 555-2222"}
 */
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
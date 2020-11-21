#include "Customers.h"

Customers::Customers(){}

Customers::Customers(int CustomerId, string CustomerName,string  ContactName,string  Address,string  City,string  PostalCode,string  Country){
    this->CustomerId=CustomerId;
    this->CustomerName=CustomerName;
    this->ContactName=ContactName;
    this->Address=Address;
    this->City=City;
    this->PostalCode=PostalCode;
    this->Country=Country;
}
string Customers::ToString(){
    string s;
    s += "{";
    s += to_string(CustomerId) + ", ";
    s += CustomerName + ", ";
    s += ContactName + ", ";
    s += Address + ", ";
    s += City + ", ";
    s += PostalCode + ", ";
    s += Country ;
    s += "}";
    return s;
}
/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: Customers p(1 , Alfreds Futterkiste,  Maria Anders,  Obere Str. 57,  Berlin , 12209 , Germany ) -> {"CustomerId":1,"CustomerName":"Alfreds Futterkiste","ContactName":"Maria Anders","Address":"Obere Str. 57","City":"Berlin","PostalCode":"12209", "Country":"Germany"}
 */
json Customers::ToJson(){
    json j;
    j["CustomerId"] = CustomerId;
    j["CustomerName"] = CustomerName;
    j["ContactName"] = ContactName;
    j["Address"] = Address;
    j["City"] = City;
    j["PostalCode"] = PostalCode;
    j["Country"] = Country;
    return j;
}

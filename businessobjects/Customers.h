#ifndef _Customers_h
#define _Customers_h
#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Customers{
public:
int CustomerId;
string CustomerName, ContactName, Address, City, PostalCode, Country;
public:
Customers();
Customers(int CustomerId, string CustomerName,string  ContactName,string  Address,string  City,string  PostalCode,string  Country);
string ToString();
json ToJson();
};
#endif
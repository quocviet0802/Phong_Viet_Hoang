#include "Categories.h"

Categories::Categories(){}


Categories::Categories(int CategoryId, string  CategoryName,string  Description){
    this->CategoryId=CategoryId;
    this->CategoryName=CategoryName;
    this->Description=Description;
}

string Categories::ToString(){
    string s;
    s += "{";
    s += to_string(CategoryId) + ", ";
    s += CategoryName + ", ";
    s += Description + ", ";
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: Categories p(1 , 	"Beverages"  ,	"Soft drinks, coffees, teas, beers, and ales") -> {"CategoryId":1,"CategoryName":"Beverages","Description":"Soft drinks, coffees, teas, beers, and ales"}
 */
json Categories::ToJson(){
    json j;
    j["CategoryId"] = CategoryId;
    j["CategoryName"] = CategoryName;
    j["Description"] = Description;
    return j;
}
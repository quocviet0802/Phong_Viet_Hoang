#include "Shippers.h"

Shippers::Shippers(){
}

Shippers::Shippers(int ShipperID, string ShipperName, string Phone){
    this->ShipperID = ShipperID;
    this->ShipperName = ShipperName;
    this->Phone = Phone;
}

/** @brief Function converts this object to string.
 *  
 *  Function converts this object to string 
 *  *  @return a string;
 *  Example: Shippers p(1, "Grab", "090.00123") -> {"ShipperID":1,"ShipperName":"Grab","Phone":"090.00123"}
 */
string Shippers::ToString(){
    string s;
    s += "{";
    s += to_string(ShipperID) + ", ";
    s += ShipperName + ", ";
    s += Phone;
    s += "}";
    return s;
}


/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.
 *  @return a json object;
 *  Example: Shippers p(1, "Grab", "090.00123") -> {"ShipperID":1,"ShipperName":"Grab","Phone":"090.00123"}
 */
json Shippers::ToJson(){
    json j;
    j["ShipperID"] = ShipperID;
    j["ShipperName"] = ShipperName;
    j["Phone"] = Phone;
    return j;
}
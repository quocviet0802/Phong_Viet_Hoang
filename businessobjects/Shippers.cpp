#include "Shippers.h"

Shippers::Shippers(){
}

Shippers::Shippers(int ShipperID, string ShipperName, string Phone){
    this->ShipperID = ShipperID;
    this->ShipperName = ShipperName;
    this->Phone = Phone;
}

string Shippers::ToString(){
    string s;
    s += "{";
    s += to_string(ShipperID) + ", ";
    s += ShipperName + ", ";
    s += Phone;
    s += "}";
    return s;
}

json Shippers::ToJson(){
    json j;
    j["ShipperID"] = ShipperID;
    j["ShipperName"] = ShipperName;
    j["Phone"] = Phone;
    return j;
}
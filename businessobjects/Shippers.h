#ifndef _Shippers_h
#define _Shippers_h

#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Shippers{
public:
    int ShipperID;
    string ShipperName, Phone;
public:
    Shippers();
    Shippers(int ShipperID, string ShipperName, string Phone);
    string ToString();
    json ToJson();
};


#endif
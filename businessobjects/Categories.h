#ifndef _Categories_h
#define _Categories_h
#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Categories{
public:
    int CategoryId;
    string CategoryName, Description;
public:
    Categories();
    Categories(int , string , string);
    string ToString();
    json ToJson();
};
#endif
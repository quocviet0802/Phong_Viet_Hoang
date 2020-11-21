#ifndef _Employees_h
#define _Employees_h
#include <string>
#include "../libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Employees{
public:
    int EmployeeId;
    string LastName,	FirstName,	BirthDate,	Photo, Notes;
public:
    Employees();
    Employees(int ,string ,string ,string  ,string  , string );
    string ToString();
    json ToJson();
};
#endif
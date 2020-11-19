#ifndef _Orders_h
#define _Orders_h

#include <string>
using namespace std;
class Orders{
private:
    int OrderID, CustomerID, EmployeeID, ShipperID;
    string OrderDate;
public:
    Orders();
    Orders(int OrderID, int CustomerID, int EmployeeID, string OrderDate, int ShipperID);
};
#endif
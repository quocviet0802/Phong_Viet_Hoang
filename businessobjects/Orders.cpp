#include "Orders.h"
Orders::Orders(){
}
Orders::Orders(int OrderID, int CustomerID, int EmployeeID, string OrderDate, int ShipperID){
    this->OrderID = OrderID;
    this->CustomerID = CustomerID;
    this->EmployeeID = EmployeeID;
    this->OrderDate = OrderDate;
    this->ShipperID = ShipperID;
}
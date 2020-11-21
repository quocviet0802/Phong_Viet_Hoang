#include "Order.h"

Order::Order()
{
}

Order::Order(int OrderID,int CustomerID,int EmployeeID,string OrderDate,int ShipperID)
{
    this->OrderID = OrderID;
    this->CustomerID = CustomerID;
    this->EmployeeID = EmployeeID;
    this->OrderDate = OrderDate;
    this->ShipperID = ShipperID;
}

Order::~Order()
{
}

/** @brief Function convert Order to json
*   Function convert Order to json
*   @return json object
*   @example auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
*            std::cout << j.dump(4) << std::endl;
*/  
json Order::toJson()
{
    json object =
        {
            {"OrderID", this->OrderID},
            {"CustomerID", this->CustomerID},
            {"EmployeeID", this->EmployeeID},
            {"OrderDate", this->OrderDate},
            {"ShipperID", this->ShipperID}
        };

    return object;
}
#include "OrderDetails.h"

OrderDetails::OrderDetails()
{
}

OrderDetails::OrderDetails(int OrderDetailID,int OrderID,int ProductID,int Quantity)
{
    this->OrderDetailID = OrderDetailID;
    this->OrderID = OrderID;
    this->ProductID = ProductID;
    this->Quantity = Quantity;
}

OrderDetails::~OrderDetails()
{
}

/** @brief Function convert Order Details to json
*   Function convert Order Details to json
*   @return json object
*   @example auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
*            std::cout << j.dump(4) << std::endl;
*/  
json OrderDetails::toJson()
{
    json object =
        {
            {"OrderDetailID", this->OrderDetailID},
            {"OrderID", this->OrderID},
            {"ProductID", this->ProductID},
            {"Quantity", this->Quantity},
        };

    return object;
}
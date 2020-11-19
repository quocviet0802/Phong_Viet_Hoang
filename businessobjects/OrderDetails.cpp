#include "OrderDetails.h"
OrderDetails::OrderDetails(){
}
OrderDetails::OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity){
    this->OrderDetailID = OrderDetailID;
    this->OrderID = OrderID;
    this->ProductID = ProductID;
    this->Quantity = Quantity;
}
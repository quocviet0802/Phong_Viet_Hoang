#include "Product.h"

Product::Product()
{
}

/** @brief Constructor
*   @param 
*       ProductID:(int) 
*       ProductName:(string)  
*       SupplierID:(int)
*       CategoryID:(int)
*       Unit:(string) unit of measure of an item
*       Price:(double) 
*/  
Product::Product(int ProductID,string ProductName,int SupplierID,int CategoryID,string Unit,double Price)
{
    this->ProductID = ProductID;
    this->ProductName = ProductName;
    this->SupplierID = SupplierID;
    this->CategoryID = CategoryID;
    this->Unit = Unit;
    this->Price = Price;
}

Product::~Product()
{
}

/** @brief Function convert Product object to json
*   Function convert Product object to json
*   @return json object
*   @example auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
*            std::cout << j.dump(4) << std::endl;
*/  
json Product::toJson()
{
    json object =
        {
            {"ProductID", this->ProductID},
            {"ProductName", this->ProductName},
            {"SupplierID", this->SupplierID},
            {"CategoryID", this->CategoryID},
            {"Unit", this->Unit},
            {"Price", this->Price}
        };

    return object;
}
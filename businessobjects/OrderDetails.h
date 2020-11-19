#ifndef _OrderDetails_h
#define _OrderDetails_h

#include <string>
using namespace std;
class OrderDetails{
private:
    int OrderDetailID, OrderID, ProductID, Quantity;
public:
    OrderDetails();
    OrderDetails(int OrderDetailID, int OrderID, int ProductID, int Quantity);
};
#endif
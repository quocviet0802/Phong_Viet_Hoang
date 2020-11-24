#ifndef _WarehouseManagementModel_h
#define _WarehouseManagementModel_h

#include "../dataaccess/CategoriesData.h"
#include "../dataaccess/CustomersData.h"
#include "../dataaccess/EmployeesData.h"
#include "../dataaccess/OrdersData.h"
#include "../dataaccess/OrderDetailsData.h"
#include "../dataaccess/ProductsData.h"
#include "../dataaccess/ShippersData.h"
#include "../dataaccess/SuppliersData.h"

#include <vector>
#include <string>
#include <time.h>

class WarehouseManagementModel{
// private:
protected:
    vector<Categories> DataCategories;
    vector<Customers> DataCustomers;
    vector<Employees> DataEmployees;
    vector<OrderDetails> DataOrderDetails;
    vector<Order> DataOrders;
    vector<Product> DataProducts;
    vector<Shippers> DataShippers;
    vector<Suppliers> DataSuppliers;

    string TimeStart;
    string TimeEnd;

public:
    WarehouseManagementModel();
    ~WarehouseManagementModel();

    void GetDataOrder();

    string GetShipperNameByID(int);
    string GetSupplierNameByID(int);
    string GetCustomerNameByID(int);
    string GetCategoryNameByID(int);

    string GetOrderDateByID(int);

    void ShowTable();
    void ShowData(int, int, string, int, double, int, string);

    virtual bool ShowStatisticsFollowProductID(int) = 0;
    virtual bool ShowStatisticsFollowCategoryID(int) = 0;
    virtual bool ShowStatisticsFollowSupplierID(int) = 0;
    void ShowDataOfStatistics(int, int, int);

    tm string2time(string);
    bool CheckInTime(string, string , string);
    int TimeCompare(tm, tm);

    virtual void ExportReport();  
};


#endif
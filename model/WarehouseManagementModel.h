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

public:
    WarehouseManagementModel();
    ~WarehouseManagementModel();

    void GetDataOrder();

    string GetShipperNameByID(int);
    string GetSupplierNameByID(int);
    string GetCustomerNameByID(int);
    string GetCategoryNameByID(int);

    void ShowTable();
    void ShowData(int, int, string, string, string, double, int, string, string, string);

    virtual bool ShowStatisticsFlowProductID(int) = 0;
    virtual bool ShowStatisticsFlowCategoryName(string) = 0;
    virtual bool ShowStatisticsFlowSupplierName(string) = 0;
    void ShowDataOfStatistics(int, int, int);

    virtual void ExportReport();   
};


#endif
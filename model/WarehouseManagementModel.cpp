#include "WarehouseManagementModel.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

WarehouseManagementModel::WarehouseManagementModel(){

}

WarehouseManagementModel::~WarehouseManagementModel(){

}

void WarehouseManagementModel::ExportReport(){
}


/** @brief Get all data of file
 *  A function to get all data from db file
 *  @author VietmQ
 */
void WarehouseManagementModel::GetDataOrder(){

    CategoriesData datacategories("RawDatas/Categories.txt");
    DataCategories = datacategories.GetCategoryList();

    CustomersData customers("RawDatas/Customers.txt");
    DataCustomers = customers.getCustomersDataList();

    EmployeesData employees("RawDatas/Employees.txt");
    DataEmployees = employees.getEmployeesDataList();

    OrderDetailsData oderdetails;
	oderdetails.importDataFromJsonFile();
    DataOrderDetails = oderdetails.getOrderDetailsList();

    OrdersData oders;
	oders.importDataFromJsonFile();
	DataOrders = oders.getOrderList();

    ProductsData products;
	products.importDataFromJsonFile();
	DataProducts = products.getProductList();

    ShippersData shippers("RawDatas/Shippers.txt");
    DataShippers = shippers.getShippersDataList();

    SuppliersData suppliers("RawDatas/Suppliers.txt");
    DataSuppliers = suppliers.getSuppliersDataList();

}


/** @brief Get category name with id
 *  A function to get category name with category id
 *  @return string of category name
 *  @author VietmQ
 */
string WarehouseManagementModel::GetCategoryNameByID(int id){
    string category_name = "NULL";
    for(Categories item: DataCategories){
        if(id == item.CategoryId){
            category_name = item.CategoryName;
        }
    }
    return category_name;
}


/** @brief Get customer name with id
 *  A function to get customer name with customer id
 *  @return string of customer name
 *  @author VietmQ
 */
string WarehouseManagementModel::GetCustomerNameByID(int id){
    string customer_name = "NULL";
    for(Customers item: DataCustomers){
        if(id == item.CustomerId){
            customer_name = item.CustomerName;
        }
    }
    return customer_name;
}


/** @brief Get shipper name with id
 *  A function to get shipper name with shipper id
 *  @return string of shipper name
 *  @author VietmQ
 */
string WarehouseManagementModel::GetShipperNameByID(int id){
    string shipper_name = "NULL";
    for(Shippers item: DataShippers){
        if(id == item.ShipperID){
            shipper_name = item.ShipperName;
        }
    }
    return shipper_name;
}


/** @brief Get supplier name with id
 *  A function to get supplier name with supplier id
 *  @return string of supplier name
 *  @author VietmQ
 */
string WarehouseManagementModel::GetSupplierNameByID(int id){
    string supplier_name = "NULL";
    for(Suppliers item: DataSuppliers){
        if(id == item.SupplierID){
            supplier_name = item.SupplierName;
        }
    }
    return supplier_name;
}


/** @brief Get order date with id
 *  A function to get order date with order id
 *  @return string of order date
 *  @author VietmQ
 */
string WarehouseManagementModel::GetOrderDateByID(int id){
    string date_order = "";
    for(Order item:DataOrders){
        if(item.OrderID == id){
            date_order = item.OrderDate;
        }
    }
    return date_order;
}


/** @brief Show frame of Statistics table
 *  A function to Show frame of Statistics table
 *  @author VietmQ
 */
void WarehouseManagementModel::ShowTable(){
    cout << endl << endl;
    cout << setw(10) << left << "Order_ID";
    cout << setw(15) << left << "Product_ID";
    cout << setw(35) << left << "Product_Name";
    cout << setw(15) << left << "Category_ID";
    cout << setw(10) << left << "Price";
    cout << setw(10) << left << "Quantity";
    cout << setw(25) << left << "Order_Date";
    cout << setw(15) << left << "Cost" << endl;
 
    cout << setfill('-');
    cout << setw(130) << "-" << endl;
    cout << setfill(' ');
}


/** @brief Show data of table
 *  A function to Show data of table
 *  @author VietmQ
 */
void WarehouseManagementModel::ShowData(int o_id, int p_id, string p_name, int c_id, double p, int q, string o_d){
    cout << setw(10) << left << o_id;
    cout << setw(15) << left << p_id;
    cout << setw(35) << left << p_name;
    cout << setw(15) << left << c_id;
    cout << setw(10) << left << p;
    cout << setw(10) << left << q;
    cout << setw(25) << left << o_d;
    cout << setw(15) << left << fabs(double(p*q)) << endl;

}


/** @brief Show data of Statistics table
 *  A function to Show data of Statistics table
 *  @author VietmQ
 */
void WarehouseManagementModel::ShowDataOfStatistics(int product_id, int order_id, int quanlity){

    string product_name = "NULL";
    double price = 0;
    int category_id = 0;
    string order_date = "NULL";

    for(Product product: DataProducts){
        if(product_id == product.ProductID){
            product_name = product.ProductName;
            price = product.Price;
            category_id = product.CategoryID;
            break;
        }
    }
    for(Order order: DataOrders){
        if(order.OrderID == order_id){
            string supplier = GetCustomerNameByID(order.CustomerID);
            string order_date = order.OrderDate;
            string shipper_name = GetShipperNameByID(order.ShipperID);
            
            ShowData(order_id, product_id, product_name, category_id, price, quanlity, order_date);
        }
    }


}


/** @brief change time from string to object
 *  A function to change time from string to object
 *  @return a object tm
 *  @author VietmQ
 */
tm WarehouseManagementModel::string2time(string str){
    const char* charstar = str.c_str();
    int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;
    tm tm1 = {0};
	sscanf(charstar,"%4d-%2d-%2d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday);
    return tm1;
}


/** @brief compare 2 time input 
 *  A function to compare 2 time input 
 *  @return 1 -> tm1 > tm2 | 0 -> tm1 = tm2 | -1 -> tm1 < tm2
 *  @author VietmQ
 */
int WarehouseManagementModel::TimeCompare(tm tm1, tm tm2){
    if (tm1.tm_year > tm2.tm_year) return 1;
    else if (tm1.tm_year < tm2.tm_year) return -1;
    else 
    if (tm1.tm_mon > tm2.tm_mon) return 1;
    else if (tm1.tm_mon < tm2.tm_mon) return -1; 
    else
    if (tm1.tm_mday > tm2.tm_mday) return 1;
    else if (tm1.tm_mday < tm2.tm_mday) return -1;  
    else return 0;
}


/** @brief Check the time input is between time_start and time_input
 *  A function to Check the time input is between time_start and time_input
 *  @return a bool type
 *  @author VietmQ
 */
bool WarehouseManagementModel::CheckInTime(string time_start, string time_end, string time_check){
    tm start = string2time(time_start);
    tm end = string2time(time_end);
    tm check = string2time(time_check);

    int check_rank = TimeCompare(start, end);

    int compare_start = TimeCompare(check, start);
    int compare_end = TimeCompare(end, check);


    if(check_rank < 0){
        return (compare_start >= 0 && compare_end >= 0) ? true : false;
    }else{
        return (compare_start <= 0 && compare_end <= 0) ? true :  false;
    }
}


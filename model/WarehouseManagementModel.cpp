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
    cout << "Hello I am Warehouse" <<endl;
}

void WarehouseManagementModel::GetDataOrder(){

    CategoriesData datacategories("RawDatas/Categories.txt");
    DataCategories = datacategories.getCategoriesDataList();

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

string WarehouseManagementModel::GetCategoryNameByID(int id){
    string category_name = "NULL";
    for(Categories item: DataCategories){
        if(id == item.CategoryId){
            category_name = item.CategoryName;
        }
    }
    return category_name;
}

string WarehouseManagementModel::GetCustomerNameByID(int id){
    string customer_name = "NULL";
    for(Customers item: DataCustomers){
        if(id == item.CustomerId){
            customer_name = item.CustomerName;
        }
    }
    return customer_name;
}

string WarehouseManagementModel::GetShipperNameByID(int id){
    string shipper_name = "NULL";
    for(Shippers item: DataShippers){
        if(id == item.ShipperID){
            shipper_name = item.ShipperName;
        }
    }
    return shipper_name;
}

string WarehouseManagementModel::GetSupplierNameByID(int id){
    string supplier_name = "NULL";
    for(Suppliers item: DataSuppliers){
        if(id == item.SupplierID){
            supplier_name = item.SupplierName;
        }
    }
    return supplier_name;
}

string WarehouseManagementModel::GetOrderDateByID(int id){
    string date_order = "";
    for(Order item:DataOrders){
        if(item.OrderID == id){
            date_order = item.OrderDate;
        }
    }
    return date_order;
}

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


tm WarehouseManagementModel::string2time(string str){
    const char* charstar = str.c_str();
    int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;
    tm tm1 = {0};
	sscanf(charstar,"%4d-%2d-%2d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday);
    return tm1;
}

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

bool WarehouseManagementModel::CheckInTime(string time_start, string time_end, string time_check){
    tm start = string2time(time_start);
    tm end = string2time(time_end);
    tm check = string2time(time_check);

    int check_rank = TimeCompare(start, end);

    if(check_rank < 0){
        int compare_start = TimeCompare(check, start);
        int compare_end = TimeCompare(end, check);

        return (compare_start >= 0 && compare_end >= 0) ? true : false;

    }else{
        int compare_start = TimeCompare(check, start);
        int compare_end = TimeCompare(end, check);

        return (compare_start <= 0 && compare_end <= 0) ? true :  false;
    }
}

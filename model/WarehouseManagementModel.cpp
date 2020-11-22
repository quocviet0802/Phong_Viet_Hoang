#include "WarehouseManagementModel.h"

#include <iostream>
#include <string>
#include <iomanip>

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


void WarehouseManagementModel::ShowTable(){
    cout << endl << endl;
    cout << setw(10) << left << "Order_ID";
    cout << setw(12) << left << "Product_ID";
    cout << setw(30) << left << "Product_Name";
    cout << setw(17) << left << "Category_Name";
    cout << setw(22) << left << "Unit" ;
    cout << setw(7) << left << "Price";
    cout << setw(10) << left << "Quantity";
    cout << setw(30) << left << "Supplier";
    cout << setw(14) << left << "Order_Date";
    cout << setw(20) << left << "Shipper_Name" << endl;
    cout << setfill('-');
    cout << setw(160) << "-" << endl;
    cout << setfill(' ');
}

void WarehouseManagementModel::ShowData(int o_id, int p_id, string p_name, string c_name, string u, double p, int q, string s, string o_d, string s_n){
    cout << setw(10) << left << o_id;
    cout << setw(12) << left << p_id;
    cout << setw(30) << left << p_name;
    cout << setw(17) << left << c_name;
    cout << setw(22) << left << u ;
    cout << setw(7) << left << p;
    cout << setw(10) << left << q;
    cout << setw(30) << left << s;
    cout << setw(14) << left << o_d;
    cout << setw(20) << left << s_n << endl;
}

void WarehouseManagementModel::ShowDataOfStatistics(int product_id, int order_id, int quanlity){

    string product_name = "NULL";
    string unit = "NULL";
    double price = 0;
    string category_name = "NULL";
    string supplier = "NULL";
    string order_date = "NULL";
    string shipper_name = "NULL";

    for(Product product: DataProducts){
        if(product_id == product.ProductID){
            product_name = product.ProductName;
            unit = product.Unit;
            price = product.Price;
            category_name = GetCategoryNameByID(product.CategoryID);
            break;
        }
    }
    for(Order order: DataOrders){
        if(order.OrderID == order_id){
            string supplier = GetCustomerNameByID(order.CustomerID);
            string order_date = order.OrderDate;
            string shipper_name = GetShipperNameByID(order.ShipperID);
            
            ShowData(order_id, product_id, product_name, category_name, unit, price, quanlity, supplier, order_date, shipper_name);
        }
    }


}



#include "ImportManagementModel.h"

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

ImportManagementModel::ImportManagementModel(){

}

ImportManagementModel::~ImportManagementModel(){

}


/** @brief Show data of Statistics table with product id
 *  A function to Show data of Statistics table with product id
 *  @return true if success, false if fail
 *  @author VietmQ
 */
bool ImportManagementModel::ShowStatisticsFollowProductID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(OrderDetails item: DataOrderDetails){
        string oder_date = GetOrderDateByID(item.OrderID);
        if (CheckInTime(TimeStart, TimeEnd, oder_date)){
            if(item.ProductID == id){
                if(item.Quantity < 0) continue;
                ShowDataOfStatistics(item.ProductID, item.OrderID, item.Quantity);
                FlagCheck = true;
            }
        }
    }

    if(FlagCheck) return true;
    return false;
}


/** @brief Show data of Statistics table with category id
 *  A function to Show data of Statistics table with category id
 *  @return true if success, false if fail
 *  @author VietmQ
 */
bool ImportManagementModel::ShowStatisticsFollowCategoryID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(Product item: DataProducts){
        if(item.CategoryID == id){
            for(OrderDetails item2: DataOrderDetails){
                if(item2.ProductID == item.ProductID){
                    string oder_date = GetOrderDateByID(item2.OrderID);
                    if (CheckInTime(TimeStart, TimeEnd, oder_date)){
                        if(item2.Quantity < 0) continue;
                        ShowDataOfStatistics(item2.ProductID, item2.OrderID, item2.Quantity);
                        FlagCheck = true;
                    }
                }
            }
        }
    }    

    if(FlagCheck) return true;
    return false;
}


/** @brief Show data of Statistics table with supplier id
 *  A function to Show data of Statistics table with supplier id
 *  @return true if success, false if fail
 *  @author VietmQ
 */
bool ImportManagementModel::ShowStatisticsFollowCustomerID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(Order item: DataOrders){
        if(item.CustomerID == id){
            if (CheckInTime(TimeStart, TimeEnd, item.OrderDate)){
                for(OrderDetails item2: DataOrderDetails){
                    if(item2.OrderID == item.OrderID){
                        if(item2.Quantity < 0) continue;
                        ShowDataOfStatistics(item2.ProductID, item2.OrderID, item2.Quantity);
                        FlagCheck = true;
                    }
                }
            }
        }
    }
            

    if(FlagCheck) return true;
    return false;
}


/** @brief show import management
 *  A function to Show option and call function import management
 *  @author VietmQ
 */
void ImportManagementModel::ImportManagement(){
    GetDataOrder();
    do
    {
        system("CLS");
        cout << "---Import Management---" << endl << endl;
        cout << "Please choose :  " << endl << endl; 
        cout << "1. Input New Data"<<endl;
        cout << "2. Export Statistics"<<endl;
        cout << "3. Exit" <<endl;
        cout << "Select : ";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            InputDataToDB();
            cout << endl << "Done !!" << endl;
            getch();
            return;
        }
        case 2:
        {
            ExportReport();
            return;
        }
        case 3:
            return;
        default:
            break;
        }
    } while (1);

}
    

/** @brief import management
 *  A function to Show option and call function print report
 *  @author VietmQ
 */
void ImportManagementModel::ExportReport(){

    system("CLS");
    cout << "Enter The Time Period" << endl;
    cout << "From (YYYY-MM-DD): ";
    cin >> TimeStart;
    cout << "To (YYYY-MM-DD): ";
    cin >> TimeEnd;

    do
    {
        system("CLS");
        cout << "1. Export Statistics With Product ID"<< endl;
        cout << "2. Export Statistics With Category ID"<< endl;
        cout << "3. Export Statistics With Customer ID"<< endl;
        cout << "4. Exit"<< endl;
        cout << "Select: "<< endl;
  
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Input Product ID: ";
            int id;
            cin >> id;
            ShowStatisticsFollowProductID(id);
            getch();
            return;
        }
        case 2:
        {
            cout << "Input Category ID: ";
            int id;
            cin >> id;
            ShowStatisticsFollowCategoryID(id);
            getch();
            return;
        }
        case 3:
        {
            cout << "Input Supplier ID: ";
            int id;
            cin >> id;
            ShowStatisticsFollowCustomerID(id);
            getch();
            return;
        }
        case 4:
            return;
        default:
            break;
        }

    } while (1);
}


/** @brief Input data press from keyboard to db file
 *  A function to Input data press from keyboard to db file
 *  @return a bool type
 *  @author VietmQ
 */
void ImportManagementModel::InputDataToDB(){
    system("CLS");
    cout << "Input Order Information" << endl;

    
    cout << "Input Customer ID ('intput ID is 0 if New Customer): ";
    int customer_id;
    cin >> customer_id;

    cout << "Input Employee ID: ";
    int employee_id;
    cin >> employee_id;

    cout << "Input Order Date (YYYY-MM-DD): ";
    string order_date;
    cin.clear();
    fflush(stdin);
    getline(cin, order_date);

    cout << "Input Shipper ID: ";
    int shipper_id;
    cin >> shipper_id;

    if(customer_id == 0){
        cout << "Input 'Name' of new customer: ";
        string name;
        cin.clear();
        fflush(stdin);
        getline(cin, name);

        cout << "Input 'Contact Name' of new customer: ";
        string contact;
        cin.clear();
        fflush(stdin);
        getline(cin, contact);

        cout << "Input 'Address' of new customer: ";
        string address;
        cin.clear();
        fflush(stdin);
        getline(cin, address);
        
        cout << "Input 'City' of new customer: ";
        string city;
        cin.clear();
        fflush(stdin);
        getline(cin, city);

        cout << "Input 'Postal Code' of new customer: ";
        string portal_code;
        cin.clear();
        fflush(stdin);
        getline(cin, portal_code);

        cout << "Input 'Country' of new customer: ";
        string country;
        cin.clear();
        fflush(stdin);
        getline(cin, country);

        cout << endl;
        cout << "Enter to save 'Customer Information': ";
        getch();

        CustomersData customer("RawDatas/Customers.txt");
        customer_id = customer.createCustomers(name, contact, address, city, portal_code, country);
        customer.ExportToFile("RawDatas/Customers.txt");

        GetDataOrder();
        cout << " Done !" << endl;
        getch();
    }
    

    cout << endl;
    cout << "Enter to save 'Order Information': ";
    getch();

    OrdersData oders;
    oders.importDataFromJsonFile();
    int order_id = oders.createOrder(customer_id, employee_id, order_date, shipper_id);
    oders.exportDataToFile();

    cout << endl << endl;

    cout << setw(10) << left << "Order_ID";
    cout << setw(25) << left << "Customer_Name";
    cout << setw(25) << left << "Employee_Name";
    cout << setw(25) << left << "Order_Date";
    cout << setw(25) << left << "Shiper_name"<< endl;
    cout << setfill('-');
    cout << setw(100) << "-" << endl;
    cout << setfill(' ');

    cout << setw(10) << left << order_id;
    cout << setw(25) << left << GetCustomerNameByID(customer_id);
    cout << setw(25) << left << GetEmployeeNameByID(employee_id);
    cout << setw(25) << left << order_date;
    cout << setw(25) << left << GetShipperNameByID(shipper_id) << endl <<endl;

    getch();

    char check;
    do{

        system("CLS");
        cout << endl;
        cout << "Input Product Information of Order ( " << order_id << " )" << endl;

        int product_id;
        cout << "Input Product ID : ";
        cin >> product_id;

        cout << "Input Quantity: ";
        int quantity;
        cin >> quantity;

        OrderDetailsData odersdetails;
        odersdetails.importDataFromJsonFile();
        odersdetails.createOrderDetail(order_id, product_id, quantity);
        odersdetails.exportDataToFile();

        cout << endl << endl;

        cout << setw(30) << left << "Product_Name";
        cout << setw(25) << left << "Quanltity";
        cout << setw(25) << left << "Price" ;
        cout << setw(25) << left << "Cost" << endl;
        cout << setfill('-');
        cout << setw(105) << "-" << endl;
        cout << setfill(' ');
        
        double price = GetProductPriceByID(product_id);
        cout << setw(30) << left << GetProductNameByID(product_id);
        cout << setw(25) << left << quantity;
        cout << setw(25) << left << price;
        cout << setw(25) << left << price * quantity << endl << endl;

        cout << "Continue [Y/N]:";
        cin >> check;

    }while(check == 'Y' || check == 'y');

}

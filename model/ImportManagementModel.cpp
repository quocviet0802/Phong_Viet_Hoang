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

bool ImportManagementModel::ShowStatisticsFollowProductID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(OrderDetails item: DataOrderDetails){
        string oder_date = GetOrderDateByID(item.OrderID);
        if ( (oder_date != "") ? CheckInTime(TimeStart, TimeEnd, oder_date) : false) continue;
        if(item.ProductID == id){
            if(item.Quantity < 0) continue;
            ShowDataOfStatistics(item.ProductID, item.OrderID, item.Quantity);
            FlagCheck = true;
        }
    }

    if(FlagCheck) return true;
    return false;
}


bool ImportManagementModel::ShowStatisticsFollowCategoryID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(Product item: DataProducts){
        if(item.CategoryID == id){
            for(OrderDetails item2: DataOrderDetails){
                if(item2.ProductID == item.ProductID){
                    string oder_date = GetOrderDateByID(item2.OrderID);
                    if ( (oder_date != "") ? CheckInTime(TimeStart, TimeEnd, oder_date) : false) continue;
                    if(item2.Quantity < 0) continue;
                    ShowDataOfStatistics(item2.ProductID, item2.OrderID, item2.Quantity);
                    FlagCheck = true;
                }
            }
        }
    }    

    if(FlagCheck) return true;
    return false;
}


bool ImportManagementModel::ShowStatisticsFollowSupplierID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(Order item: DataOrders){
        if(item.CustomerID == id){
            if( CheckInTime(TimeStart, TimeEnd, item.OrderDate) ) continue;
            for(OrderDetails item2: DataOrderDetails){
                if(item2.OrderID == item.OrderID){
                    if(item2.Quantity < 0) continue;
                    ShowDataOfStatistics(item2.ProductID, item2.OrderID, item2.Quantity);
                    FlagCheck = true;
                }
            }
        }
    }
            

    if(FlagCheck) return true;
    return false;
}


void ImportManagementModel::ImportManagement(){
    do
    {
        system("CLS");
        cout << "1. Them thong tin"<<endl;
        cout << "2. Xuat hoa don"<<endl;
        cout << "3. Exit" <<endl;
        cout << "---nhap option : ";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            InputDataToDB();
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
    


void ImportManagementModel::ExportReport(){

    system("CLS");
    cout << "Nhap Thoi Gian Can Xuat Bao Cao " << endl;
    cout << "From (YYYY-MM-DD) : ";
    cin >> TimeStart;
    cout << "To (YYYY-MM-DD): ";
    cin >> TimeEnd;

    do
    {
        system("CLS");
        cout << "Xuat Bao Cao Theo" << endl;
        cout << "1. Xuat theo product id"<< endl;
        cout << "2. Xuat theo category id"<< endl;
        cout << "3. Xuat theo customer id"<< endl;
  

        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "nhap product id : ";
            int id;
            cin >> id;
            ShowStatisticsFollowProductID(id);
            getch();
            return;
        }
        case 2:
        {
            cout << "nhap category id : ";
            int id;
            cin >> id;
            ShowStatisticsFollowCategoryID(id);
            getch();
            return;
        }
        case 3:
        {
            cout << "nhap supplier id : ";
            int id;
            cin >> id;
            ShowStatisticsFollowSupplierID(id);
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

void ImportManagementModel::InputDataToDB(){
    system("CLS");
    cout << "Nhap thong tin order" << endl;

    cout << "Nhap Customer ID :";
    int customer_id;
    cin >> customer_id;

    cout << "Nhap Employee ID :";
    int employee_id;
    cin >> employee_id;

    cout << "Nhap order date (DD/MM/YYYY): ";
    string order_date;
    cin.clear();
    fflush(stdin);
    getline(cin, order_date);

    cout << "Nhap shipper ID :";
    int shipper_id;
    cin >> shipper_id;

    OrdersData oders;
    oders.importDataFromJsonFile();
    int order_id = oders.createOrder(customer_id, employee_id, order_date, shipper_id);
    oders.exportDataToFile();

    char check;
    do{

        system("CLS");
        cout << endl;
        cout << "Nhap thong tin cac product cua order" << endl;

        int product_id;
        cout << "Nhap Product ID: ";
        cin >> product_id;
        cout << "Nhap  Quanlity: ";
        int quanlity;
        cin >> quanlity;

        OrderDetailsData odersdetails;
        odersdetails.importDataFromJsonFile();
        odersdetails.createOrderDetail(order_id, product_id, quanlity);
        odersdetails.exportDataToFile();

        cout << "nhap tiep [Y/N] :";
        cin >> check;

    }while(check == 'Y' || check == 'y');

}


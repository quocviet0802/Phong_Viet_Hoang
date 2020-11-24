#include "ExportManagementModel.h"

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

ExportManagementModel::ExportManagementModel(){

}

ExportManagementModel::~ExportManagementModel(){

}


bool ExportManagementModel::ShowStatisticsFollowProductID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(OrderDetails item: DataOrderDetails){
        string oder_date = GetOrderDateByID(item.OrderID);
        if ( (oder_date != "") ? CheckInTime(TimeStart, TimeEnd, oder_date) : false) continue;
        if(item.ProductID == id){
            if(item.Quantity > 0) continue;
            ShowDataOfStatistics(item.ProductID, item.OrderID, item.Quantity);
            FlagCheck = true;
        }
    }

    if(FlagCheck) return true;
    return false;
}


bool ExportManagementModel::ShowStatisticsFollowCategoryID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(Product item: DataProducts){
        if(item.CategoryID == id){
            for(OrderDetails item2: DataOrderDetails){
                if(item2.ProductID == item.ProductID){
                    string oder_date = GetOrderDateByID(item2.OrderID);
                    if ( (oder_date != "") ? CheckInTime(TimeStart, TimeEnd, oder_date) : false) continue;
                    if(item2.Quantity > 0) continue;
                    ShowDataOfStatistics(item2.ProductID, item2.OrderID, item2.Quantity);
                    FlagCheck = true;
                }
            }
        }
    }    

    if(FlagCheck) return true;
    return false;
}


bool ExportManagementModel::ShowStatisticsFollowSupplierID(int id){
    bool FlagCheck = false;

    ShowTable();

    for(Order item: DataOrders){
        if(item.CustomerID == id){
            if( CheckInTime(TimeStart, TimeEnd, item.OrderDate) ) continue;
            for(OrderDetails item2: DataOrderDetails){
                if(item2.OrderID == item.OrderID){
                    if(item2.Quantity > 0) continue;
                    ShowDataOfStatistics(item2.ProductID, item2.OrderID, item2.Quantity);
                    FlagCheck = true;
                }
            }
        }
    }
            

    if(FlagCheck) return true;
    return false;
}



void ExportManagementModel::ExportManagement(){
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


void ExportManagementModel::ExportReport(){

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

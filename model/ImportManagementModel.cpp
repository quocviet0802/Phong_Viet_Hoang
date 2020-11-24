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


/** @brief Show data of Statistics table with supplier id
 *  A function to Show data of Statistics table with supplier id
 *  @return true if success, false if fail
 *  @author VietmQ
 */
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


/** @brief show import management
 *  A function to Show option and call function import management
 *  @author VietmQ
 */
void ImportManagementModel::ImportManagement(){
    do
    {
        system("CLS");
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
    cout << "From (YYYY-MM-DD) : ";
    cin >> TimeStart;
    cout << "To (YYYY-MM-DD): ";
    cin >> TimeEnd;

    do
    {
        system("CLS");
        cout << "1. Export Statistics With Product ID"<< endl;
        cout << "2. Export Statistics With Category ID"<< endl;
        cout << "3. Export Statistics With Supplier ID"<< endl;
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

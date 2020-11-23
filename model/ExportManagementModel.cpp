#include "ExportManagementModel.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

ExportManagementModel::ExportManagementModel(){

}

ExportManagementModel::~ExportManagementModel(){

}



void ExportManagementModel::ExportReport(){
    cout << "Hello I am Export" <<endl;

}

bool ExportManagementModel::ShowStatisticsFollowProductID(int id){
    bool FlagCheck = false;

    WarehouseManagementModel::ShowTable();

    for(OrderDetails item: DataOrderDetails){
        if(item.ProductID == id){
            if(item.Quantity > 0) continue;
            ShowDataOfStatistics(item.ProductID, item.OrderID, item.Quantity);
            FlagCheck = true;
        }
    }

    if(FlagCheck) return true;
    return false;
}


bool ExportManagementModel::ShowStatisticsFollowCategoryName(string name){
    bool FlagCheck = false;

    WarehouseManagementModel::ShowTable();

    for(Categories item: DataCategories){
        if(item.CategoryName == name){
            for(Product item2: DataProducts){
                if(item2.CategoryID == item.CategoryId){
                    for(OrderDetails item3: DataOrderDetails){
                        if(item3.ProductID == item2.ProductID){
                            if(item3.Quantity > 0) continue;
                            ShowDataOfStatistics(item3.ProductID, item3.OrderID, item3.Quantity);
                            FlagCheck = true;
                        }
                    }
                }
            }
            
        }
    }

    if(FlagCheck) return true;
    return false;
}


bool ExportManagementModel::ShowStatisticsFollowSupplierName(string name){
    bool FlagCheck = false;

    ShowTable();

    for(Customers item: DataCustomers){
        if(item.CustomerName == name){
            for(Order item2: DataOrders){
                if(item2.CustomerID == item.CustomerId){
                    for(OrderDetails item3: DataOrderDetails){
                        if(item3.OrderID == item2.OrderID){
                            if(item3.Quantity > 0) continue;
                            ShowDataOfStatistics(item3.ProductID, item3.OrderID, item3.Quantity);
                            FlagCheck = true;
                        }
                    }
                }
            }
            
        }
    }

    if(FlagCheck) return true;
    return false;
}
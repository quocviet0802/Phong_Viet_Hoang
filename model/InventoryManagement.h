#ifndef _InventoryManagement_h
#define _InventoryManagement_h
#include "WarehouseManagementModel.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class InventoryManagement : public WarehouseManagementModel {
    
    
    public:

    InventoryManagement();
    ~InventoryManagement();
    
    void ShowTableInventory();
    void ShowInputOutputDataInventory(int, string, string, double ,int);
    
    string GetProductNameByProductID(int);
    double GetPriceByProductID(int);
    string GetOrderDateByOrderID(int);
    string GetUnitByProductID(int);
    
    void ShowStatisticsFollowID(string , string);

    void totalValueOfOInventoryInThePeriod(int ,string,string,double,int);
    void ShowTableInventoryTotal();
    
    void  ShowStatisticsInventoryTotal(string ,string );

    
    bool ShowStatisticsFollowProductID(int);
    bool ShowStatisticsFollowCategoryID(int);
    bool ShowStatisticsFollowCustomerID(int);

    void MenuInventoryManagemament();
};
#endif
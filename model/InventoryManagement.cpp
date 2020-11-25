#include "InventoryManagement.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;




InventoryManagement::InventoryManagement(){

}
InventoryManagement::~InventoryManagement(){

}

/** @brief Show Inventory table title to Import and export of products report
 *  A function to  Show Inventory table title to Import and export of products report
 *  @author Phong
 */

void InventoryManagement::ShowTableInventory(){
    cout << endl<<endl;
    cout<< "=================  Import and export of products report in the period  ===================";
    cout<< endl<<endl;
    
    cout<< setw(12)<< left << "Product_ID";
    cout<< setw(40)<< left << "Product_Name";
    cout<< setw(22)<< left << "OrderDate";
    cout<< setw(7)<< left << "Price";
    cout<< setw(7)<<left << "Quantity"<<endl;;
    cout<< setfill('-');
    cout<< setw(90)<< "-"<<endl;
    cout<< setfill(' ');
    
}

/** @brief Show Inventory table to Import and export of products report
 *  A function to  Show Inventory table to Import and export of products report
 *  @author Phong
 */
void InventoryManagement::ShowInputOutputDataInventory(int ProductID, string ProductName,string OrderDate ,double Price,int Quantity){
    cout<< setw(12)<< left << ProductID;
    cout<< setw(40)<<left  << ProductName;
    cout<< setw(22)<<left << OrderDate;
    cout<< setw(7)<<left << Price;
    cout<< setw(7)<< left << Quantity<<endl;
}


/** @brief Show data in Inventory table to Import and export of products report in the period time
 *  A function to  Show Inventory table to Import and export of products report in the period time
 *  @author Phong
 */
void InventoryManagement::ShowStatisticsFollowID(string startDate, string endDate){
    ShowTableInventory();
   
    for (Order item: DataOrders){
        
        if(CheckInTime(startDate, endDate, item.OrderDate)){
            for(OrderDetails item2: DataOrderDetails){
                if(item2.OrderID == item.OrderID){
                    int quantity = item2.Quantity;
                    int productId = item2.ProductID;

                    string productName = GetProductNameByProductID(item2.ProductID);
                    string orderDate = GetOrderDateByOrderID(item2.OrderID);

                    double price = GetPriceByProductID(item2.ProductID);
                    ShowInputOutputDataInventory(productId,productName,orderDate, price, quantity);
                }
            }
        }

    }
}




bool InventoryManagement::ShowStatisticsFollowProductID(int id) {
    return false;}
bool InventoryManagement::ShowStatisticsFollowCategoryID(int id) {
    return false;}
bool InventoryManagement::ShowStatisticsFollowCustomerID(int id){
    return false;}

/** @brief Get Product name with id
 *  A function to get Product name with Product id
 *  @return string of Product name
 *  @author Phong
 */
string InventoryManagement::GetProductNameByProductID(int id){
    string product_name = "NULL";
    for(Product item: DataProducts){
        if(id == item.ProductID){
            product_name = item.ProductName;
        }
    }
    return product_name;
}


/** @brief Get Order name with id
 *  A function to get Order name with Order id
 *  @return string of Order name
 *  @author Phong
 */
string InventoryManagement::GetOrderDateByOrderID(int id){
    string order_day = "NULL";
    for(Order item: DataOrders){
        if(id == item.OrderID){
            order_day = item.OrderDate;
        }
    }
    return order_day;
}

/** @brief Get Price  with id
 *  A function to get Price with Product id
 *  @return double of Price
 *  @author Phong
 */
double InventoryManagement::GetPriceByProductID(int id){
    int price;
    for(Product item: DataProducts){
        if(id== item.ProductID){
            price=item.Price;
        }
    }
    return price;
}

/** @brief Get Unit  with id
 *  A function to get Unit with Product id
 *  @return string of Unit
 *  @author Phong
 */
string InventoryManagement::GetUnitByProductID(int id){
    string unit = "NULL";
    for(Product item: DataProducts){
        if(id == item.ProductID){
            unit = item.Unit;
        }
    }
    return unit;
}

/** @brief Show Total Inventory table title  to remaining In Inventory
 *  A function to  Show Total Inventory table title  to remaining In Inventory
 *  @author Phong
 */
void InventoryManagement::ShowTableInventoryTotal(){
    cout<<endl<<endl;
    cout<<"====================  Inventory reports and inventory value. ======================";
    cout << endl<<endl;
    cout<< setw(12)<< left << "Product_ID";
    cout<< setw(40)<< left << "Product_Name";
    cout<< setw(22)<< left << "Unit";
    cout<< setw(10)<< left << "Quantity";
    cout<< setw(10)<< left << "Money"<< endl;
    cout<< setfill('-');
    cout<< setw(90)<< "-"<<endl;
    cout<< setfill(' ');
}

/** @brief Show Total Inventory table   to remaining In Inventory
 *  A function to  Show Total Inventory table  to remaining In Inventory
 *  @author Phong
 */
void InventoryManagement::totalValueOfOInventoryInThePeriod(int productId ,string productName,string Unit,double price,int quanlity){
    cout<< setw(12)<< left <<productId;
    cout<< setw(40)<< left << productName;
    cout<< setw(22)<< left << Unit;
    cout<< setw(10)<< left << quanlity;
    cout<< setw(10)<<left << price<<endl;
}



/** @brief show Total Inventory table   to remaining In Inventory in the period time
 *  A function to  show Total Inventory table   to remaining In Inventory in the period time
 *  @author Phong
 */

void  InventoryManagement::ShowStatisticsInventoryTotal(string startDate,string endDate){

     ShowTableInventoryTotal();
        for (Order item: DataOrders){
            int quantity=0;
            if(CheckInTime(startDate, endDate, item.OrderDate) ){
                for(OrderDetails item2: DataOrderDetails){
                    if(item2.OrderID==item.OrderID){
                        quantity+=item2.Quantity;   
                        int productId=item2.ProductID;
                        string productname=GetProductNameByProductID(item2.ProductID);
                        string unit= GetUnitByProductID(item2.ProductID) ;
                        double price= quantity*GetPriceByProductID(item2.ProductID) ;
                        totalValueOfOInventoryInThePeriod(productId, productname,unit, price,quantity);
                    }
                }
            } 
         }
     }

/** @brief Input data press from keyboard to db file
 *  A function to show data in Inventory table press from keyboard to db file
 *  @author Phong
 */

void InventoryManagement::MenuInventoryManagemament(){
    GetDataOrder();

    while(1)
    {
    system("CLS");
    cout<< "=====================    Menu Inventory Managemament   =================="<<endl;
    cout<< "========================================================================="<<endl<<endl;
    cout<< "1. Import and export of products report in the period. "<<endl;
    cout<< "2. Inventory reports and inventory value."<<endl;
    cout<< "3. Exit "<<endl;
    cout<< "Input Menu: "<<endl;
    int x;
    cin >> x;
    
   
    switch (x){
            case 1:
            {   
                cout<< "1.Import and export of products report in the period."<<endl;
                cout<< "Input the period time: "<<endl;
                string startDate;
                string endDate;

                cout<< "Start time:(YYYY-MM-DD): ";
                cin.clear();
                fflush(stdin);
                getline(cin, startDate);

                cout<< "End time:(YYYY-MM-DD): ";
                cin.clear();
                fflush(stdin);
                getline(cin, endDate);
                GetDataOrder();
                ShowStatisticsFollowID(startDate,endDate);
                getch();
                break;
            }
            case 2:
            {   
                
                cout<<"2. Inventory reports and inventory value:"<<endl;
                cout<< "Input the period time: "<<endl;
                string startDate;
                string endDate;

                cout<< "Start time:(YYYY-MM-DD): ";
                cin.clear();
                fflush(stdin);
                getline(cin, startDate);

                cout<< "End time:(YYYY-MM-DD): ";
                cin.clear();
                fflush(stdin);
                getline(cin, endDate);
                GetDataOrder();
                ShowStatisticsInventoryTotal(startDate, endDate);
                getch();
                break;
             }
            case 3:{
                return ;
            }
            
            default:
		        break;
            }
    }
}






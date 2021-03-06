#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "businessobjects/Categories.h"
#include "businessobjects/Customers.h"
#include "businessobjects/Employees.h"
#include "businessobjects/Order.h"
#include "businessobjects/OrderDetails.h"
#include "businessobjects/Product.h"
#include "businessobjects/Shippers.h"
#include "businessobjects/Suppliers.h"

#include "dataaccess/CategoriesData.h"
#include "dataaccess/CustomersData.h"
#include "dataaccess/EmployeesData.h"
#include "dataaccess/OrdersData.h"
#include "dataaccess/OrderDetailsData.h"
#include "dataaccess/ProductsData.h"
#include "dataaccess/ShippersData.h"
#include "dataaccess/SuppliersData.h"

#include "model/ImportManagementModel.h"
#include "model/ExportManagementModel.h"
#include "model/CategoryManegementModel.h"
#include "model/InventoryManagement.h"

#include "model/DataManagement.h"


#include "libs/json.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
using json = nlohmann::json;


int main(int argc, char** argv) {

	do
	{	
		system("CLS");
		cout << "Please choose :  " << endl;
		cout << "1. Import Management" << endl;
		cout << "2. Export Management" << endl; 
		cout << "3. Inventory Management" << endl;
		cout << "4. Category Management" << endl; 
		cout << "5. Management of Data System" << endl;
		cout << "6. Exit" << endl << endl;
        cout << "Select : ";

		int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            ImportManagementModel importModel;
			importModel.ImportManagement();
			break;
        }
        case 2:
        {
            ExportManagementModel exportModel;
			exportModel.ExportManagement();
			break;
        }
        case 3:
        {
			InventoryManagement inventory;
			inventory.MenuInventoryManagemament();
			break;
        }
        case 4:
        {
			CategoryManegementModel::getInstance()->run();
			break;
        }
		case 5:
        {
			DataManagement save_data;
			break;
        }
		case 6:
        {
			return 0;
        }
        default:
            break;
        }

	} while (1);


	
	
	return 0;
}


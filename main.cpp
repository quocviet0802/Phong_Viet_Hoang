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

#include "libs/json.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
using json = nlohmann::json;


void ImportManagement(){
	ImportManagementModel importModel;
	importModel.GetDataOrder();
	importModel.ExportReport();
	// importModel.ShowStatisticsFlowProductID(16);
	// importModel.ShowStatisticsFlowCategoryName("Beverages");
	importModel.ShowStatisticsFlowSupplierName("Around the Horn");

}


int main(int argc, char** argv) {
	ImportManagement();
	return 0;
}


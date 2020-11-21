#include "ImportManagementModel.h"

#include <iostream>
#include <vector>
using namespace std;

ImportManagementModel::ImportManagementModel(){

}

ImportManagementModel::ImportManagementModel(ShippersData shipperItem, SuppliersData suppliersItem){
    for(Suppliers item: suppliersItem.ListSuppliersData){
        if(item.SupplierID%2 == 0){
            
        }
    }
}

void ImportManagementModel::ExportReport(){
    cout << "Hello I am Import" <<endl;
}


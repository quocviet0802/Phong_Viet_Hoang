#ifndef _ImportModel_h
#define _ImportModel_h

#include <vector>
#include <string>
#include "WarehouseManagementModel.h"
#include "../dataaccess/ShippersData.h"
#include "../dataaccess/SuppliersData.h"


class ImportManagementModel: public WarehouseManagementModel{
private:
    vector<Shippers> OrderData;
    vector<Suppliers> _DataImport;

public:
    ImportManagementModel();
    ImportManagementModel(ShippersData, SuppliersData);
    int PushBack(Suppliers);
    void ExportReport();
    // void GetDataImportInOrder(vector);
};


#endif
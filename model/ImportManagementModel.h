#ifndef _ImportModel_h
#define _ImportModel_h

#include <vector>
#include <string>
#include "WarehouseManagementModel.h"
#include "../dataaccess/ShippersData.h"
#include "../dataaccess/SuppliersData.h"


class ImportManagementModel: public WarehouseManagementModel{
// private:

public:
    ImportManagementModel();
    void ExportReport();
};


#endif
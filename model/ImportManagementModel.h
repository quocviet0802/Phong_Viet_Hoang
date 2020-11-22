#ifndef _ImportModel_h
#define _ImportModel_h

#include <vector>
#include <string>
#include "WarehouseManagementModel.h"

class ImportManagementModel: public WarehouseManagementModel{
public:
    ImportManagementModel();
    ~ImportManagementModel();
    void ExportReport();

    bool ShowStatisticsFlowProductID(int);
    bool ShowStatisticsFlowCategoryName(string);
    bool ShowStatisticsFlowSupplierName(string);

};


#endif
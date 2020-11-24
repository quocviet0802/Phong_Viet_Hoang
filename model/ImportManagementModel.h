#ifndef _ImportModel_h
#define _ImportModel_h

#include <vector>
#include <string>
#include "WarehouseManagementModel.h"

class ImportManagementModel: public WarehouseManagementModel{
public:
    ImportManagementModel();
    ~ImportManagementModel();
    
    bool ShowStatisticsFollowProductID(int);
    bool ShowStatisticsFollowCategoryID(int);
    bool ShowStatisticsFollowSupplierID(int);

    void ExportReport();
    void ImportManagement();
    void InputDataToDB();
};


#endif
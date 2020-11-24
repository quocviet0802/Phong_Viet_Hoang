#ifndef _ExportModel_h
#define _ExportModel_h

#include <vector>
#include <string>
#include "WarehouseManagementModel.h"

class ExportManagementModel: public WarehouseManagementModel{
public:
    ExportManagementModel();
    ~ExportManagementModel();

    bool ShowStatisticsFollowProductID(int);
    bool ShowStatisticsFollowCategoryID(int);
    bool ShowStatisticsFollowSupplierID(int);

    void ExportReport();
    void ExportManagement();
    void InputDataToDB();
};


#endif
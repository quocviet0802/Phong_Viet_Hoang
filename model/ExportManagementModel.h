#ifndef _ExportModel_h
#define _ExportModel_h

#include <vector>
#include <string>
#include "WarehouseManagementModel.h"

class ExportManagementModel: public WarehouseManagementModel{
public:
    ExportManagementModel();
    ~ExportManagementModel();
    void ExportReport();

    bool ShowStatisticsFollowProductID(int);
    bool ShowStatisticsFollowCategoryName(string);
    bool ShowStatisticsFollowSupplierName(string);

};


#endif
#ifndef _Suppliers_Data_h
#define _Suppliers_Data_h
#include <vector>
#include <string>
#include "../businessobjects/Suppliers.h"

class SuppliersData{
public:
    int maxId;
private:
    vector<Suppliers> ListSuppliersData;
public:
    SuppliersData();
    SuppliersData(string);

    int PushBack(Suppliers);
    int Update(int, Suppliers);

    Suppliers Get(int);
    Suppliers* GetPointer(int);

    Suppliers* GetSupplierByID(int);
    Suppliers* GetSupplierByName(string);

    int GetSize();
    int ExportToFile(string);
    
    vector<Suppliers> getSuppliersDataList();
};
#endif
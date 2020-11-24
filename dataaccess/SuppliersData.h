#ifndef _Suppliers_Data_h
#define _Suppliers_Data_h
#include <vector>
#include <string>
#include<sstream>
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
    
    friend class ImportManagementModel;

    //[PHI]
    vector<Suppliers> GetSupplierList();
    bool ImportDataFromCSVFile();
    bool isIDValided(int supplierID);
    bool updateSupplierByID(int supplierID,Suppliers supplier);
    bool deleteSupplierByID(int supplierID);
    void printList();
};
#endif
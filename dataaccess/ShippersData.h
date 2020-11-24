#ifndef _Shippers_Data_h
#define _Shippers_Data_h
#include <vector>
#include <string>
#include "../businessobjects/Shippers.h"

class ShippersData{
public:
    int maxId;
private:
    vector<Shippers> ListShippersData;
public:
    ShippersData();
    ShippersData(string);

    int PushBack(Shippers);
    int Update(int, Shippers);

    Shippers Get(int);
    Shippers* GetPointer(int);

    Shippers* GetShipperByID(int);
    Shippers* GetShipperByName(string);

    int GetSize();
    int ExportToFile(string);
    friend class ImportManagementModel;

    //[PHI]
    void printList();
};
#endif
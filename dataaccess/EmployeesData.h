#ifndef _Employees_Data_h
#define _Employees_Data_h
#include <vector>
#include <iostream>
using namespace std;

#include "../businessobjects/Employees.h"

class EmployeesData{
public:
    int maxId;
private:
    vector<Employees> _data;
public:
    EmployeesData();
    EmployeesData(string);
    int PushBack(Employees);
    int Update(int, Employees);
    Employees Get(int);
    int GetSize();
    int ExportToFile(string);

    vector<Employees> getEmployeesDataList();

    //[PHI]
    void printList();

};
#endif
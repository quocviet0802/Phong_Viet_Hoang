#ifndef _DataManagement_h
#define _DataManagement_h


#include "WarehouseManagementModel.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <dirent.h>
#include <direct.h>
#include <stdio.h>
#include <conio.h>


class DataManagement{
private:
    string PathDir;
public:
    DataManagement();
    ~DataManagement();

    void SaveData(string, string);
    string GetNow();
    string GetCurrentWorkingDirectory();
    void GetListFile(const char*, string);
    const string GetCurrentDateTime();
    string CreateBackupFolder();
    void Run();

};


#endif
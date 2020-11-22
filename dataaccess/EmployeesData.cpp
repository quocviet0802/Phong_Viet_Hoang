/** @file EmployeesData.h
 *  @brief EmployeesData stores all Products objects
 *  
 *  @author Bao-Phong Le (lvbphong)
 *  @bug No known bugs.
 */

#include "EmployeesData.h"
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

EmployeesData::EmployeesData(){
    maxId = 0;
    _data.resize(0);
}

EmployeesData::EmployeesData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Employees p(
            j["EmployeeId"],
            j["LastName"],
            j["FirstName"],
            j["BirthDate"],
            j["Photo"],
            j["Notes"]
        );
        _data.push_back(p);
    }
    inFile.close();
}
/** @brief Function add a Employees object to the end of the list inside EmployeesData.
 *  
 *  Function add a Employees object to the end of the list inside EmployeesData.
 *  @return maxId of Employees object inside EmployeesData;
 */
int EmployeesData::PushBack(Employees p){
    //at first, there nothing, maxId = 0
    
    //assume p.EmployeeId = 5, then maxId = 5
    if (maxId < p.EmployeeId) maxId = p.EmployeeId;

    //add a Employees object to EmployeesData
    _data.push_back(p);
    return maxId;
}

/** @brief Function updates a Employees object at a position inside the list inside EmployeesData.
 *  
 *  Function updates a Employees object at a position inside the list inside EmployeesData.
 *  @return maxId of Employees object inside EmployeesData;
 *  if fail, return -1;
 */
int EmployeesData::Update(int i, Employees p){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = p;
    //assume p.EmployeeId = 5 and maxId = 4, then maxId = 5
    if (maxId < p.EmployeeId) maxId = p.EmployeeId;
    return maxId;
}

/** @brief Function return a EmployeeId object at a position inside the list inside EmployeesData.
 *  
 *  Function return a Employees object at a position inside the list inside EmployeesData.
 *  @return Employees object;
 *  if fail, return NULL;
 */
Employees EmployeesData::Get(int i){
    return _data[i];
}

/** @brief Function return size of EmployeesData.
 *  
 *  Function return size of EmployeesData. This is the quantity of Employees objects inside EmployeesData.
 *  @return number of Employees objects;
 */
int EmployeesData::GetSize(){
    return _data.size();
}

/** @brief Function write all data in EmployeesData to file.
 *  
 *  Function write all data in EmployeesData to file.
 *  @return 1 if success, 0 if fail;
 */
int EmployeesData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employees p:_data){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}


vector<Employees> EmployeesData::getEmployeesDataList(){
    return _data;
}

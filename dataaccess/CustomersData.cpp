/** @file CustomersData.h
 *  @brief CustomersData stores all Products objects
 *  
 *  @author Bao_Phong Le (lvbphong)
 *  @bug No known bugs.
 */

#include "CustomersData.h"
#include <fstream>
#include "../libs/json.hpp"
#include<iostream>
using namespace std;
using json = nlohmann::json;

CustomersData::CustomersData(){
    maxId = 0;
    _data.resize(0);
}

CustomersData::CustomersData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Customers p(
            j["CustomerId"],
            j["CustomerName"],
            j["ContactName"],
            j["Address"],
            j["City"],
            j["PostalCode"],
            j["Country"]
        );
        _data.push_back(p);
    }
    inFile.close();
}
/** @brief Function add a Customers object to the end of the list inside CustomersData.
 *  
 *  Function add a Customers object to the end of the list inside CustomersData.
 *  @return maxId of Customers object inside CustomersData;
 */
int CustomersData::PushBack(Customers p){
    //at first, there nothing, maxId = 0
    
    //assume p.CustomerId = 5, then maxId = 5
    if (maxId < p.CustomerId) maxId = p.CustomerId;

    //add a Customers object to CustomersData
    _data.push_back(p);
    return maxId;
}

/** @brief Function updates a Customers object at a position inside the list inside CustomersData.
 *  
 *  Function updates a Customers object at a position inside the list inside CustomersData.
 *  @return maxId of Customers object inside CustomersData;
 *  if fail, return -1;
 */
int CustomersData::Update(int i, Customers p){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = p;
    //assume p.CustomerId = 5 and maxId = 4, then maxId = 5
    if (maxId < p.CustomerId) maxId = p.CustomerId;
    return maxId;
}

/** @brief Function return a Customers object at a position inside the list inside CustomersData.
 *  
 *  Function return a Customers object at a position inside the list inside CustomersData.
 *  @return Customers object;
 *  if fail, return NULL;
 */
Customers CustomersData::Get(int i){
    return _data[i];
}

/** @brief Function return size of CustomersData.
 *  
 *  Function return size of CustomersData. This is the quantity of Customers objects inside CustomersData.
 *  @return number of Customers objects;
 */
int CustomersData::GetSize(){
    return _data.size();
}

/** @brief Function write all data in CustomersData to file.
 *  
 *  Function write all data in CustomersData to file.
 *  @return 1 if success, 0 if fail;
 */
int CustomersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Customers p:_data){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

/** @brief Print all Customer in table
 *  A function to print all Customer in table
 *  @author Phi Nguyen
 */
void CustomersData::printList()
{
    cout << " ------------------------- Customer table ----------------------------" << endl;
    cout.width(3);
    cout << "ID" << left;
    cout.width(30);
    cout << "CustomerName" << left;
    cout.width(30);
    cout << "ContactName" << left;
    cout.width(40);
    cout << "Address" << left;
    cout.width(30);
    cout << "City" << left;
    cout.width(10);
    cout << "PostalCode"<< left;
    cout.width(20);
    cout << "Country" << left << endl;
    for (Customers p : _data)
    {
        cout.width(3);
        cout << p.CustomerId << left;
        cout.width(30);
        cout << p.CustomerName << left;
        cout.width(30);
        cout << p.ContactName << left;
        cout.width(40);
        cout << p.Address << left;
        cout.width(30);
        cout << p.City << left;
        cout.width(10);
        cout << p.PostalCode << left;
        cout.width(20);
        cout << p.Country << left << endl;
    }
}


//VietMQ
vector<Customers> CustomersData::getCustomersDataList(){
    return _data;
}

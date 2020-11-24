#include "ShippersData.h"
#include <fstream>
#include "../libs/json.hpp"
#include <iostream>
using namespace std;

using json = nlohmann::json;

ShippersData::ShippersData(){
    maxId = 0;
    ListShippersData.resize(0);
}

ShippersData::ShippersData(string filename){
    maxId = 0;
    ListShippersData.resize(0);

    // open file
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];

    // create object of Shippers class with data from input file and add to ListShippersData
    while (inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Shippers Shipper(
            j["ShipperID"],
            j["ShipperName"],
            j["Phone"]
        );
        ListShippersData.push_back(Shipper);
    }
    inFile.close();
}


/** @brief Function add a Products object to the end of the list inside ProductsData.
 *  
 *  Function add a Products object to the end of the list inside ProductsData.
 *  @return maxId of Products object inside ProductsData;
 */
int ShippersData::PushBack(Shippers p){
    //at first, there nothing, maxId = 0
    
    //assume p.ShipperID = 5, then maxId = 5
    if (maxId < p.ShipperID) maxId = p.ShipperID;

    //add a Shippers object to ShippersData
    ListShippersData.push_back(p);
    return maxId;
}


/** @brief Function updates a Products object at a position inside the list inside ProductsData.
 *  
 *  Function updates a Products object at a position inside the list inside ProductsData.
 *  @return maxId of Products object inside ProductsData;
 *  if fail, return -1;
 */
int ShippersData::Update(int i, Shippers p){
    if (i < 0) return -1;
    if (i >= ListShippersData.size()) return -1;
    ListShippersData[i] = p;
    //assume p.ShipperID = 5 and maxId = 4, then maxId = 5
    if (maxId < p.ShipperID) maxId = p.ShipperID;
    return maxId;
}


/** @brief Function return a Products object at a position inside the list inside ProductsData.
 *  
 *  Function return a Products object at a position inside the list inside ProductsData.
 *  @return Products object;
 *  if fail, return NULL;
 */
Shippers ShippersData::Get(int i){
    return ListShippersData[i];
}

Shippers* ShippersData::GetPointer(int i){
    Shippers* p = nullptr;

    if (i < 0) return p;
    if (i >= ListShippersData.size()) return p;
    p = &ListShippersData[i];
    return p;
}


/** @brief Function return size of ProductsData.
 *  
 *  Function return size of ProductsData. This is the quantity of Products objects inside ProductsData.
 *  @return number of Products objects;
 */
int ShippersData::GetSize(){
    return ListShippersData.size();
}


/** @brief Function write all data in ProductsData to file.
 *  
 *  Function write all data in ProductsData to file.
 *  @return 1 if success, 0 if fail;
 */
int ShippersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Shippers p:ListShippersData){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

/** @brief Function get Shippers object with id
 *  
 *  Function get Shippers object with id
 *  @return address of a Shippers 
 */
Shippers* ShippersData::GetShipperByID(int id){
    Shippers* p = nullptr;

    for(int i = 0; i < ListShippersData.size(); i++){
        if(id == ListShippersData[i].ShipperID){
            p = &ListShippersData[i];
            break;
        }
    }
    return p;
}

/** @brief Function get Shippers object with name
 *  
 *  Function get Shippers object with name
 *  @return address of a Shippers 
 */
Shippers* ShippersData::GetShipperByName(string name){
    Shippers* p = nullptr;

    for(int i = 0; i < ListShippersData.size(); i++){
        if(name == ListShippersData[i].ShipperName){
            p = &ListShippersData[i];
            break;
        }
    }

    return p;
}

/** @brief return a List data of Shippers 
 *  A function return a vector of Shippers object
 *  @return vector include suppliers
 *  @author VietMQ
 */
vector<Shippers> ShippersData::getShippersDataList(){
    return ListShippersData;
}


/** @brief Print all shipper in table
 *  A function to print all shipper in table
 *  @author Phi Nguyen
 */
void ShippersData::printList()
{
    cout << " ------------------------- Shippers table ----------------------------" << endl;
    cout.width(3);
    cout << "ShipperID" << left;
    cout.width(40);
    cout << "ShipperName" << left;
    cout.width(40);
    cout << "Phone" << left << endl;
    for (Shippers shipper : ListShippersData)
    {
        cout.width(3);
        cout << shipper.ShipperID << left;
        cout.width(40);
        cout << shipper.ShipperName << left;
        cout.width(40);
        cout << shipper.Phone << left << endl;
    }
}


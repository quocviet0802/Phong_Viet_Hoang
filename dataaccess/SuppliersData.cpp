#include "SuppliersData.h"
#include <fstream>
#include "../libs/json.hpp"
#include <iostream>
#include <sstream>
using namespace std;

using json = nlohmann::json;

SuppliersData::SuppliersData(){
    maxId = 0;
    ListSuppliersData.resize(0);
}

SuppliersData::SuppliersData(string filename){
    maxId = 0;
    ListSuppliersData.resize(0);

    // open file
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize];

    // create object of Suppliers class with data from input file and add to ListSuppliersData
    while (inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Suppliers Supplier(
            j["SupplierID"],
            j["SupplierName"],
            j["ContactName"],
            j["Address"],
            j["City"],
            j["PostalCode"],
            j["Country"],
            j["Phone"]
        );
        maxId = maxId < Supplier.SupplierID? Supplier.SupplierID : maxId;
        ListSuppliersData.push_back(Supplier);
    }
    inFile.close();
}


/** @brief Function add a Products object to the end of the list inside ProductsData.
 *  
 *  Function add a Products object to the end of the list inside ProductsData.
 *  @return maxId of Products object inside ProductsData;
 */
int SuppliersData::PushBack(Suppliers p){
    //at first, there nothing, maxId = 0
    
    //assume p.SupplierID = 5, then maxId = 5
    if (maxId < p.SupplierID) maxId = p.SupplierID;

    //add a Suppliers object to SuppliersData
    ListSuppliersData.push_back(p);
    return maxId;
}


/** @brief Function updates a Products object at a position inside the list inside ProductsData.
 *  
 *  Function updates a Products object at a position inside the list inside ProductsData.
 *  @return maxId of Products object inside ProductsData;
 *  if fail, return -1;
 */
int SuppliersData::Update(int i, Suppliers p){
    if (i < 0) return -1;
    if (i >= ListSuppliersData.size()) return -1;
    ListSuppliersData[i] = p;
    //assume p.SupplierID = 5 and maxId = 4, then maxId = 5
    if (maxId < p.SupplierID) maxId = p.SupplierID;
    return maxId;
}


/** @brief Function return a Products object at a position inside the list inside ProductsData.
 *  
 *  Function return a Products object at a position inside the list inside ProductsData.
 *  @return Products object;
 *  if fail, return NULL;
 */
Suppliers SuppliersData::Get(int i){
    return ListSuppliersData[i];
}

Suppliers* SuppliersData::GetPointer(int i){
    Suppliers* p = nullptr;

    if (i < 0) return p;
    if (i >= ListSuppliersData.size()) return p;
    p = &ListSuppliersData[i];
    return p;
}


/** @brief Function return size of ProductsData.
 *  
 *  Function return size of ProductsData. This is the quantity of Products objects inside ProductsData.
 *  @return number of Products objects;
 */
int SuppliersData::GetSize(){
    return ListSuppliersData.size();
}


/** @brief Function write all data in ProductsData to file.
 *  
 *  Function write all data in ProductsData to file.
 *  @return 1 if success, 0 if fail;
 */
int SuppliersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Suppliers p:ListSuppliersData){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}


/** @brief Function get Suppliers object with id
 *  
 *  Function get Suppliers object with id
 *  @return address of a Suppliers 
 */
Suppliers* SuppliersData::GetSupplierByID(int id){
    Suppliers* p = nullptr;

    for(int i = 0; i < ListSuppliersData.size(); i++){
        if(id == ListSuppliersData[i].SupplierID){
            p = &ListSuppliersData[i];
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
Suppliers* SuppliersData::GetSupplierByName(string name){
    Suppliers* p = nullptr;

    for(int i = 0; i < ListSuppliersData.size(); i++){
        if(name == ListSuppliersData[i].SupplierName){
            p = &ListSuppliersData[i];
            break;
        }
    }

    return p;
}


/** @brief return a List data of Suppliers 
 *  A function return a vector of Suppliers object
 *  @return vector include suppliers
 *  @author VietMQ
 */
vector<Suppliers> SuppliersData::getSuppliersDataList(){
    return ListSuppliersData;
}


/** @brief Get all suppliers
 *  A function to get all suppliers
 *  @return vector include suppliers
 *  @author Phi Nguyen
 */
vector<Suppliers> SuppliersData::GetSupplierList()
{
    return ListSuppliersData;
}

/** @brief Import data from CSV file
 *  A function to import data from CSV file
 *  @note: just run this function one time to make Json file
 *  @return true: success | false: failed
 *  @author Phi Nguyen
 */
bool SuppliersData::ImportDataFromCSVFile()
{
    ifstream fin;
    string line;
    int pos;

    // fin.open(PATH_FILE);
    fin.open("RawDatas/SuppliersData_csv.csv");

    // Open an OrderDetails Data file
    if (!fin.is_open())
        return false;

    while (!fin.eof())
    {

        Suppliers suppliers;
        getline(fin, line);
        int numOfEle = 1;

        do
        {
            pos = line.find('|');
            string field = line.substr(0, pos);

            line = line.substr(pos + 1);

            switch (numOfEle)
            {
            case 1:
                stringstream(field) >> suppliers.SupplierID;
                maxId = suppliers.SupplierID < maxId ? maxId : suppliers.SupplierID;
                numOfEle++;
                break;
            case 2:
                suppliers.SupplierName = field;
                numOfEle++;
                break;

            case 3:
                suppliers.ContactName = field;
                numOfEle++;
                break;
            case 4:
                suppliers.Address = field;
                numOfEle++;
                break;
            case 5:
                suppliers.City = field;
                numOfEle++;
                break;
            case 6:
                suppliers.PostalCode = field;
                numOfEle++;
                break;
            case 7:
                suppliers.Country = field;
                numOfEle++;
                break;
            case 8:
                suppliers.Phone = field;
                numOfEle++;
                break;
            default:
                break;
            }
        } while (pos >= 0);

        ListSuppliersData.push_back(suppliers);
    }

    fin.close();

    return true;
}

/** @brief check ID is valided
 *  A function to check ID is valided
 *  @param supplierID(int)
 *  @return true: success | false: failed
 *  @author Phi Nguyen
 */
bool SuppliersData::isIDValided(int supplierID)
{
    for (int i = 0; i < ListSuppliersData.size(); i++)
    {
        if (ListSuppliersData[i].SupplierID == supplierID)
            return true;
    }
    return false;
}

/** @brief update supplier info by ID
 *  A function to update supplier info by ID
 *  @param 
 *        supplierID(int)
 *        supplier(Suppliers)
 *  @return true: success | false: failed
 *  @author Phi Nguyen
 */
bool SuppliersData::updateSupplierByID(int supplierID, Suppliers supplier)
{
    /* if (supplierID < 0)
        return false;
    else if (supplierID > maxId)
        return false; */

    for (int i = 0; i < ListSuppliersData.size(); i++)
    {
        if (ListSuppliersData[i].SupplierID == supplierID)
        {
            ListSuppliersData[i].SupplierName = supplier.SupplierName;
            ListSuppliersData[i].ContactName = supplier.ContactName;
            ListSuppliersData[i].City = supplier.City;
            ListSuppliersData[i].Address = supplier.Address;
            ListSuppliersData[i].Country = supplier.Country;
            ListSuppliersData[i].PostalCode = supplier.PostalCode;
            ListSuppliersData[i].Phone = supplier.Phone;
            return true;
        }
    }
    return false;
}

/** @brief delete supplier info by ID
 *  A function to delete supplier info by ID
 *  @param 
 *        supplierID(int)
 *  @return true: success | false: failed
 *  @author Phi Nguyen
 */
bool SuppliersData::deleteSupplierByID(int supplierID)
{
    /* if (supplierID < 0)
        return false;
    else if (supplierID > maxId)
        return false; */
    for (int i = 0; i < ListSuppliersData.size(); i++)
    {
        if (ListSuppliersData[i].SupplierID == supplierID)
        {
            ListSuppliersData.erase(ListSuppliersData.begin() + i);
            return true;
        }
    }

    return false;
}


/** @brief Print all supplier in table
 *  A function to print all supplier in table
 *  @author Phi Nguyen
 */
void SuppliersData::printList()
{
    cout << " ------------------------- Supplier table ----------------------------" << endl;
    for (Suppliers supplier : ListSuppliersData)
    {
        cout << supplier.ToString() << endl;
    }
}



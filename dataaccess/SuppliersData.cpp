#include "SuppliersData.h"
#include <fstream>
#include "../libs/json.hpp"
#include <iostream>
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
        ListSuppliersData.push_back(Supplier);
    }
    inFile.close();
}

int SuppliersData::PushBack(Suppliers p){
    //at first, there nothing, maxId = 0
    
    //assume p.SupplierID = 5, then maxId = 5
    if (maxId < p.SupplierID) maxId = p.SupplierID;

    //add a Suppliers object to SuppliersData
    ListSuppliersData.push_back(p);
    return maxId;
}


int SuppliersData::Update(int i, Suppliers p){
    if (i < 0) return -1;
    if (i >= ListSuppliersData.size()) return -1;
    ListSuppliersData[i] = p;
    //assume p.SupplierID = 5 and maxId = 4, then maxId = 5
    if (maxId < p.SupplierID) maxId = p.SupplierID;
    return maxId;
}


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


int SuppliersData::GetSize(){
    return ListSuppliersData.size();
}


int SuppliersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Suppliers p:ListSuppliersData){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

Suppliers* SuppliersData::GetSupplierByID(int id){
    Suppliers* p = nullptr;

    // for(Suppliers item: ListSuppliersData){
    //     if(id == item.SupplierID){
    //         p = &ListSuppliersData[item.SupplierID - 1];
    //         break;
    //     }
    // }

    for(int i = 0; i < ListSuppliersData.size(); i++){
        if(id == ListSuppliersData[i].SupplierID){
            p = &ListSuppliersData[i];
            break;
        }
    }
    return p;
}

Suppliers* SuppliersData::GetSupplierByName(string name){
    Suppliers* p = nullptr;

    // for(Suppliers item: ListSuppliersData){
    //     if(name == item.SupplierName){
    //         p = &ListSuppliersData[item.SupplierID - 1];
    //         break;
    //     }
    // }

    for(int i = 0; i < ListSuppliersData.size(); i++){
        if(name == ListSuppliersData[i].SupplierName){
            p = &ListSuppliersData[i];
            break;
        }
    }

    return p;
}


vector<Suppliers> SuppliersData::getSuppliersDataList(){
    return ListSuppliersData;
}





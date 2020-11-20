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

int ShippersData::PushBack(Shippers p){
    //at first, there nothing, maxId = 0
    
    //assume p.ShipperID = 5, then maxId = 5
    if (maxId < p.ShipperID) maxId = p.ShipperID;

    //add a Shippers object to ShippersData
    ListShippersData.push_back(p);
    return maxId;
}


int ShippersData::Update(int i, Shippers p){
    if (i < 0) return -1;
    if (i >= ListShippersData.size()) return -1;
    ListShippersData[i] = p;
    //assume p.ShipperID = 5 and maxId = 4, then maxId = 5
    if (maxId < p.ShipperID) maxId = p.ShipperID;
    return maxId;
}


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


int ShippersData::GetSize(){
    return ListShippersData.size();
}


int ShippersData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Shippers p:ListShippersData){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

Shippers* ShippersData::GetShipperByID(int id){
    Shippers* p = nullptr;

    // for(Shippers item: ListShippersData){
    //     if(id == item.ShipperID){
    //         p = &ListShippersData[item.ShipperID - 1];
    //         break;
    //     }
    // }

    for(int i = 0; i < ListShippersData.size(); i++){
        if(id == ListShippersData[i].ShipperID){
            p = &ListShippersData[i];
            break;
        }
    }
    return p;
}

Shippers* ShippersData::GetShipperByName(string name){
    Shippers* p = nullptr;

    // for(Shippers item: ListShippersData){
    //     if(name == item.ShipperName){
    //         p = &ListShippersData[item.ShipperID - 1];
    //         break;
    //     }
    // }

    for(int i = 0; i < ListShippersData.size(); i++){
        if(name == ListShippersData[i].ShipperName){
            p = &ListShippersData[i];
            break;
        }
    }

    return p;
}






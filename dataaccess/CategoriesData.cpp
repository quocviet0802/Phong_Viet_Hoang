/** @file ProductsData.h
 *  @brief ProductsData stores all Products objects
 *  
 *  @author Bao-Phong Le (lvbphong)
 *  @bug No known bugs.
 */

#include "CategoriesData.h"
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

CategoriesData::CategoriesData(){
    maxId = 0;
    _data.resize(0);
}

CategoriesData::CategoriesData(string filename){
    maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Categories p(
            j["CategoryId"],
            j["CategoryName"],
            j["Description"]
        );
        _data.push_back(p);
    }
    inFile.close();
}
/** @brief Function add a Categories object to the end of the list inside CategoriesData.
 *  
 *  Function add a Categories object to the end of the list inside CategoriesData.
 *  @return maxId of Categories object inside CategoriesData;
 */
int CategoriesData::PushBack(Categories p){
    //at first, there nothing, maxId = 0
    
    //assume p.CategoryId = 5, then maxId = 5
    if (maxId < p.CategoryId) maxId = p.CategoryId;

    //add a Categories object to CategoriesData
    _data.push_back(p);
    return maxId;
}

/** @brief Function updates a Categories object at a position inside the list inside CategoriesData.
 *  
 *  Function updates a Categories object at a position inside the list inside CategoriesData.
 *  @return maxId of Categories object inside CategoriesData;
 *  if fail, return -1;
 */
int CategoriesData::Update(int i,Categories p){
    if (i < 0) return -1;
    if (i >= _data.size()) return -1;
    _data[i] = p;
    //assume p.CategoryId = 5 and maxId = 4, then maxId = 5
    if (maxId < p.CategoryId) maxId = p.CategoryId;
    return maxId;
}

/** @brief Function return a Categories object at a position inside the list inside CategoriesData.
 *  
 *  Function return a Categories object at a position inside the list inside CategoriesData.
 *  @return Categories object;
 *  if fail, return NULL;
 */
Categories CategoriesData::Get(int i){
    return _data[i];
}

/** @brief Function return size of CategoriesData.
 *  
 *  Function return size of CategoriesData. This is the quantity of Categories objects inside CategoriesData.
 *  @return number of Categories objects;
 */
int CategoriesData::GetSize(){
    return _data.size();
}

/** @brief Function write all data in CategoriesData to file.
 *  
 *  Function write all data in CategoriesData to file.
 *  @return 1 if success, 0 if fail;
 */
int CategoriesData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Categories p:_data){
        outFile << p.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

vector<Categories> CategoriesData::getCategoriesDataList(){
    return _data;
}

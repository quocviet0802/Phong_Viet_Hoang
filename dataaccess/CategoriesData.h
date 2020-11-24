    #ifndef _Categories_Data_h
#define _Categories_Data_h
#include <vector>
#include "../businessobjects/Categories.h"
#include<iostream>
using namespace std;

class CategoriesData{
public:
    int maxId;
private:
    vector<Categories> _data;
public:
    CategoriesData();
    CategoriesData(string);
    int PushBack(Categories);
    int Update(int, Categories);
    Categories Get(int);
    int GetSize();
    int ExportToFile(string);


    //[PHI]
    vector<Categories> GetCategoryList();
    bool isIDValided(int CategoryID);
    bool updateCategoryByID(int CategoryID,Categories Category);
    bool deleteCategoryByID(int CategoryID);
    void printList();
};
#endif
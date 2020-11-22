    #ifndef _Categories_Data_h
#define _Categories_Data_h
#include <vector>
#include "../businessobjects/Categories.h"

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

    vector<Categories> getCategoriesDataList();

};
#endif
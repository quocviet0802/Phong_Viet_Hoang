/** @file ProductCategoriesManagementModel.h
 *  @brief Perform a Category management function (create,read,update and delete)
 *  
 *  @author Phi Nguyen Viet
 *  @bug No known bugs.
 */

#include"ProductCategoriesManagementModel.h"
ProductCategoriesManagementModel *ProductCategoriesManagementModel::instance = nullptr;

ProductCategoriesManagementModel::ProductCategoriesManagementModel()
{
    categoryName = "Categories";
    categoriesData = new CategoriesData("RawDatas/Categories.txt");
}

ProductCategoriesManagementModel::~ProductCategoriesManagementModel()
{
}

/** @brief a singleton function
 *  A singleton function
 *  @return pointer to ProductCategoriesManagementModel
 *  @author Phi Nguyen
 */
ProductCategoriesManagementModel *ProductCategoriesManagementModel::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ProductCategoriesManagementModel();
    }
    return instance;
}

/** @brief create and add Product Category to list
 *  A function to create and add Product Category to list
 *  @return 
 *          true: add success
 *          false: add failed
 *  @author Phi Nguyen
 */
bool ProductCategoriesManagementModel::addItem()
{
    int step = (int)CATEGORIES_PROPS::NAME;
    Categories categories;
    cout << "----------------------- ADD CATEGORY -----------------------------" << endl;
    while (step <= (int)CATEGORIES_PROPS::DESCRIPTION)
    {
        //Input all data to create a category
        //use regex to validation
        switch (step)
        {
        case (int)CATEGORIES_PROPS::NAME:
        {
            cout << "Input category name: ";
            fflush(stdin);
            getline(cin, categories.CategoryName);
            if (regex_match(categories.CategoryName, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)CATEGORIES_PROPS::DESCRIPTION:
        {
            cout << "Input description: ";
            fflush(stdin);
            getline(cin, categories.Description);
            step++;
            break;
        }

        default:
            break;
        }
    }
    //Push to list and save to file
    categories.CategoryId = categoriesData->maxId + 1;
    categoriesData->PushBack(categories);

    return categoriesData->ExportToFile("RawDatas/CategoriesData.json");
}

/** @brief show all category data
 *  A function to show all category data
 *  @author Phi Nguyen
 */
void ProductCategoriesManagementModel::showItemList()
{
    cout << "----------------------- CATEGORY LIST -----------------------------" << endl;
    cout.width(3);
    cout << "ID" << left;
    cout.width(30);
    cout << "CategoryName" << left;
    cout.width(100);
    cout << "Description" << left << endl;;


    for (int i = 0; i < categoriesData->GetSize(); i++)
    {
        cout << setw(3) << categoriesData->GetCategoryList().at(i).CategoryId
             << setw(40) << categoriesData->GetCategoryList().at(i).CategoryName
             << setw(100) << categoriesData->GetCategoryList().at(i).Description<< left << endl;
    }
}

/** @brief update category data
 *  A function to update category data
 *  @return 
 *          true: update success
 *          false: update failed
 *  @author Phi Nguyen
 */
bool ProductCategoriesManagementModel::updateItem()
{
    int step = (int)CATEGORIES_PROPS::ID;
    Categories category;
    cout << "----------------------- UPDATE CATEGORY -----------------------------" << endl;

    while (step <= (int)CATEGORIES_PROPS::DESCRIPTION)
    {
        //Input all data to update a category
        //use regex to validation
        switch (step)
        {
        case (int)CATEGORIES_PROPS::ID:
        {
            cout << "Input CategoryId" << endl;
            cin >> category.CategoryId;
            if (!categoriesData->isIDValided(category.CategoryId))
                cout << "Invalid ID.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)CATEGORIES_PROPS::NAME:
        {
            cout << "Input category name: ";
            fflush(stdin);
            getline(cin, category.CategoryName);
            if (regex_match(category.CategoryName, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)CATEGORIES_PROPS::DESCRIPTION :
        {
            cout << "Input description name: ";
            fflush(stdin);
            getline(cin, category.Description);
            step++;
            break;
        }

        default:
            break;
        }
    }
    //update and save to file
    categoriesData->updateCategoryByID(category.CategoryId, category);

    return categoriesData->ExportToFile("RawDatas/CategoriesData.json");
}

/** @brief delete category data
 *  A function to delete category data
 *  @return 
 *          true: delete success
 *          false: delete failed
 *  @author Phi Nguyen
 */
bool ProductCategoriesManagementModel::deleteItem()
{
    int categoryId;
    showItemList();
    cout << endl;
    cout << "Input category id you want to delete: ";
    cin >> categoryId;

    return categoriesData->deleteCategoryByID(categoryId) && categoriesData->ExportToFile("RawDatas/CategoriesData.json");
}
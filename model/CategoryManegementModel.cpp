/** @file CategoryManegementModel.h
 *  @brief Perform category management function
 *      Call another management model to excute management function
 *  @author Phi Nguyen Viet
 *  @bug No known bugs.
 */

#include "CategoryManegementModel.h"

CategoryManegementModel *CategoryManegementModel::instance = nullptr;
CategoryManegementModel::CategoryManegementModel(/* args */)
{
    supplierManagementModel = SupplierManagementModel::getInstance();
    productCategoriesManagementModel = ProductCategoriesManagementModel::getInstance();
}

CategoryManegementModel::~CategoryManegementModel()
{
}

/** @brief Singleton function
 *  
 *  @return 
 *          pointer to CategoryManegementModel
 *  @author Phi Nguyen
 */
CategoryManegementModel *CategoryManegementModel::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CategoryManegementModel();
    }
    return instance;
}

/** @brief show all selection
 *      A function to show all selection
 *  @author Phi Nguyen
 */
void CategoryManegementModel::run()
{
    int categoryFunctionSeleted;

    while (categoryFunctionSeleted != (int)CATEGORY_FUNCTION::BACK)
    {
        while (true)
        {
            cout << "----------------------- CATEGORY MANAGEMENT -----------------------------" << endl;
            cout << "1.Supplier management" << endl;
            cout << "2.Categories management" << endl;
            cout << "3.Show table" << endl;
            cout << "4.Back" << endl;
            cout << "Select: ";
            cin >> categoryFunctionSeleted;

            system("cls");
            if (categoryFunctionSeleted > (int)CATEGORY_FUNCTION::BACK || categoryFunctionSeleted < (int)CATEGORY_FUNCTION::SUPPLIER_MANAGEMENT)
            {
                cout << "Out of selection.Please select again!!!" << endl;
                cout << endl;
            }
            else
                break;
        }

        //Excute each function
        switch (categoryFunctionSeleted)
        {
        case (int)CATEGORY_FUNCTION::SUPPLIER_MANAGEMENT:
        {
            supplierManagementModel->run();
            break;
        }

        case (int)CATEGORY_FUNCTION::CATEGORIES_MANAGEMENT:
        {
            productCategoriesManagementModel->run();
            break;
        }

        case (int)CATEGORY_FUNCTION::SHOW_LIST:
        {
            TableManagementModel tableManagementModel;
            tableManagementModel.run();
            break;
        }

        case (int)CATEGORY_FUNCTION::BACK:
        {
            break;
        }

        default:
            break;
        }
    }
}
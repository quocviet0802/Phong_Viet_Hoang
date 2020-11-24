/** @file CRUDManagementModel.h
 *  @brief Base class of Management class
 *      derived class must override 4 methods show-add-update-delete
 *  @author Phi Nguyen Viet
 *  @bug No known bugs.
 */

#include "CRUDManagementModel.h"

CRUDManagementModel::CRUDManagementModel(/* args */)
{
}

CRUDManagementModel::~CRUDManagementModel()
{
}

/** @brief show all selection
 *  A function to show all selection
 *  @author Phi Nguyen
 */
void CRUDManagementModel::run()
{
    int seleted = -1;

    while (seleted != (int)CRUD::BACK)
    {
        while (true)
        {
            cout << "----------------------- " << categoryName << " management -----------------------------" << endl;
            cout << "1.Show " << categoryName << " list" << endl;
            cout << "2.Add " << categoryName << endl;
            cout << "3.Update " << categoryName << endl;
            cout << "4.Delete " << categoryName << endl;
            cout << "5.Back" << endl;
            cout << "Select: ";
            cin >> seleted;

            cout << "\e[1;1H\e[2J";
            if (seleted > (int)CRUD::BACK || seleted < (int)CRUD::SHOW)
            {
                cout << "Out of selection.Please select again!!!" << endl;
                cout << endl;
            }
            else
                break;
        }

        switch (seleted)
        {
        case (int)CRUD::SHOW:
        {
            showItemList();
            break;
        }

        case (int)CRUD::ADD:
        {
            if (addItem())
                cout << "ADD SUCCESS" << endl;
            else
                cout << "ADD FAILED" << endl;
            break;
        }

        case (int)CRUD::UPDATE:
        {
            if (updateItem())
                cout << "UPDATE SUCCESS" << endl;
            else
                cout << "UPDATE FAILED" << endl;
            break;
        }

        case (int)CRUD::DELETE:
        {
            if (deleteItem())
                cout << "DELETE SUCCESS" << endl;
            else
                cout << "DELETE FAILED" << endl;
            break;
        }

        case (int)CRUD::BACK:
        {
            cout << "BACK" << endl;
            break;
        }

        default:
            break;
        }
    }
}
void CRUDManagementModel::showItemList()
{
    cout << "Show item" << endl;
}


bool CRUDManagementModel::addItem()
{
    cout << "add item" << endl;
    return true;
}

bool CRUDManagementModel::updateItem()
{
    cout << "update item" << endl;
    return true;

}

bool CRUDManagementModel::deleteItem()
{
    cout << "delete item" << endl;
    return true;

}
/** @file SupplierManagementModel.h
 *  @brief Perform a Supplier management function (create,read,update and delete)
 *  
 *  @author Phi Nguyen Viet
 *  @bug No known bugs.
 */

#include "SupplierManagementModel.h"
SupplierManagementModel *SupplierManagementModel::instance = nullptr;

SupplierManagementModel::SupplierManagementModel(/* args */)
{
    categoryName = "Supplier";
    suppliersData = new SuppliersData(filename);
}

SupplierManagementModel::~SupplierManagementModel()
{
}

/** @brief a singleton function
 *  A singleton function
 *  @return pointer to SupplierManagementModel
 *  @author Phi Nguyen
 */
SupplierManagementModel *SupplierManagementModel::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SupplierManagementModel();
    }
    return instance;
}

/** @brief create and add supplier to list
 *  A function to create and add supplier to list
 *  @return 
 *          true: add success
 *          false: add failed
 *  @author Phi Nguyen
 */
bool SupplierManagementModel::addItem()
{
    int step = (int)SUPPLIER_PROPS::NAME;
    Suppliers supplier;
    cout << "----------------------- ADD SUPPLIER -----------------------------" << endl;
    while (step <= (int)SUPPLIER_PROPS::PHONE)
    {
        //Input all data to create a supplier
        //use regex to validation
        switch (step)
        {
        case (int)SUPPLIER_PROPS::NAME:
        {
            cout << "Input supplier name: ";
            fflush(stdin);
            getline(cin, supplier.SupplierName);
            if (regex_match(supplier.SupplierName, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::CONTACT_NAME:
        {
            cout << "Input contact name: ";
            fflush(stdin);
            getline(cin, supplier.ContactName);
            if (regex_match(supplier.ContactName, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::ADDRESS:
        {
            cout << "Input address: ";
            fflush(stdin);
            getline(cin, supplier.Address);
            if (regex_match(supplier.Address, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::CITY:
        {
            cout << "Input city: ";
            fflush(stdin);
            getline(cin, supplier.City);
            if (regex_match(supplier.City, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::POSTAL_CODE:
        {
            cout << "Input postal code: ";
            fflush(stdin);
            getline(cin, supplier.PostalCode);
            step++;
            break;
        }
        case (int)SUPPLIER_PROPS::COUNTRY:
        {
            cout << "Input country: ";
            fflush(stdin);
            getline(cin, supplier.Country);
            if (regex_match(supplier.Country, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::PHONE:
        {
            cout << "Input phone: ";
            fflush(stdin);
            getline(cin, supplier.Phone);
            if (regex_match(supplier.Phone, regex("[a-zA-Z]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }

        default:
            break;
        }
    }

    //Push to list and save to file
    supplier.SupplierID = suppliersData->maxId + 1;
    suppliersData->PushBack(supplier);

    return suppliersData->ExportToFile(filename);
}

/** @brief show all supplier data
 *  A function to show all supplier data
 *  @author Phi Nguyen
 */
void SupplierManagementModel::showItemList()
{
    cout << "----------------------- SUPPLIER LIST -----------------------------" << endl;
    cout.width(3);
    cout << "ID" << left;
    cout.width(40);
    cout << "SupplierName" << left;
    cout.width(30);
    cout << "ContactName" << left;
    cout.width(35);
    cout << "Address" << left;
    cout.width(15);
    cout << "City" << left;
    cout.width(11);
    cout << "PostalCode" << left;
    cout.width(15);
    cout << "Country" << left;
    cout.width(15);
    cout << "Phone" << left << endl;

    for (int i = 0; i < suppliersData->GetSize(); i++)
    {
        cout << setw(3) << suppliersData->GetSupplierList().at(i).SupplierID
             << setw(40) << suppliersData->GetSupplierList().at(i).SupplierName
             << setw(30) << suppliersData->GetSupplierList().at(i).ContactName
             << setw(35) << suppliersData->GetSupplierList().at(i).Address
             << setw(15) << suppliersData->GetSupplierList().at(i).City
             << setw(11) << suppliersData->GetSupplierList().at(i).PostalCode
             << setw(15) << suppliersData->GetSupplierList().at(i).Country
             << setw(15) << suppliersData->GetSupplierList().at(i).Phone << left << endl;
    }
}

/** @brief update supplier data
 *  A function to update supplier data
 *  @return 
 *          true: update success
 *          false: update failed
 *  @author Phi Nguyen
 */
bool SupplierManagementModel::updateItem()
{
    int step = (int)SUPPLIER_PROPS::ID;
    int supplierID;
    Suppliers supplier;
    cout << "----------------------- UPDATE SUPPLIER -----------------------------" << endl;

    while (step <= (int)SUPPLIER_PROPS::PHONE)
    {
        //Input all data to update a supplier
        //use regex to validation
        switch (step)
        {
        case (int)SUPPLIER_PROPS::ID:
        {
            cout << "Input SupplierID" << endl;
            cin >> supplier.SupplierID;
            if (!suppliersData->isIDValided(supplier.SupplierID))
                cout << "Invalid ID.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::NAME:
        {
            cout << "Input supplier name: ";
            fflush(stdin);
            getline(cin, supplier.SupplierName);
            if (regex_match(supplier.SupplierName, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::CONTACT_NAME:
        {
            cout << "Input contact name: ";
            fflush(stdin);
            getline(cin, supplier.ContactName);
            if (regex_match(supplier.ContactName, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::ADDRESS:
        {
            cout << "Input address: ";
            fflush(stdin);
            getline(cin, supplier.Address);
            if (regex_match(supplier.Address, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::CITY:
        {
            cout << "Input city: ";
            fflush(stdin);
            getline(cin, supplier.City);
            if (regex_match(supplier.City, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::POSTAL_CODE:
        {
            cout << "Input postal code: ";
            fflush(stdin);
            getline(cin, supplier.PostalCode);
            step++;
            break;
        }
        case (int)SUPPLIER_PROPS::COUNTRY:
        {
            cout << "Input country: ";
            fflush(stdin);
            getline(cin, supplier.Country);
            if (regex_match(supplier.Country, regex("[0-9]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }
        case (int)SUPPLIER_PROPS::PHONE:
        {
            cout << "Input phone: ";
            fflush(stdin);
            getline(cin, supplier.Phone);
            if (regex_match(supplier.Phone, regex("[a-zA-Z]")))
                cout << "Invalid.Please input again!!!" << endl;
            else
                step++;
            break;
        }

        default:
            break;
        }
    }

    //update and save to file
    suppliersData->updateSupplierByID(supplier.SupplierID, supplier);

    return suppliersData->ExportToFile(filename);
}

/** @brief delete supplier data
 *  A function to delete supplier data
 *  @return 
 *          true: delete success
 *          false: delete failed
 *  @author Phi Nguyen
 */
bool SupplierManagementModel::deleteItem()
{
    int supplierID;
    showItemList();
    cout << endl;
    cout << "Input supplier id you want to delete: ";
    cin >> supplierID;

    //delete supplier and save to file
    return suppliersData->deleteSupplierByID(supplierID) && suppliersData->ExportToFile(filename);
}
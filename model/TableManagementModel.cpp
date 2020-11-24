/** @file TableManagementModel.h
 *  @brief Perform show table function
 *  
 *  @author Phi Nguyen Viet
 *  @bug No known bugs.
 */

#include"TableManagementModel.h"


TableManagementModel::TableManagementModel(/* args */)
{
}

TableManagementModel::~TableManagementModel()
{
}

/** @brief Show table depend on selection
 *  A function to show table
 *  @author Phi Nguyen
 */
void TableManagementModel::run()
{
    int selected = -1;
    while(selected != (int)TABLE::BACK)
    {
        while (true)
        {
            cout<<"1.CUSTOMER"<<endl;
            cout<<"2.CATEGORY"<<endl;
            cout<<"3.EMPLOYEE"<<endl;
            cout<<"4.ORDERDETAIL"<<endl;
            cout<<"5.ORDER"<<endl;
            cout<<"6.PRODUCT"<<endl;
            cout<<"7.SHIPPER"<<endl;
            cout<<"8.SUPPLIER"<<endl;
            cout<<"9.BACK"<<endl;
            cout<<"Input the table you want to show: ";
            cin >> selected;

            cout << "\e[1;1H\e[2J";
            if(selected < (int)TABLE::CUSTOMER || selected > (int)TABLE::BACK) cout<<"Out of selection. Please select again!!!"<<endl;
            else break;
        }

        switch (selected)
        {
        case (int)TABLE::CUSTOMER:
        {
            //FIXME:
            CustomersData customerData("RawDatas/Customers.txt");
            customerData.printList();
            break;
        }
        case (int)TABLE::CATEGORY :
        {
            CategoriesData categoriesData("RawDatas/Categories.txt");
            categoriesData.printList();
            break;
        }
        case (int)TABLE::EMPLOYEE :
        {
            //FIXME: 
            EmployeesData employeesData("RawDatas/Employees.txt");
            cout<< "size: "<< employeesData.GetSize()<<endl;
            employeesData.printList();
            break;
        }
        case (int)TABLE::ORDERDETAIL :
        {
            OrderDetailsData::getInstance()->importDataFromJsonFile();
            OrderDetailsData::getInstance()->printList();
            break;
        }
        case (int)TABLE::ORDER :
        {
            OrdersData::getInstance()->importDataFromJsonFile();
            OrdersData::getInstance()->printList();
            break;
        }
        case (int)TABLE::PRODUCT :
        {
            ProductsData::getInstance()->importDataFromJsonFile();
            ProductsData::getInstance()->printList();
            break;
        }
        case (int)TABLE::SHIPPER :
        {
            //FIXME:
            ShippersData shippersData("RawDatas/Shippers.txt");
            shippersData.printList();
            break;
        }
        case (int)TABLE::SUPPLIER :
        {
            //FIXME:
            SuppliersData suppliersData("RawDatas/Suppliers.txt");
            suppliersData.printList();
            break;
        }
        case (int)TABLE::BACK :
        {
            cout << "\e[1;1H\e[2J";
            break;
        }
           
        default:
            break;
        }
        
    }
}
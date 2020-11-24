#include "OrdersData.h"
OrdersData *OrdersData::instance = NULL;
OrdersData::OrdersData()
{
    maxID = 0;
}

/** @brief Singleton function
*   Function returns ifsefl
*   @return instance of OrdersData
*/ 
OrdersData *OrdersData::getInstance()
{
    if (instance == NULL)
    {
        instance = new OrdersData();
    }
    return instance;
}

OrdersData::~OrdersData()
{
}


/** @brief Import data from CSV file to OrderDataList
*   Function import data from CSV file to OrderDataList
*   @return true: import success
*           false: import failed
*/ 
bool OrdersData::importDataFromCSVFile()
{
    ifstream fin;
    string line;
    int pos;

    // Open an Order Data file
    // fin.open(PATH_FILE);
    fin.open("RawDatas/OrdersData_csv.csv");
    
    
    if (!fin.is_open())
        return false;

    while (!fin.eof())
    {

        Order order;

        //Get data line
        getline(fin, line);

        //Postion of elements
        int numOfEle = 1; 

        do
        {
            //Find "|" postion and get string from 0 -> pos
            pos = line.find('|');
            string field = line.substr(0, pos);

            //erase string has been retrieved from line
            line = line.substr(pos + 1);

            switch (numOfEle)
            {
            case 1: //First element
                //cast string to int
                stringstream(field) >> order.OrderID;
                //Increasing maxID
                maxID = order.OrderID < maxID ? maxID : order.OrderID;
                numOfEle++;
                break;
            case 2: //Second element
                stringstream(field) >> order.CustomerID;
                numOfEle++;
                break;
            case 3: //Third element
                stringstream(field) >> order.EmployeeID;
                numOfEle++;
                break;
            case 4: //Fourth element
                order.OrderDate = field;
                numOfEle++;
                break;
            case 5: //Fifth element
                stringstream(field) >> order.ShipperID;
                numOfEle++;
                break;
            default:
                break;
            }
        } while (pos >= 0);

        //push order to list
        OrderList.push_back(order);
    }

    fin.close();

    return true;
}

/** @brief Import data from Json file to OrderDataList
*   Function import data from Json file to OrderDataList
*   @return true: import success
*           false: import failed
*/ 
bool OrdersData::importDataFromJsonFile()
{
    maxID = 0;
    ifstream inFile("RawDatas/OrdersData.json");

    //return false if cannot open it
    if (!inFile.is_open())
        return false;

    //Max of character in a line
    const int maxSize = 255;
    char buff[maxSize + 1];

    //Get a data line and add into buffer
    while (inFile.getline(buff, maxSize))
    {
        // parsing to json object
        json jObject = json::parse(buff);
        int OrderID,CustomerID,EmployeeID,ShipperID;

        stringstream(jObject["OrderID"].dump()) >> OrderID;
        stringstream(jObject["CustomerID"].dump()) >> CustomerID;
        stringstream(jObject["EmployeeID"].dump()) >> EmployeeID;
        stringstream(jObject["ShipperID"].dump()) >> ShipperID;

        //Create a order with infomations from json object
        Order order(OrderID, CustomerID, EmployeeID, jObject["OrderDate"].dump(), ShipperID);
        maxID = OrderID < maxID ? maxID : OrderID;
        OrderList.push_back(order);
    }
    return true;
}

/** @brief Export data from OrderList to Json file
*   Function export data from OrderList to Json file
*   @return true: export success
*           false: export failed
*/ 
bool OrdersData::exportDataToFile()
{
    ofstream outFile;
    outFile.open("RawDatas/OrdersData.json", ios::out);
    //return false if cannot open it
    if (!outFile)
        return false;

    // get each order and parse to json then save to file
    for (Order order : OrderList)
    {
        outFile << order.toJson() << endl;
    }
    outFile.close();

    return true;
}

/** @brief Get order by OrderID
*   Function get order informations by OrderID
*   @param 
*      OrderID: id of order
*   @return pointer Order if found
*           nullptr if cannot found
*/ 
Order *OrdersData::getOrderByID(int orderID)
{
    Order *order = nullptr;

    //return nullptr if out of list size
    if (orderID < 0 || orderID >= OrderList.size())
        return order;
    for (int i = 0; i < OrderList.size(); i++)
    {
        if (OrderList[i].OrderID == orderID)
            order = &OrderList[i];
    }
    return order;
}

/** @brief Create a new order
*   Function create a new order
*   @param 
*      OrderID: id of order
*   @return pointer Order if found
*           nullptr if cannot found
*/ 
int OrdersData::createOrder(int CustomerID, int EmployeeID, string OrderDate, int ShipperID)
{
    Order order(++maxID, CustomerID, EmployeeID, OrderDate, ShipperID);
    OrderList.push_back(order);
    return maxID;
}

bool OrdersData::updateOrder(int OrderID, int CustomerID, int EmployeeID, string OrderDate, int ShipperID)
{
    for (int i = 0; i < OrderList.size(); i++)
    {
        if (OrderList[i].OrderID == OrderID)
        {
            OrderList[i].OrderID = OrderID;
            OrderList[i].CustomerID = CustomerID;
            OrderList[i].EmployeeID = EmployeeID;
            OrderList[i].OrderDate = OrderDate;
            OrderList[i].ShipperID = ShipperID;
            return true;
        }
    }
    return false;
}

bool OrdersData::deleteOrder(int OrderID)
{
    for (int i = 0; i < OrderList.size(); i++)
    {
        if (OrderList[i].OrderID == OrderID)
        {
            OrderList.erase(OrderList.begin() + i);
            return true;
        }
    }
    return false;
}

void OrdersData::printAll()
{
    cout << "order list" << endl;
    for (Order order : OrderList)
    {
        cout << "{" << order.OrderID << " , " << order.CustomerID << " , " << order.EmployeeID << " , " << order.OrderDate << " , " << order.ShipperID << endl;
    }
}

vector<Order> OrdersData::getOrderList()
{
    return OrderList;
}


/** @brief Print all Order in table
 *  A function to print all Order in table
 *  @author Phi Nguyen
 */
void OrdersData::printList()
{
    cout << " ------------------------- Order table ----------------------------" << endl;
    for (Order order : OrderList)
    {
        cout << order.OrderID << " "
             << order.EmployeeID << " "
             << order.EmployeeID << " "
             << order.OrderDate << " "
             << order.ShipperID << " " << endl;
    }
}
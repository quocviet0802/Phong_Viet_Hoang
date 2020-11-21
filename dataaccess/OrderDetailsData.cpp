#include "OrderDetailsData.h"


OrderDetailsData *OrderDetailsData::instance = NULL;
OrderDetailsData::OrderDetailsData()
{
    maxID = 0;
}

OrderDetailsData *OrderDetailsData::getInstance()
{
    if (instance == NULL)
    {
        instance = new OrderDetailsData();
    }
    return instance;
}

OrderDetailsData::~OrderDetailsData()
{
}

bool OrderDetailsData::importDataFromCSVFile()
{
    ifstream fin;
    string line;
    int pos;

    // fin.open(PATH_FILE);
    fin.open("RawDatas/OrderDetailsData_csv.csv");

    // Open an OrderDetails Data file
    if (!fin.is_open())
        return false;

    while (!fin.eof())
    {

        OrderDetails orderDetail;
        getline(fin, line);
        int numOfEle = 1;

        do
        {
            pos = line.find('|');
            string field = line.substr(0, pos);

            line = line.substr(pos + 1);

            switch (numOfEle)
            {
            case 1:
                stringstream(field) >> orderDetail.OrderDetailID;
                maxID = orderDetail.OrderDetailID < maxID ? maxID : orderDetail.OrderDetailID;
                numOfEle++;
                break;
            case 2:
                stringstream(field) >> orderDetail.OrderID;
                numOfEle++;
                break;

            case 3:
                stringstream(field) >> orderDetail.ProductID;
                numOfEle++;
                break;
            case 4:
                stringstream(field) >> orderDetail.Quantity;
                numOfEle++;
                break;
            default:
                break;
            }
        } while (pos >= 0);

        OrderDetailsList.push_back(orderDetail);
    }

    fin.close();

    return true;
}

bool OrderDetailsData::importDataFromJsonFile()
{
    maxID = 0;
    ifstream inFile("RawDatas/OrderDetailsData.json");
    if (!inFile.is_open())
        return false;

    const int maxSize = 255;
    char buff[maxSize + 1];

    while (inFile.getline(buff, maxSize))
    {
        json jObject = json::parse(buff);
        int OrderDetailID = 0,OrderID,ProductID,Quantity;

        stringstream(jObject["OrderID"].dump()) >> OrderID;
        stringstream(jObject["ProductID"].dump()) >> ProductID;
        stringstream(jObject["Quantity"].dump()) >> Quantity;
        stringstream(jObject["OrderDetailID"].dump()) >> OrderDetailID;


        OrderDetails orderDetail(OrderDetailID, OrderID,ProductID,Quantity);
        maxID = OrderDetailID < maxID ? maxID : OrderDetailID;
        OrderDetailsList.push_back(orderDetail);
    }
    return true;
}

bool OrderDetailsData::exportDataToFile()
{
    ofstream outFile;
    outFile.open("RawDatas/OrderDetailsData.json", ios::out);
    if (!outFile)
        return false;

    for (OrderDetails orderDetail : OrderDetailsList)
    {
        outFile << orderDetail.toJson() << endl;
    }
    outFile.close();

    return true;
}

OrderDetails *OrderDetailsData::getOrderDetailsByID(int OrderDetailID)
{
    OrderDetails *orderDetail = nullptr;
    if (OrderDetailID < 0 || OrderDetailID >= OrderDetailsList.size())
        return orderDetail;
    for (int i = 0; i < OrderDetailsList.size(); i++)
    {
        if (OrderDetailsList[i].OrderDetailID == OrderDetailID)
            orderDetail = &OrderDetailsList[i];
    }
    return orderDetail;
}

int OrderDetailsData::createOrderDetail(int OrderID,int ProductID,int Quantity)
{
    OrderDetails orderDetail(++maxID, OrderID, ProductID,Quantity);
    OrderDetailsList.push_back(orderDetail);
    return maxID;
}

bool OrderDetailsData::updateOrderDetail(int OrderDetailID,int OrderID,int ProductID,int Quantity)
{
    for (int i = 0; i < OrderDetailsList.size(); i++)
    {
        if (OrderDetailsList[i].OrderDetailID == OrderDetailID)
        {
            OrderDetailsList[i].OrderID = OrderID;
            OrderDetailsList[i].ProductID = ProductID;
            OrderDetailsList[i].Quantity = Quantity;
            return true;
        }
    }
    return false;
}

bool OrderDetailsData::deleteOrderDetail(int OrderDetailID)
{
    for (int i = 0; i < OrderDetailsList.size(); i++)
    {
        if (OrderDetailsList[i].OrderDetailID == OrderDetailID)
        {
            OrderDetailsList.erase(OrderDetailsList.begin() + i);
            return true;
        }
    }
    return false;
}

void OrderDetailsData::printAll()
{
    cout << "OrderDetail list" << endl;
    for (OrderDetails orderDetail : OrderDetailsList)
    {
        cout << "{" << orderDetail.OrderDetailID << " , " << orderDetail.OrderID << " , " << orderDetail.ProductID << " , " << orderDetail.Quantity <<endl;
    }
}

// vector<OrderDetails> OrderDetailsData::getOrderDetailsList()
// {
//     return OrderDetailsList;
// }
#include "ProductsData.h"
ProductsData *ProductsData::instance = NULL;
ProductsData::ProductsData()
{
    maxID = 0;
}

/** @brief Singleton function
*   Function returns ifsefl
*   @return instance of ProductsData
*/ 
ProductsData *ProductsData::getInstance()
{
    if (instance == NULL)
    {
        instance = new ProductsData();
    }
    return instance;
}

ProductsData::~ProductsData()
{
}


/** @brief Import data from CSV file to ProductList
*   Function import data from CSV file to ProductList
*   @return true: import success
*           false: import failed
*/ 
bool ProductsData::importDataFromCSVFile()
{
    ifstream fin;
    string line;
    int pos;

    // Open an Product Data file
    // fin.open(PATH_FILE);
    fin.open("RawDatas/ProductsData_csv.csv");
    
    
    if (!fin.is_open())
        return false;

    while (!fin.eof())
    {

        Product Product;

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

            cout<<"field : "<<field<<endl;
            switch (numOfEle)
            {
            case 1: //First element
                //cast string to int
                stringstream(field) >> Product.ProductID;
                //Increasing maxID
                maxID = Product.ProductID < maxID ? maxID : Product.ProductID;
                numOfEle++;
                break;
            case 2: //Second element
                Product.ProductName = field;
                numOfEle++;
                break;
            case 3: //Third element
                stringstream(field) >> Product.SupplierID;
                numOfEle++;
                break;
            case 4: //Fourth element
                stringstream(field) >> Product.CategoryID;
                numOfEle++;
                break;
            case 5: //Fifth element
                Product.Unit = field;
                numOfEle++;
                break;
            case 6: //Sixth element
                stringstream(field) >> Product.Price;
                numOfEle++;
                break;
            default:
                break;
            }
        } while (pos >= 0);

        //push Product to list
        ProductList.push_back(Product);
    }

    fin.close();

    return true;
}

/** @brief Import data from Json file to ProductList
*   Function import data from Json file to ProductList
*   @return true: import success
*           false: import failed
*/ 
bool ProductsData::importDataFromJsonFile()
{
    maxID = 0;
    ifstream inFile("RawDatas/ProductsData.json");

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
        json j = json::parse(buff);
        
        Product product(
            j["ProductID"],
            j["ProductName"],
            j["SupplierID"],
            j["CategoryID"],
            j["Unit"],
            j["Price"]
        );

        int ProductID;

        stringstream(j["ProductID"].dump()) >> ProductID;

        //Create a Product with infomations from json object
        maxID = ProductID < maxID ? maxID : ProductID;
        ProductList.push_back(product);
    }
    return true;
}

/** @brief Export data from ProductList to Json file
*   Function export data from ProductList to Json file
*   @return true: export success
*           false: export failed
*/ 
bool ProductsData::exportDataToFile()
{
    ofstream outFile;
    outFile.open("RawDatas/ProductsData.json", ios::out);
    //return false if cannot open it
    if (!outFile)
        return false;

    // get each Product and parse to json then save to file
    for (Product Product : ProductList)
    {
        outFile << Product.toJson() << endl;
    }
    outFile.close();

    return true;
}

/** @brief Get Product by ProductID
*   Function get Product informations by ProductID
*   @param 
*      ProductID: id of Product
*   @return pointer Product if found
*           nullptr if cannot found
*/ 
Product *ProductsData::getProductByID(int ProductID)
{
    Product *Product = nullptr;

    //return nullptr if out of list size
    if (ProductID < 0 || ProductID >= ProductList.size())
        return Product;
    for (int i = 0; i < ProductList.size(); i++)
    {
        if (ProductList[i].ProductID == ProductID)
            Product = &ProductList[i];
    }
    return Product;
}

/** @brief Create a new Product
*   Function create a new Product
*   @param 
*      ProductID:(int) id of Product
*   @return pointer Product if found
*           nullptr if cannot found
*/ 
int ProductsData::createProduct(string ProductName,int SupplierID,int CategoryID,string Unit,double Price)
{
    Product Product(++maxID, ProductName, SupplierID, CategoryID, Unit,Price);
    ProductList.push_back(Product);
    return maxID;
}

/** @brief Create a new Product
*   Function create a new Product
*   @param 
*      ProductID:(int) id of Product
*   @return pointer Product if found
*           nullptr if cannot found
*/
bool ProductsData::updateProduct(int ProductID,string ProductName,int SupplierID,int CategoryID,string Unit,double Price)
{
    for (int i = 0; i < ProductList.size(); i++)
    {
        if (ProductList[i].ProductID == ProductID)
        {
            ProductList[i].ProductID = ProductID;
            ProductList[i].ProductName = ProductName;
            ProductList[i].SupplierID = SupplierID;
            ProductList[i].CategoryID = CategoryID;
            ProductList[i].Unit = Unit;
            ProductList[i].Price = Price;
            return true;
        }
    }
    return false;
}

bool ProductsData::deleteProduct(int ProductID)
{
    for (int i = 0; i < ProductList.size(); i++)
    {
        if (ProductList[i].ProductID == ProductID)
        {
            ProductList.erase(ProductList.begin() + i);
            return true;
        }
    }
    return false;
}

void ProductsData::printAll()
{
    cout << "Product list" << endl;
    for (Product Product : ProductList)
    {
        cout << "{" << Product.ProductID << " , " << Product.ProductName << " , " 
        << Product.SupplierID << " , " << Product.CategoryID << " , " << Product.Unit << " , " << Product.Price<< endl;
    }
}

vector<Product> ProductsData::getProductList()
{
    return ProductList;
}


/** @brief Print all product in table
 *  A function to print all product in table
 *  @author Phi Nguyen
 */
void ProductsData::printList()
{
    cout << " ------------------------- Product table ----------------------------" << endl;
    cout.width(3);
    cout << "ID" << left;
    cout.width(50);
    cout << "ProductName" << left;
    cout.width(20);
    cout << "SupplierID" << left;
    cout.width(20);
    cout << "CategoryID" << left;
    cout.width(30);
    cout << "Unit" << left;
    cout.width(10);
    cout << "Price" << left << endl;
    for (Product product : ProductList)
    {
        cout.width(3);
        cout << product.ProductID << left;
        cout.width(50);
        cout << product.ProductName << left;
        cout.width(20);
        cout << product.SupplierID << left;
        cout.width(20);
        cout << product.CategoryID << left;
        cout.width(30);
        cout << product.Unit << left;
        cout.width(10);
        cout << product.Price << left << endl;
    }
}
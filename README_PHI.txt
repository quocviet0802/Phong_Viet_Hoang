# Phong_Viet_Hoang

#####Chu y:
vi du:
	OrderData::getInstance()->importDataFromJsonFile(): chay khi khoi tao de load data.



#PHI:

Order:
+ Order(int OrderID,int CustomerID,int EmployeeID,string OrderDate,int ShipperID);
+ ToJson();

OrderData:
	#Variable
	int maxID: ID lon nhat trong bang
	vector<Order> orderList.
	
	
	#Function
	+static OrdersData *getInstance(): SingleTon
	

    +bool importDataFromCSVFile(): Import data tu file csv de lay data va export sang file json.
	@return 
				true: Import thanh cong
				false: Import loi
	
    +bool importDataFromJsonFile(): Import data tu json file. Chi chay lan dau tien de lay du lieu.
	@return 
				true: Import thanh cong
				false: Import loi
    +bool exportDataToFile(): Export ra file json.
	@return 
				true: Import thanh cong
				false: Import loi
	
    +Order* getOrderByID(int OrderID): Get order 
	@param: int OrderID
	@return:
		pointer Order: thanh cong
		nullptr				:loi
	
    +int createOrder(int CustomerID,int EmployeeID,string OrderDate,int ShipperID): Tao Order.
	@param: 
		int CustomerID
		int EmployeeID
		string OrderDate
		int ShipperID
	@return: maxID
	
    +bool updateOrder(int OrderID,int CustomerID,int EmployeeID,string OrderDate,int ShipperID): Update Order
	@param:
		int OrderID
		int CustomerID
		int EmployeeID
		string OrderDate
		int ShipperID
	@return 
				true: Update thanh cong
				false: Update loi
	
    +bool deleteOrder(int OrderID);
	@param:
		int OrderID
	@return 
				true: delete thanh cong
				false: delete loi
	+vector<Order> getOrderList():
	@return vector<Order>.
	
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	Product:
+ Product(int ProductID,int CustomerID,int EmployeeID,string ProductDate,int ShipperID);
+ ToJson();

ProductData:
	#Variable
	int maxID: ID lon nhat trong bang
	vector<Product> ProductList.
	
	
	#Function
	+static ProductsData *getInstance(): SingleTon
	

    +bool importDataFromCSVFile(): Import data tu file csv de lay data va export sang file json.
	@return 
				true: Import thanh cong
				false: Import loi
	
    +bool importDataFromJsonFile(): Import data tu json file. Chi chay lan dau tien de lay du lieu.
	@return 
				true: Import thanh cong
				false: Import loi
    +bool exportDataToFile(): Export ra file json.
	@return 
				true: Import thanh cong
				false: Import loi
	
    +Product* getProductByID(int ProductID): Get Product 
	@param: int ProductID
	@return:
		pointer Product: thanh cong
		nullptr				:loi
	
    +int createProduct(string ProductName,int SupplierID,int CategoryID,string Unit,double Price): Tao Product.
	@param: 
		string ProductName
		int SupplierID
		int CategoryID
		string Unit
		double Price
	@return: maxID
	
    +bool updateProduct(int ProductID,string ProductName,int SupplierID,int CategoryID,string Unit,double Price): Update Product
	@param:
		int ProductID
		string ProductName
		int SupplierID
		int CategoryID
		string Unit
		double Price
	@return 
				true: Update thanh cong
				false: Update loi
	
    +bool deleteProduct(int ProductID);
	@param:
		int ProductID
	@return 
				true: delete thanh cong
				false: delete loi
	+vector<Product> getProductList():
	@return vector<Product>.
	
	
	-------------------------------------------------------------------------------------------------------------------------------------------
	OrderDetails:
+ OrderDetails(int OrderDetailID,int OrderID,int OrderDetailsID,int Quantity);
+ ToJson();

OrderDetailsData:
	#Variable
	int maxID: ID lon nhat trong bang
	vector<OrderDetails> OrderDetailsList.
	
	
	#Function
	+static OrderDetailsData *getInstance(): SingleTon
	

    +bool importDataFromCSVFile(): Import data tu file csv de lay data va export sang file json.
	@return 
				true: Import thanh cong
				false: Import loi
	
    +bool importDataFromJsonFile(): Import data tu json file. Chi chay lan dau tien de lay du lieu.
	@return 
				true: Import thanh cong
				false: Import loi
    +bool exportDataToFile(): Export ra file json.
	@return 
				true: Import thanh cong
				false: Import loi
	
    +OrderDetails* getOrderDetailsByID(int OrderDetailsID): Get OrderDetails 
	@param: int OrderDetailsID
	@return:
		pointer OrderDetails: thanh cong
		nullptr				:loi
	
    +int createOrderDetail(int OrderID,int ProductID,int Quantity);: Tao OrderDetails.
	@param: 
		int OrderID,
		int ProductID,
		int Quantity
	@return: maxID
	
    +bool updateOrderDetail(int OrderDetailID,int OrderID,int ProductID,int Quantity); Update OrderDetails
	@param:
		int OrderDetailID
		int OrderID
		int ProductID,int Quantity
	@return 
				true: Update thanh cong
				false: Update loi
	
    +bool deleteOrderDetails(int OrderDetailsID);
	@param:
		int OrderDetailsID
	@return 
				true: delete thanh cong
				false: delete loi
	+vector<OrderDetails> getOrderDetailsList():
	@return vector<OrderDetails>.
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
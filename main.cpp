#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "businessobjects/Shippers.h"
#include "dataaccess/ShippersData.h"
#include "businessobjects/Suppliers.h"
#include "dataaccess/SuppliersData.h"
#include "libs/json.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
using json = nlohmann::json;

void write_Shippers_to_file(){

	Shippers p1(1, "Speedy Express", "(503) 555-9831");
	Shippers p2(2, "United Package", "(503) 555-3199");
	Shippers p3(3, "Federal Shipping", "(503) 555-9931");


	ShippersData Shippersdata;
	Shippersdata.PushBack(p1);
	Shippersdata.PushBack(p2);
	Shippersdata.PushBack(p3);

	// for (int i=0; i < Shippersdata.GetSize(); i++){
	// 	Shippers p = Shippersdata.Get(i);
	// 	cout << p.ToString() << endl;
	// }
}

void write_Suppliers_to_file(){

	Suppliers s1(1, "Exotic Liquid", "Charlotte Cooper", "49 Gilbert St.", "Londona", "EC1 4SD", "UK", "(171) 555-2222");
	Suppliers s2(2, "New Orleans Cajun Delights", "Shelley Burke", "P.O. Box 78934", "New Orleans", "70117", "USA", "(100) 555-4822");

	SuppliersData Suppliersdata;
	Suppliersdata.PushBack(s1);
	Suppliersdata.PushBack(s2);

	Suppliersdata.ExportToFile("Suppliers.txt");
}

void read_Shippers_from_file(){
	ShippersData Shippersdata("Shippers.txt");
	for (int i=0; i < Shippersdata.GetSize(); i++){
		Shippers item = Shippersdata.Get(i);
		cout << item.ToString() << endl;
	}
	// Shippers a = *Shippersdata.GetShipperByID(4);
	// cout << a.ShipperName;
	Shippers b = *Shippersdata.GetShipperByName("Speedy Express");
	cout << b.ShipperID;
}

void read_Suppliers_from_file(){
	SuppliersData Suppliersdata("Suppliers.txt");
	for (int i=0; i < Suppliersdata.GetSize(); i++){
		Suppliers item = Suppliersdata.Get(i);
		cout << item.ToString() << endl;
	}
	Suppliers a = *Suppliersdata.GetSupplierByID(1);
	cout << a.SupplierName<<endl;
	Suppliers b = *Suppliersdata.GetSupplierByName("Speedy Express");
	cout << b.SupplierID<<endl;
}

void create_shipper_convert_to_json(){
	Shippers p(4, "Ahihi", "(503) 555-1234");
	json j = p.ToJson();
	cout << j;
}

int main(int argc, char** argv) {

	//create_shipper_convert_to_json();
	write_Shippers_to_file();
	read_Shippers_from_file();

	write_Suppliers_to_file();
	read_Suppliers_from_file();
	return 0;
}


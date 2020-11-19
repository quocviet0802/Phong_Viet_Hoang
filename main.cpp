#include <iostream>
#include "businessobjects/Products.h"

using namespace std;


int main(int argc, char** argv) {
	Products p(1, "Chais", 1, 1, "bottle", 20.0);	
	p.AddListProducts(&p);

	for(Products *item: p.ListProducts){
		cout<<item->CategoryId;
	}

	return 0;
}

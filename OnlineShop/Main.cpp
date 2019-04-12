#include "Product.h"
#include "Store.h"
#include <iostream>
using namespace std;


void add_new_product(Store & s) {
	int sku;
	int count;
	double price;
	char* brand = new char[100];
	char* model = new char[100];
	char* category = new char[100];
	cout << "New product characteristics: " << endl;
	cout << "SKU: ";
	cin >> sku;
	cout << "Count: ";
	cin >> count;
	cout << "Price: ";
	cin >> price;
	cin.ignore();
	cout << "Brand: ";
	cin.getline(brand, 100);
	cout << "Model: ";
	cin.getline(model, 100);
	cout << "Category: ";
	cin.getline(category, 100);

	Product p = Product(sku, count, price, brand, model, category);
	s.add_product(p);
	delete[] brand;
	delete[] model;
	delete[] category;
}

void delete_product(Store & s) {
	int sku;
	cout << "SKU of the product you want to delete: ";
	cin >> sku;
	s.delete_product(sku);
}

void change_product(Store & s) {
	//TODO: Dynamic brand model category length
	int sku;
	int count;
	double price;
	char* brand = new char[20];
	char* model = new char[20];
	char* category = new char[20];

	cout << "SKU of the product you want to change: ";
	cin >> sku;
	cout << "New product characteristics: " << endl;
	cout << "Count: ";
	cin >> count;
	cout << "Price: ";
	cin >> price;
	cout << "Brand: ";
	cin.ignore();
	cin.getline(brand, sizeof brand);
	cout << "Model: ";
	cin.getline(model, sizeof model);
	cout << "Category: ";
	cin.getline(category, sizeof category);
	
	s.change_product(sku, (int)count, (double)price, brand, model, category);
	delete[] brand;
	delete[] model;
	delete[] category;
}

void display_products(Store & s) {
	for (int i = 0; i < s.size(); i++) {
	Product p = s.get(i);
	cout << "sku: " << p.get_sku() << ", count: " << p.get_count() << ", price: " << p.get_price() << " , brand: " <<
		p.get_brand() << ", model: " << p.get_model() << ", category: " << p.get_category() << endl;
	}
}


int main() {

	Product assassins_creed = Product(745, 1002, 21.90, "Ubisoft", "Assassins Creed", "action-adventure");
	Product minecraft = Product(209, 897, 12.60, "Mojang", "Minecraft", "simulator, adventure");
	Product mortal_combat = Product(461, 1092, 22.57, "EA Games", "Mortal Combat", "fighting");
	Product sims_4 = Product(592, 787, 39.99,  "EA Games", "Sims 4", "simulator");
	Product amnesia = Product(640, 958, 19.99, "Frictional Games", "Amnesia", "survival horror");
	Product p6 = Product(6, 14, 3, "Blizzard Entertainment", "World of Warcraft", "simulator");

	Store s = Store();

	s.add_product(p1);
	s.add_product(p2);
	s.add_product(p3);
	s.add_product(p4);
	s.add_product(p5);
	s.add_product(p6);

	char command;
	cout << "A Add new product" << endl;
	cout << "X Delete product" << endl;
	cout << "C Change product" << endl;
	cout << "D Display products" << endl;
	cout << "Q Quit" << endl;
	
		cin >> command;
		while (command != 'Q') {
			if (command == 'A') {
				add_new_product(s);
			}
			else if (command == 'X') {
				delete_product(s);
			}
			else if (command == 'C') {
				change_product(s);
			}
			else if (command == 'D') {
				display_products(s);
			}
			else {
				cout << "Wrong command!";
			}
			cout << "Enter command: ";
			cin >> command;
		}

}
#include "Product.h"
#include <string>

Product::Product(int sku, int count, double price, const char* brand, const char* model, const char* category) {
	set_sku(sku);
	set_count(count);
	set_price(price);
	set_brand(brand);
	set_model(model);
	set_category(category);
}

Product::Product(): _sku(0), _count(0), _price(0), _brand(nullptr), _model(nullptr), _category(nullptr) {
}

Product::Product(Product const & product) {
	set_sku(product._sku);
	set_count(product._count);
	set_price(product._price);
	set_brand(product._brand);
	set_model(product._model);
	set_category(product._category);
}

Product::~Product() {
	//delete[] _brand;
	/*delete[] _model;
	delete[] _category;*/
}

void Product::set_sku(int sku) {
	_sku = sku;
}

void Product::set_count(int count) {
	_count = count;
}

void Product::set_price(double price) {
	_price = price;
}

void Product::set_brand(const char* brand) {
	if (!brand) {
		brand = "";
	}
 	int length = strlen(brand);
	_brand = new char[length];
	strcpy(_brand, brand);
}

void Product::set_model(const char* model) {
	if (!model) {
		model = "";
	}
	int length = strlen(model);
	_model = new char[length];
	strcpy(_model, model);

}

void Product::set_category(const char* category) {
	if (!category) {
		category = "";
	}
	int length = strlen(category);
	_category = new char[length];
	strcpy(_category, category);
}

int Product::get_sku() {
	return _sku;
}

int Product::get_count() {
	return _count;
}

double Product::get_price() {
	return _price;
}

const char* Product::get_brand() {
	return _brand;
}

const char* Product::get_model() {
	return _model;
}

const char* Product::get_category() {
	return _category;
}

//int main() {
//	Product p = Product(1, 2, 3, "aa", "bb", "cc");
//	Product p1 = Product(1, 2, 3, "a", "b", "c");
//
//	cout << p.get_sku();
//	//cout << p.get_brand() << endl;
//	//cout << p1.get_brand() << endl;
//	//cout << p.get_brand() << endl;
//
//}
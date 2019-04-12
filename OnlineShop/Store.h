#pragma once
#include "Product.h"

const int MAX = 5;

class Store {
private:
	int _top;
	int _size;
	Product* _products;
	bool full();
	bool empty();
	bool exists(int);
	void expand();
public:
	Store();
	Store(Store const&);
	~Store();

	int size();
	Product get(int);
	Product* get_products();
	void add_product(Product);
	void delete_product(int);
	void change_product(int, int = -1, double = -1, const char* = nullptr, const char* = nullptr, const char* = nullptr);
	Product* find(int);
};

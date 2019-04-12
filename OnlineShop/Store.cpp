#include "Store.h"
#include <iostream>


Store::Store() {
	_size = MAX;
	_top = -1;
	_products = new Product[_size];
}

Store::Store(Store const& store) {
	_size = store._size;
	_top = store._top;
	_products = store._products;
}

Store::~Store() {
	delete[] _products;
}

bool Store::full() {
	return _top == _size - 1;
}

bool Store::empty() {
	return _top == - 1;
}

int Store::size() {
	return _top + 1;
}

Product Store::get(int i) {
	return _products[i];
}

Product* Store::get_products() {
	if (empty()) {
		return 0;
	}
	return _products;
}

void Store::add_product(Product product) {
	if (full()) {
		expand();
	}
	_products[++_top] = product;
}

bool Store::exists(int sku) {
	bool exists = false;
	for (int i = 0; i < _size; i++) {
		if (_products[i].get_sku() == sku) {
			exists = true;
		}
	} 
	return exists;
}

void Store::delete_product(int sku) {
	Product *newArr = new Product[_size];
	if (!empty() && exists(sku)) {
		int j = 0;
		for (int i = 0; i < _size; i++) {
			if (_products[i].get_sku() != sku) {
				newArr[j] = _products[i];
				j++;
			}
			else {
				_top--;
			}
		}
	}

	delete[] _products;
	_products = newArr;
}

void Store::change_product(int sku, int count, double price, const char* brand, const char* model, const char* category) {
	Product* p = find(sku);
	if (count != -1) {
		p->set_count(count);
	}
	if (price != -1) {
		p->set_price(price);
	}
	if (brand != nullptr) {
		p->set_brand(brand);
	}
	if (model != nullptr) {
		p->set_model(model);
	}
	if (category != nullptr) {
		p->set_category(category);
	}

}

Product* Store::find(int sku) {
	if (!empty() && exists(sku)) {
		for (int i = 0; i < _size; i++)
			if (_products[i].get_sku() == sku) {
				return & _products[i];
			}
	}
	return nullptr;
}

void Store::expand() {
	Product *newArr = new Product[2 * _size];
	for (int i = 0; i < _size; i++)
		newArr[i] = _products[i];
	delete[] _products;
	_products = newArr;
	_size *= 2;
}
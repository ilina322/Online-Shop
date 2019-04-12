#pragma once
class Product {
private:
	int _sku;
	int _count;
	double _price;
	char* _brand;
	char* _model;
	char* _category;

public:
	Product(int, int, double, const char*, const char*, const char*);
	Product();
	Product(Product const &);
	~Product();
	void set_sku(int);
	void set_count(int);
	void set_price(double);
	void set_brand(const char*);
	void set_model(const char*);
	void set_category(const char*);

	int get_sku();
	int get_count();
	double get_price();
	const char* get_brand();
	const char* get_model();
	const char* get_category();


};
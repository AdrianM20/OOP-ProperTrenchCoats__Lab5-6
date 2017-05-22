#pragma once
#include "DynamicVector.h"
#include "Coat.h"

typedef Coat Product;

class ShoppingCart
{
private:
	DynamicVector<Product> products;
	DynamicVector<Product> cart;
	int current;
	
public:
	ShoppingCart();

	void clearProducts();

	void addAvailableCoats(const Product& coat);

	void add(const Product& coat);

	void start();
	
	void next();

	Coat getCurrentCoat();

	double totalCost();

	DynamicVector<Product> getCartContents() const { return cart; }

	bool isEmpty();

	bool noProducts();
};
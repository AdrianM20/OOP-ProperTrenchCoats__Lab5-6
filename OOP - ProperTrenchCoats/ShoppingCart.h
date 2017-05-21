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

	void addAvailableCoats(const Product& coat);

	void add(const Product& coat);

	Coat getCurrentCoat();

	double totalCost();

	DynamicVector<Product> getCartContents() const { return products; }

	bool isEmpty();
};
#pragma once
#include "DynamicVector.h"
#include "Coat.h"

typedef Coat Product;

class ShoppingCart
{
private:
	DynamicVector<Product> products;
	
public:
	ShoppingCart();

	void add(const Product& coat);

	double totalCost();

	DynamicVector<Product> getCartContents() const { return products; }

	bool isEmpty();
};
#pragma once
#include "DynamicVector.h"

class ShoppingCart
{
private:
	DynamicVector products;
	
public:
	ShoppingCart();

	void add(const Coat& coat);

	double totalCost();

	bool isEmpty();
};
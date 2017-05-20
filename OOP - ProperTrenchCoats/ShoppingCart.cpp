#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->current = 0;
}

void ShoppingCart::add(const Product & coat)
{
	this->products.add(coat);
}

Coat ShoppingCart::getCurrentCoat()
{
	if (this->current == this->products.getSize())
		this->current = 0;
	return this->products[this->current];
}

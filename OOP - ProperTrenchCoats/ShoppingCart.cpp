#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->current = 0;
}

void ShoppingCart::addAvailableCoats(const Product & coat)
{
	this->products.add(coat);
}

void ShoppingCart::add(const Product & coat)
{
	this->cart.add(coat);
}

Coat ShoppingCart::getCurrentCoat()
{
	if (this->current == this->products.getSize())
		this->current = 0;
	return this->products[this->current];
}

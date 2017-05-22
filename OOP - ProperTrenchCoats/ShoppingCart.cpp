#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->current = 0;
}

void ShoppingCart::clearProducts()
{
	this->products.setSize(0);
}

void ShoppingCart::addAvailableCoats(const Product & coat)
{
	this->products.add(coat);
}

void ShoppingCart::add(const Product & coat)
{
	this->cart.add(coat);
}

void ShoppingCart::start()
{
	if (this->products.getSize() == 0)
		return;
	this->current = 0;
	Coat currentCoat = this->getCurrentCoat();
	currentCoat.show();
}

void ShoppingCart::next()
{
	if (this->products.getSize() == 0)
		return;
	this->current++;
	Coat currentCoat = this->getCurrentCoat();
	currentCoat.show();
}

Coat ShoppingCart::getCurrentCoat()
{
	if (this->current == this->products.getSize())
		this->current = 0;
	return this->products[this->current];
}

double ShoppingCart::totalCost()
{
	double cost = 0;
	for (int i = 0; i < this->cart.getSize(); i++)
		cost += cart[i].getPrice();
	return cost;
}

bool ShoppingCart::isEmpty()
{
	return this->cart.getSize() == 0;
}

bool ShoppingCart::noProducts()
{
	return this->products.getSize() == 0;
}

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->current = 0;
}

void ShoppingCart::clearProducts()
{
	this->products.clear();
}

void ShoppingCart::clearCart()
{
	this->cart.clear();
}

void ShoppingCart::addAvailableCoats(const Product & coat)
{
	this->products.push_back(coat);
}

void ShoppingCart::add(const Product & coat)
{
	this->cart.push_back(coat);
}

void ShoppingCart::start()
{
	if (this->products.empty())
		return;
	this->current = 0;
	Coat currentCoat = this->getCurrentCoat();
	currentCoat.show();
}

void ShoppingCart::next()
{
	if (this->products.empty())
		return;
	this->current++;
	Coat currentCoat = this->getCurrentCoat();
	currentCoat.show();
}

Coat ShoppingCart::getCurrentCoat()
{
	if (this->current == this->products.size())
		this->current = 0;
	return this->products[this->current];
}

double ShoppingCart::totalCost()
{
	double cost = 0;
	for (int i = 0; i < this->cart.size(); i++)
		cost += cart[i].getPrice();
	return cost;
}

bool ShoppingCart::isEmpty()
{
	return this->cart.empty();
}

bool ShoppingCart::noProducts()
{
	return this->products.empty();
}

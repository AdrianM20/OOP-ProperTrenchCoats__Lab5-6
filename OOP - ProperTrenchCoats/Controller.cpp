#include "Controller.h"

/// ---------- Repository ---------- ///

void Controller::addCoatToRepository(const std::string & ID, const int & size, const std::string & colour, const double & price, const int & quantity, const std::string & link)
{
	Coat coat{ ID, size, colour, price, quantity, link };
	this->repo.addCoat(coat);
}

void Controller::removeCoatFromRepository(const std::string & ID)
{
	this->repo.removeCoatByID(ID);
}

void Controller::updateCoatToRepository(const std::string & ID, const double & new_price, const int & new_quantity, const std::string & new_link)
{
	Coat existingCoat = this->repo.findByID(ID);
	Coat newCoat{ ID, existingCoat.getSize(), existingCoat.getColour(), new_price, new_quantity, new_link };
	this->repo.updateCoat(ID, newCoat);
}

/// ---------- Shopping Cart ---------- ///

void Controller::clearProducts()
{
	this->cart.clearProducts();
}

void Controller::addAllAvailableCoats()
{
	DynamicVector<Coat> coats = getAllCoats();
	for (int i = 0; i < coats.getSize(); i++) {
		this->cart.addAvailableCoats(coats[i]);
	}
}

void Controller::addAllSizeCoats(const int & size)
{
	DynamicVector<Coat> coats = getAllCoats();
	for (int i = 0; i < coats.getSize(); i++) {
		if (coats[i].getSize() == size)
			this->cart.addAvailableCoats(coats[i]);
	}
}

void Controller::addCoatToCart(const Coat & c)
{
	this->cart.add(c);
}

void Controller::startShopping()
{
	this->cart.start();
}

void Controller::nextCoatShopping()
{
	this->cart.next();
}

void Controller::buyProducts()
{
	DynamicVector<Coat> coatsInCart = this->cart.getCartContents();
	for (int i = 0; i < coatsInCart.getSize(); i++) {
		this->repo.sellCoatByID(coatsInCart[i].getID());
	}
	this->cart.clearCart();
	this->cart.clearProducts();
}

void Controller::eraseCart()
{
	this->cart.clearCart();
}

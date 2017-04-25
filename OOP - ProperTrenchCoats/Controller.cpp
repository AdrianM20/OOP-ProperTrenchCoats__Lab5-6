#include "Controller.h"

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

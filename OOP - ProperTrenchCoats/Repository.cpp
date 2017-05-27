#include "Repository.h"
#include <string>
#include <sstream>
#include "Validators.h"

using namespace std;

void Repository::addNoCheck(const Coat& c)
{
	this->coats.push_back(c);
}

void Repository::addCoat(const Coat & c)
{
	coatValidator(c);
	this->coats.push_back(c);
}

void Repository::removeCoatByID(const std::string & ID)
{
	Coat checkCoat = findByID(ID);
	if (checkCoat.getID().length() == 0)
		throw "Coat does now exist. Nothig was deleted.";
	if (checkCoat.getQuantity() > 0) {
		char* ex;
		ex = "Cannot delete this coat. There is at least one left in stock.";
		throw ex;
	}

	for (int i = 0; i < this->coats.size(); i++)
		if (this->coats[i] == checkCoat) {
			this->coats.erase(this->coats.begin() + i);
			break;
		}
}

void Repository::sellCoatByID(const std::string & ID)
{
	Coat checkCoat = findByID(ID);
	Coat newCoat{ checkCoat.getID(),checkCoat.getSize(), checkCoat.getColour(),checkCoat.getPrice(), checkCoat.getQuantity() - 1,checkCoat.getLink() };
	int i;
	for (i = 0; i < this->coats.size(); i++) {
		if (this->coats[i] == checkCoat) {
			this->coats.erase(this->coats.begin() + i);
			break;
		}
	}
	this->coats.insert(this->coats.begin() + i, newCoat);
}

void Repository::updateCoat(const std::string & ID, const Coat & c)
{
	Coat checkCoat = findByID(ID);
	if (checkCoat.getID().length() == 0)
		throw "Coat does not exist. No data was updated.";
	coatValidator(c);
	int i;
	for (i = 0; i < this->coats.size(); i++)
		if (this->coats[i] == checkCoat) {
			this->coats.erase(this->coats.begin() + i);
			break;
		}
	this->coats.insert(this->coats.begin() + i, c);
}

Coat Repository::findByID(const std::string& ID)
{
	for (int i = 0; i < this->coats.size(); i++) {
		Coat coat = coats[i];
		if (coat.getID() == ID)
			return coat;
	}
	return Coat{};
}

std::vector<Coat> Repository::getCoatsbySize(const int & size)
{
	std::vector<Coat> coats;
	for (int i = 0; i < this->coats.size(); i++) {
		Coat c = this->coats[i];
		if (c.getSize() == size)
			coats.push_back(c);
	}
	return coats;
}

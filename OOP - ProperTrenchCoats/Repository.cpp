#include "Repository.h"
#include <string>
#include <sstream>
#include "Validators.h"

using namespace std;

void Repository::addNoCheck(const Coat& c)
{
	this->coats.add(c);
}

void Repository::addCoat(const Coat & c)
{
	coatValidator(c);
	this->coats.add(c);
}

void Repository::removeCoatByID(const std::string & ID)
{
	Coat checkCoat = findByID(ID);
	if (checkCoat.getID().length() == 0)
		throw "Coat does now exist. Nothig was deleted.";
	if (checkCoat.getQuantity() > 0) {
		char* ex;
		ex = "Cannod delete this coat. There is at least one left in stock.";
		throw ex;
	}

	coats = coats - checkCoat;

	/*Coat* coatsInDynamicVector = this->coats.getAllElems();
	for (int i = 0; i < this->coats.getSize(); i++)
		if (coatsInDynamicVector[i] == checkCoat) {
			this->coats.remove(i);
			break;
		}
	*/
}

void Repository::sellCoatByID(const std::string & ID)
{
	Coat checkCoat = findByID(ID);
	Coat* coatsInDynamicVector = this->coats.getAllElems();
	Coat newCoat{ checkCoat.getID(),checkCoat.getSize(), checkCoat.getColour(),checkCoat.getPrice(), checkCoat.getQuantity() - 1,checkCoat.getLink() };
	for (int i = 0; i < this->coats.getSize(); i++) {
		if (coatsInDynamicVector[i] == checkCoat) {
			this->coats.update(i, newCoat);
			break;
		}
	}
}

void Repository::updateCoat(const std::string & ID, const Coat & c)
{
	Coat checkCoat = findByID(ID);
	if (checkCoat.getID().length() == 0)
		throw "Coat does not exist. No data was updated.";
	Coat* coatsInDynamicVector = this->coats.getAllElems();
	coatValidator(c);
	for (int i = 0; i < this->coats.getSize(); i++)
		if (coatsInDynamicVector[i] == checkCoat) {
			this->coats.update(i, c);
			break;
		}
}

Coat Repository::findByID(const std::string& ID)
{
	Coat* coatsInDynamicVector = this->coats.getAllElems();
	if (coatsInDynamicVector == NULL)
		return Coat{};

	for (int i = 0; i < this->coats.getSize(); i++) {
		Coat coat = coatsInDynamicVector[i];
		if (coat.getID() == ID)
			return coat;
	}

	return Coat{};
}

DynamicVector<Coat> Repository::getCoatsbySize(const int & size)
{
	DynamicVector<Coat> coats;
	for (int i = 0; i < this->coats.getSize(); i++) {
		Coat c = coats[i];
		if (c.getSize() == size)
			coats.add(c);
	}
	return coats;
}

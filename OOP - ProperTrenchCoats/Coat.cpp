#include "Coat.h"
#include <Windows.h>
#include <shellapi.h>

Coat::Coat() : ID(""), size(0), colour(""), price(0), quantity(0), link("") {}

Coat::Coat(const std::string & ID, const int & size, const std::string & colour, const double & price, const int & quantity, const std::string & link)
{
	this->ID = ID;
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->link = link;
}

void Coat::show()
{
	ShellExecute(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool Coat::operator==(const Coat & other) const
{
	if (this->ID != other.ID)
		return false;
	if (this->size != other.size)
		return false;
	if (this->colour != other.colour)
		return false;
	if (this->price != other.price)
		return false;
	if (this->quantity != other.quantity)
		return false;
	if (this->link != other.link)
		return false;
	return true;
}

#pragma once
#include <iostream>

class Coat
{
private:
	std::string ID; // unique ID for identification - 5 characters
	int size;
	std::string colour;
	double price;
	int quantity;
	std::string link;

public:
	// default contructor
	Coat();

	// constructor with parameters
	Coat(const std::string& ID, const int& size, const std::string& colour, const double& price, const int& quantity, const std::string& link);

	// getter for ID
	std::string getID() const { return ID; }
	// getter for size
	int getSize() const { return size; }
	// getter for colour
	std::string getColour() const { return colour; }
	// getter for price
	double getPrice() const { return price; }
	// getter for quantity
	int getQuantity() const { return quantity; }
	// getter for link
	std::string getLink() const { return link; }

	// shows the current coat: link is opened in browser
	void show();

	// oveload of the == operator
	bool Coat::operator==(const Coat& other) const;
};
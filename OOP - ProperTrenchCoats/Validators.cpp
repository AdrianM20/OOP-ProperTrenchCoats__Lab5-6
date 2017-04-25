#include "Validators.h"
#include <string>

void coatValidator(const Coat & c)
{
	if (c.getID().length() != 5)
		throw "Coat ID must have 5 characters.!";
	if (c.getSize() > 60 || c.getSize() < 30)
		throw "Size must be between 30 and 60!";
	if (c.getColour().length() == 0)
		throw "The colour field cannot be empty!";
	if (c.getPrice() == 0)
		throw "Price must be greater than 0!";
	if (c.getQuantity() == 0)
		throw "The quantity must be at least 1!";
	if (c.getLink().length() == 0)
		throw "A link to the coat image must be given!";
}

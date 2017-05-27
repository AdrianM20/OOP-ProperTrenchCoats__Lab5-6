#pragma once
#include "Coat.h"
#include "DynamicVector.h"
#include <vector>

class Repository
{
private:
	std::vector<Coat> coats;

public:
	/*
		Default constructor.
		Initializes an repository object
	*/
	Repository() {}

	void addNoCheck(const Coat&c);

	/*
		Adds a coat to the repository
		Input: c - Coat
		Output: the coat is added to the repository
	*/
	void addCoat(const Coat& c);

	/*
		Removes a coat from the repository
		Input: ID - string
		Output: removes the coat with that ID from the repository
	*/
	void removeCoatByID(const std::string& ID);

	void sellCoatByID(const std::string& ID);

	/*
		Updates a coat info
		Input: ID - string, c - Coat
		Output: updates the coat with the given ID with data from the new Coat c
	*/
	void updateCoat(const std::string& ID, const Coat& c);

	/*
		Finds a coat by its ID.
		Input: ID - string
		Output: the coat that was found or an "empty" coat (all fields empty or 0), if nothing was found
	*/
	Coat findByID(const std::string& ID);

	/*
		Gets coats having a given size
		Input: size - int
		Output: a vector containing the coats having the given size
	*/
	std::vector<Coat> getCoatsbySize(const int& size);

	// Returns all coats
	std::vector<Coat> getCoats() const { return coats; }
};
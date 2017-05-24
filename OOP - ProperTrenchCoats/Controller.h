#pragma once
#include "Repository.h"
#include "ShoppingCart.h"

class Controller
{
private:
	Repository repo;
	ShoppingCart cart;

public:
	// default constructor for the controller
	Controller(const Repository& r) : repo(r) {}

	// return the repository and shopping cart of the controller
	Repository getRepo() const { return repo; }
	ShoppingCart getCart() const { return cart; }

	/// ---------- Repository ---------- ///

	/*
		Adds an new coat to the repository
		Input: ID, colour, link - string
				price - double
				size, quantity - int
		Output: assembles a coat object and sends it to repository
	*/
	void addCoatToRepository(const std::string& ID, const int& size, const std::string& colour, const double& price, const int& quantity, const std::string& link);

	/*
		Removes a coat from the repository
		Input: ID - string
		Output: deletes the coat with the given ID from the repository
	*/
	void removeCoatFromRepository(const std::string& ID);

	/*
		Updates a coat's information
		Input: ID, link - string
				price - double
				quantity - int
		Output: assembles a new version of the given coat and sents it to repository
	*/
	void updateCoatToRepository(const std::string& ID, const double& new_price, const int& new_quantity, const std::string& new_link);

	std::vector<Coat> getAllCoats() const { return repo.getCoats(); }

	/// ---------- Shopping Cart ---------- ///

	/*
		Clears the products dynamic vector from cart
	*/
	void clearProducts();

	/*
		Adds all coats to the available products in cart
	*/
	void addAllAvailableCoats();

	/*
		Add all coats having a given size to the available product cart
		Input: size - int
	*/
	void addAllSizeCoats(const int& size);

	/*
		Add a given coat to the shopping cart
		Input: c - Coat
	*/
	void addCoatToCart(const Coat& c);

	/*
		Starts iterating through the available products
	*/
	void startShopping();

	/*
		Jumps to the next product in list
	*/
	void nextCoatShopping();

	/*
		Buy a product. For each item in the shopping cart removes one item from the repository
		Clears shopping cart and available products
	*/
	void buyProducts();

	/*
		Clears shopping cart
	*/
	void eraseCart();
};
#pragma once
#include "DynamicVector.h"
#include "Coat.h"
#include <vector>

typedef Coat Product;

class ShoppingCart
{
private:
	std::vector<Product> products; // products available coresponding to the size condition
	std::vector<Product> cart; // shopping cart containing the chosen products
	int current;
	
public:
	// Constructor for shopping cart
	ShoppingCart();

	// clears the products vector
	void clearProducts();

	// clears the cart vector
	void clearCart();

	// adds a Coat to the products vector
	void addAvailableCoats(const Product& coat);

	// adds a Coat to the cart vetor
	void add(const Product& coat);

	// strats iterating through the available products
	void start();
	
	// jumps to the next available product
	void next();

	// returns the current coat for the iterator
	Coat getCurrentCoat();

	// computes the total cost of the Coats in the shopping cart
	double totalCost();

	// returns a vector containing all items from the shopping cart
	std::vector<Product> getCartContents() const { return cart; }

	// returns a vector containing all available products
	std::vector<Product> getCartAvailable() const { return products; }

	// checks if the cart is empty
	bool isEmpty();

	// checks if there are no available products
	bool noProducts();
};
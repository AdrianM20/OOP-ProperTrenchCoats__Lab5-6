#pragma once
#include "Controller.h"
#include <algorithm>

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printShoppingCartMenu();

	bool is_number(const std::string& s);

	void addCoatToRepo();
	void displayAllCoatsRepo();
	void removeCoatFromRepo();
	void updateCoatFromRepo();
	void addSizeCoats();
	void showCart();
};
#pragma once
#include "Controller.h"

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

	void addCoatToRepo();
	void displayAllCoatsRepo();
	void removeCoatFromRepo();
	void updateCoatFromRepo();
	void addCoatToCart();
};
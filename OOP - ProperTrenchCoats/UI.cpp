#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << "\n||------------Choose an option---------------||" << endl;
	cout << "|| 1 - Administrator mode                    ||" << endl;
	cout << "|| 2 - Client mode                           ||" << endl;
	cout << "|| 0 - Exit program                          ||" << endl;
	cout << "||------------Choose an option---------------||" << endl;
}

void UI::printRepositoryMenu()
{
	cout << "\n||----------Possible commands----------||" << endl;
	cout << "|| 1 - Add coat                        ||" << endl;
	cout << "|| 2 - Display all coats               ||" << endl;
	cout << "|| 3 - Delete coat                     ||" << endl;
	cout << "|| 4 - Update coat                     ||" << endl;
	cout << "|| 0 - Back                            ||" << endl;
	cout << "||----------Possible commands----------||" << endl;
}

void UI::printShoppingCartMenu()
{
	cout << "\n||----------Possible commands----------||" << endl;
	cout << "|| 1 - See trench coats                ||" << endl;
	cout << "|| 2 - Add coat to cart                ||" << endl;
	cout << "|| 3 - Next coat                       ||" << endl;
	cout << "|| 4 - See shopping cart               ||" << endl;
	cout << "|| 0 - Back                            ||" << endl;
	cout << "||----------Possible commands----------||" << endl;
}

bool UI::is_number(const std::string & s)
{
	return std::all_of(s.begin(), s.end(), ::isdigit);
}

void UI::addCoatToRepo()
{
	cout << "Enter the coat ID(must be 5 charanters): ";
	std::string ID;
	getline(cin, ID);
	cout << "Enter size: ";
	int size;
	cin >> size;
	cin.ignore();
	cout << "Enter colour: ";
	std::string colour;
	getline(cin, colour);
	cout << "Enter price: ";
	double price;
	cin >> price;
	cin.ignore();
	cout << "Enter quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Enter link: ";
	std::string link;
	getline(cin, link);
	this->ctrl.addCoatToRepository(ID, size, colour, price, quantity, link);
}

void UI::displayAllCoatsRepo()
{
	DynamicVector<Coat> elems = this->ctrl.getAllCoats();
	Coat* coats = elems.getAllElems();
	for (int i = 0; i < elems.getSize(); i++) {
		cout << "Coat ID: " << coats[i].getID() << " ";
		cout << "|| Size: " << coats[i].getSize() << " ";
		cout << "|| Colour: " << coats[i].getColour() << " ";
		cout << "|| Price: " << coats[i].getPrice() << " ";
		cout << "|| Quantity: " << coats[i].getQuantity() << endl;
	}
}

void UI::removeCoatFromRepo()
{
	cout << "Enter coat ID you want to remove: ";
	std::string ID;
	getline(cin, ID);
	this->ctrl.removeCoatFromRepository(ID);
}

void UI::updateCoatFromRepo()
{
	cout << "Enter the ID for the coat you want to update: ";
	std::string ID;
	getline(cin, ID);
	cout << "Enter the new price for coat: ";
	double new_price;
	cin >> new_price;
	cin.ignore();
	cout << "Enter the new quantity for coat: ";
	int new_quantity;
	cin >> new_quantity;
	cin.ignore();
	cout << "Enter new link for coat image: ";
	std::string new_link;
	getline(cin, new_link);
	this->ctrl.updateCoatToRepository(ID, new_price, new_quantity, new_link);
}

void UI::addSizeCoats()
{
	cout << "Enter the size for your coat: ";
	std::string size_str;
	getline(cin, size_str);
	if (size_str.empty()) {
		this->ctrl.clearProducts();
		this->ctrl.addAllAvailableCoats();
	}
	else {
		if (UI::is_number(size_str)) {
			int size_i = stoi(size_str);
			this->ctrl.clearProducts();
			this->ctrl.addAllSizeCoats(size_i);
		}
		else
			throw "Wrong input for coat size. Make sure you type in just numbers.";
	}
}

void UI::showCart()
{
	DynamicVector<Coat> coatsInCart = this->ctrl.getCart().getCartContents();
	cout << "\nProducts in shopping cart: " << endl;
	for (int i = 0; i < coatsInCart.getSize(); i++) {
		cout << "Colour: " << coatsInCart[i].getColour() << " ";
		cout << "|| Size: " << coatsInCart[i].getSize() << " ";
		cout << "|| Price: " << coatsInCart[i].getPrice() << endl;
	}
	if (this->ctrl.getCart().isEmpty())
		cout << "\nThe shopping cart is empty" << endl;
	cout << "\n\tTotal Cost: " << this->ctrl.getCart().totalCost() << endl;
	cout << "\nWhat would you lie to do?" << endl;
	cout << "1 - Buy coats" << endl;
	cout << "2 - Remove everything from cart" << endl;
	cout << "0 - Continue shopping" << endl;
	cout << "\nInput command: ";
	int command;
	cin >> command;
	cin.ignore();

	switch (command)
	{
	case 1: {
		if (this->ctrl.getCart().isEmpty())
			cout << "Cannot buy because cart is empty." << endl;
		else
			this->ctrl.buyProducts();
		break;
	}
	case 2: {
		this->ctrl.eraseCart();
		break;
	}
	case 0: { break; }
	}
}

void UI::run()
{
	while (true)
	{
		try {
			UI::printMenu();
			int command{ 0 };
			cout << "|| Input command: ";
			cin >> command;
			cin.ignore();
			if (command == 0)
				break;

			// Administrator mode
			if (command == 1)
			{
				while (true)
				{
					UI::printRepositoryMenu();
					int commandRepo{ 0 };
					cout << "|| Input command: ";
					cin >> commandRepo;
					cin.ignore();
					if (commandRepo == 0)
						break;

					switch (commandRepo)
					{
					case 1: {
						try {
							this->addCoatToRepo();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 2: {
						this->displayAllCoatsRepo();
						break;
					}
					case 3: {
						try {
							this->removeCoatFromRepo();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 4: {
						try {
							this->updateCoatFromRepo();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					} //end of switch
				} //
			}    // end of admin

				 // User Mode
			if (command == 2)
			{
				UI::addSizeCoats();
				while (true)
				{
					UI::printShoppingCartMenu();
					int commandUser{ 0 };
					cout << "|| Input command: ";
					cin >> commandUser;
					cin.ignore();
					if (commandUser == 0)
						break;

					switch (commandUser)
					{
					case 1: {
						try {
							if (this->ctrl.getCart().noProducts()) {
								cout << "No coats available." << endl;
								break;
							}
							this->ctrl.startShopping();
							Coat c = this->ctrl.getCart().getCurrentCoat();
							cout << "\nNow showing: " << endl;
							cout << "\tSize: " << c.getSize() << endl;
							cout << "\tColour: " << c.getColour() << endl;
							cout << "\tPrice: " << c.getPrice() << endl;
							std::string availability = "";
							if (c.getQuantity() > 3)
								availability = "In Stock";
							else if (c.getQuantity() <= 3)
									availability = "Limited Stock";
							else availability = "Out of stock";
							cout << "\tAvailability: " << availability << endl;
							cout << "\n\tTotal Cost: " << this->ctrl.getCart().totalCost() << endl;
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 2: {
						try {
							if (this->ctrl.getCart().getCurrentCoat().getQuantity() < 1) {
								cout << "This item is out of stock. It will not be added to you shopping cart." << endl;
								continue;
							}
							Coat c = this->ctrl.getCart().getCurrentCoat();
							this->ctrl.addCoatToCart(c);
							cout << "\n\tTotal Cost: " << this->ctrl.getCart().totalCost() << endl;
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 3: {
						try {
							if (this->ctrl.getCart().noProducts()) {
								cout << "No coats available." << endl;
								break;
							}
							this->ctrl.nextCoatShopping();
							Coat c = this->ctrl.getCart().getCurrentCoat();
							cout << "\nNow showing: " << endl;
							cout << "\tSize: " << c.getSize() << endl;
							cout << "\tColour: " << c.getColour() << endl;
							cout << "\tPrice: " << c.getPrice() << endl;
							std::string availability = "";
							if (c.getQuantity() > 3)
								availability = "In Stock";
							else if (c.getQuantity() <= 3 && c.getQuantity() > 0)
								availability = "Limited Stock";
							else availability = "Out of stock";
							cout << "\tAvailability: " << availability << endl;
							cout << "\n\tTotal Cost: " << this->ctrl.getCart().totalCost() << endl;
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					case 4: {
						try {
							UI::showCart();
						}
						catch (const char* msg) {
							cerr << msg << endl;
						}
						break;
					}
					} //end of switch
				} //
			}    // end of user
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
}
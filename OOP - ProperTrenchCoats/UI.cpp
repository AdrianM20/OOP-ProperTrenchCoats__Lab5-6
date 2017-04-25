#include "UI.h"
#include <string>

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
	cout << "|| 0 - Back                            ||" << endl;
	cout << "||----------Possible commands----------||" << endl;
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
	DynamicVector elems = this->ctrl.getAllCoats();
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

void UI::run()
{
	while (true)
	{
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
			}
		}
	}
}
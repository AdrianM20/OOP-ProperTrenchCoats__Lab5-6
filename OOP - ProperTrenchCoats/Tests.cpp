#include "Tests.h"
#include "Repository.h"
#include "Validators.h"
#include "ShoppingCart.h"
#include "Controller.h"

void Tests::testCoat()
{	
	// Test default constructor
	Coat c1;
	assert(c1.getID() == "");
	assert(c1.getSize() == 0);
	assert(c1.getColour() == "");
	assert(c1.getPrice() == 0);
	assert(c1.getQuantity() == 0);
	assert(c1.getLink() == "");

	// Test constructor with parameters
	Coat c2{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	assert(c2.getID() == "BEI52");
	assert(c2.getSize() == 52);
	assert(c2.getColour() == "Beige");
	assert(c2.getPrice() == 399.98);
	assert(c2.getQuantity() == 3);
	assert(c2.getLink() == "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]");
	
	// Test == operator
	Coat c3 = c2;
	assert(c3 == c2);

	Coat c4{ "GRN45", 45, "Green", 200.00, 2, "http://google.com" };
	assert(!(c4 == c2));

	Coat c5{ "BEI52", 45, "Green", 200.00, 2, "http://google.com" };
	assert(!(c5 == c2));

	Coat c6{ "BEI52", 52, "Green", 200.00, 2, "http://google.com" };
	assert(!(c6 == c2));

	Coat c7{ "BEI52", 52, "Beige", 200.00, 2, "http://google.com" };
	assert(!(c7 == c2));

	Coat c8{ "BEI52", 52, "Beige", 399.98, 2, "http://google.com" };
	assert(!(c8 == c2));

	Coat c9{ "BEI52", 52, "Beige", 399.98, 3, "http://google.com" };
	assert(!(c9 == c2));
}

void Tests::testRepository()
{
	// Test default constructor
	Repository repo{};

	// Test add to repo
	Coat c1{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	Coat c2{ "PNK32", 32, "Pink", 159.95, 4, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.addCoat(c1);
	repo.addCoat(c2);
	assert(repo.getCoats().size() == 2);

	Coat c3{ "BRN44", 44, "Brown", 159.95, 0, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.addNoCheck(c3);
	assert(repo.getCoats().size() == 3);

	// Test remove from repo
	repo.removeCoatByID("BRN44");
	assert(repo.getCoats().size() == 2);
	// Test remove exception 1
	bool exceptionThrown = false;
	try {
		repo.removeCoatByID("BRN44");
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	// Test remove exception 2
	exceptionThrown = false;
	try {
		repo.removeCoatByID("PNK32");
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test sell coat
	repo.sellCoatByID("PNK32");
	assert(repo.findByID("PNK32").getQuantity() == 3);

	// Test update coat
	Coat c4{ "BEI52",52,"Beige",399.98,6,"http://google.com" };
	repo.updateCoat("BEI52", c4);
	assert(repo.findByID("BEI52").getQuantity() == 6);
	// Test update coat exception
	exceptionThrown = false;
	try {
		repo.updateCoat("GRN50",c4);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test get coats by given size
	std::vector<Coat> check_vector = repo.getCoatsbySize(52);
	assert(check_vector.size() == 1);
}

void Tests::testValidators()
{
	// Test ID
	Coat c1{ "BGR234",0,"",0,0,"" };
	bool exceptionThrown = false;
	try {
		coatValidator(c1);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test size
	Coat c2{ "BGR23",0,"",0,0,"" };
	exceptionThrown = false;
	try {
		coatValidator(c2);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test colour
	Coat c3{ "BGR23",44,"",0,0,"" };
	exceptionThrown = false;
	try {
		coatValidator(c3);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test price
	Coat c4{ "BGR23",44,"Brown",0,0,"" };
	exceptionThrown = false;
	try {
		coatValidator(c4);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test quantity
	Coat c5{ "BGR23",44,"Brown",20,0,"" };
	exceptionThrown = false;
	try {
		coatValidator(c5);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);

	// Test link
	Coat c6{ "BGR23",44,"Brown",20,1,"" };
	exceptionThrown = false;
	try {
		coatValidator(c6);
	}
	catch (const char* msg) {
		exceptionThrown = true;
	}
	assert(exceptionThrown);
}

void Tests::testShoppingCart()
{
	// Test constructor
	ShoppingCart cart{};
	
	// Test add available products
	Coat c1{ "BLU42", 42, "Blue",195.00,2,"http://google.com" };
	Coat c2{ "ORG46", 46, "Orange",195.00,2,"http://google.com" };
	cart.addAvailableCoats(c1);
	cart.addAvailableCoats(c2);
	assert(!(cart.noProducts()));

	// Test add coats to cart
	cart.add(c1);
	cart.add(c2);
	assert(cart.getCartContents().size() == 2);

	// Test start iteration
	cart.start();
	assert(cart.getCurrentCoat() == c1);
	
	// Test next iteration
	cart.next();
	assert(cart.getCurrentCoat() == c2);
	cart.next();

	// Test total cost
	assert(cart.totalCost() == 390.00);

	// Test clear available products and no products
	cart.clearProducts();
	assert(cart.noProducts());

	// Test clear cart and empty cart
	cart.clearCart();
	assert(cart.isEmpty());

	// Test start and next for empty cart
	cart.start();
	cart.next();
}

void Tests::testController()
{
	// Test constructor
	Repository repo{};
	Controller ctrl{ repo };

	// Test add to repo
	ctrl.addCoatToRepository("BLU42", 42, "Blue", 195.00, 2, "http://google.com");
	ctrl.addCoatToRepository("ORG46", 46, "Orange", 195.00, 2, "http://google.com");
	/*Coat c{ "ORG50", 50, "Orange", 250.00, 0, "http://google.com" };
	ctrl.getRepo().addNoCheck(c);*/
	assert(ctrl.getRepo().getCoats().size() == 2);

	// Test remove from repo
	/*ctrl.removeCoatFromRepository("ORG50");
	assert(ctrl.getRepo().getCoats().size() == 2);*/

	// Test update to repo
	Coat c1{ "ORG46", 46, "Orange", 245.00, 5, "http://youtube.com" };
	ctrl.updateCoatToRepository("ORG46", 245.00, 5, "http://youtube.com");
	assert(ctrl.getRepo().getCoats()[1] == c1);
}

void Tests::testAll()
{
	testCoat();
	testRepository();
	testValidators();
	testShoppingCart();
	testController();
}

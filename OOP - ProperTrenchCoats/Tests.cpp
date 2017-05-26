#include "Tests.h"
#include "DynamicVector.h"
#include "Repository.h"
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
	Repository repo{};
	Coat c1{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.addCoat(c1);
	assert(repo.getCoats().size() == 1);
	
	Coat c2{ "PNK32", 32, "Pink", 159.95, 4, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8EZ_0149_013R.jpg],width[4000],height[4677],x[643],y[118],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.addNoCheck(c2);
	assert(repo.getCoats().size() == 2);
}

void Tests::testShoppingCart()
{
}

void Tests::testController()
{
}

void Tests::testAll()
{
	testCoat();
	testRepository();
	testShoppingCart();
	testController();
}

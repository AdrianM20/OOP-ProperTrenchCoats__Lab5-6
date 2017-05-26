#include "Tests.h"
#include <assert.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "ShoppingCart.h"
#include "Controller.h"

void Tests::testCoat()
{
	Coat c{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	assert(c.getID() == "BEI52");
	assert(c.getSize() == 52);
	assert(c.getColour() == "Beige");
	assert(c.getPrice() == 399.98);
	assert(c.getQuantity() == 3);
	assert(c.getLink() == "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]");
}

void Tests::testDynamicVector()
{
	DynamicVector<int> v1{ 3 };
	v1.add(12);
	v1.add(5);
	v1.add(45);
	assert(v1.getSize() == 3);
	v1.add(2);
	assert(v1.getSize() == 4);

	DynamicVector<int> v2 = v1;
	assert(v2.getSize() == 4);
}

void Tests::testRepository()
{
	Repository repo{};
	Coat c{ "BEI52", 52, "Beige", 399.98, 3, "http://lp2.hm.com/hmprod?set=source[/environment/2016/8FZ_0205_037R.jpg],width[3811],height[4456],y[-11],type[FASHION_FRONT]&hmver=0&call=url[file:/product/main]" };
	repo.addCoat(c);
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
	testDynamicVector();
	testRepository();
	testShoppingCart();
	testController();
}

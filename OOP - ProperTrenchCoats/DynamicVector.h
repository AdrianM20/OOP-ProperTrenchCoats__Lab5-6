#pragma once
#include "Coat.h"

typedef Coat TElement;

class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:
	// default constructor of DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// minus operator - removes the given element
	DynamicVector& operator-(const TElement& e);

	// Adds an element to the current DynamicVector
	void add(const TElement& e);

	// Deletes an element from the given position
	void remove(const int poz);
	
	// Updates the element from a given position
	void update(const int poz, const TElement& c);

	int getSize() const;
	TElement* getAllElems() const;

private:
	// Resize the current DynamicVector, multiplying its capacity by a given factor
	void resize(double factor = 2);
};
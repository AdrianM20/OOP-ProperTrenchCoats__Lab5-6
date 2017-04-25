#pragma once
#include "Coat.h"

/*
	Validate a coat's data before adding to repository
	Input: c - Coat
	Output: throws exception if there is a problem with the input data
*/
void coatValidator(const Coat& c);
#define _CRT_SECURE_NO_WARNINGS

#ifndef __RECIPE_H
#define __RECIPE_H

#include "Ingredient.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Recipe
{

private:
	LinkedList<Ingredient> ingredients;

public:
	Recipe();
	
	const LinkedList<Ingredient>& getIngredients() const;
	Recipe& operator+=(const Ingredient& ing);

	friend ostream& operator<<(ostream& os, const Recipe& r)
	{
		os << endl;
		os << r.ingredients;
		return os;
	}
};

#endif //
#include "Recipe.h"

Recipe::Recipe()
{
	this->ingredients = *new LinkedList<Ingredient>();
}


const LinkedList<Ingredient>& Recipe::getIngredients() const
{
	return ingredients;
}

 Recipe& Recipe::operator+=(const Ingredient& ing)
{
	ingredients.addNode(ing);
	return *this;
}

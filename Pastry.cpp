#include "Pastry.h"

Pastry::Pastry(const string name, double price, const Recipe& recipe)
{
	setName(name);
	setPrice(price);
	setRecipe(recipe);
}

Pastry::Pastry(const Pastry& pastry)
{
	setName(pastry.name);
	setPrice(pastry.price);
	setRecipe(pastry.recipe);
}


const string Pastry::getName() const
{
	return name;
}

double Pastry::getPrice() const
{
	return price;
}

const Recipe& Pastry::getRecipe() const
{
	return recipe;
}

void Pastry::setName(const string name)
{
	this->name = name;
}

void Pastry::setPrice(double price)
{
	this->price = price;
}

void Pastry::setRecipe(const Recipe& recipe)
{
	this->recipe = recipe;
}


#include "Ingredient.h"

Ingredient::Ingredient()
{
	setAmount(0);
	setName(" ");
}

Ingredient::Ingredient(const string name, int amount) : amount(amount)
{
	setName(name);
}

const string Ingredient::getName() const
{
	return name;
}

int Ingredient::getAmount()
{
	return amount;
}

void Ingredient::setAmount(int amount)
{
	this->amount = amount;
}

void Ingredient::setName(const string name)
{
	this->name = name;
}

#define _CRT_SECURE_NO_WARNINGS

#ifndef __INGREDIENT_H
#define __INGREDIENT_H
#include <iostream>
using namespace std;


class Ingredient
{

private:
	string name;
	int amount;

public:
	Ingredient(const string name, int amount = 1);
	Ingredient();
	inline const string getName() const;
	inline int getAmount();
	void setAmount(int amount);
	void setName(const string name);
	friend ostream& operator<<(ostream& os, const Ingredient& i)
	{
		os << i.amount << " " << i.name << endl;
		return os;
	}

	friend class Recipe;
};

#endif //__INGREDIENT_H
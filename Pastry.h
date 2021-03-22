#define _CRT_SECURE_NO_WARNINGS

#ifndef __PASTRY_H
#define __PASTRY_H

#include "Recipe.h"
#include <iostream>
using namespace std;

class Pastry
{

private:
	string name;
	double price;
	Recipe recipe;

public:
	Pastry(const string name, double price, const Recipe& recipe);
	Pastry(const Pastry& pastry);
	//~Pastry();
	const string getName() const;
	double getPrice() const;
	inline const Recipe& getRecipe() const;
	void setName(const string name);
	void setPrice(double price);
	void setRecipe(const Recipe& recipe);

	friend class PastryWithCount;
	friend ostream& operator<<(ostream& os, const Pastry& p)
	{
		os << "Name: " << p.name << endl
			<< "Price: " << p.price << endl
			<< "Recipe:" << p.recipe;
		return os;
	}
};

#endif //__PASTRY_H

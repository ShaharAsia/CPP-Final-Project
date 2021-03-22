#include "Bill.h"

Bill::Bill()
{
	items = vector<PastryWithCount>();
}
/*/
Bill::~Bill()
{
	items.clear();
}
*/
const vector<PastryWithCount>& Bill::getItems() const
{
	return items;
}

double Bill::getTotalPrice() const
{
	double sum = 0;
	for (vector<PastryWithCount>::const_iterator it = items.begin(); it != items.end(); ++it)
		sum += (*it).amount * (*it).pastry.getPrice();
	return sum;
}

bool Bill::addPastry(const Pastry& pastry, int amount)
{
	if (amount < 0) return false;
	items.push_back(*new PastryWithCount(pastry, amount));
	return true;
}


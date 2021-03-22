#include "PastryWithCount.h"

PastryWithCount::PastryWithCount(const Pastry& pastry, int amount) : pastry(pastry), amount(amount)
{
	
}



const Pastry& PastryWithCount::getPastry() const
{
	return pastry;
}

int PastryWithCount::getAmount()
{
	return amount;
}

void PastryWithCount::setAmount(int amount)
{
	this->amount = amount;
}

#include "Shift.h"

 Shift::Shift()
{

}

const Cashier* Shift::getCashier() const
{
	return cashier;
}

void Shift::setCashier(Cashier* cashier)
{
	this->cashier = cashier;
}

const Konditor* Shift::getKonditor() const
{
	return konditor;
}

void Shift::setKonditor(Konditor* konditor)
{
	this->konditor = konditor;
}
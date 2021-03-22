#include "Cashier.h"

Cashier::Cashier(const string name, double hourlyWage) : Employee(name, hourlyWage)
{
}

void Cashier::acceptPayment(double amountToPay) const
{
	cout << "Payment accepted: " << amountToPay << endl;
}

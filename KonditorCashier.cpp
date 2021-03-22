#include "KonditorCashier.h"

KonditorCashier::KonditorCashier(const string name, double hourlyWage) :
	Employee(name, hourlyWage),Cashier(name, hourlyWage),Konditor(name, hourlyWage)
{
}

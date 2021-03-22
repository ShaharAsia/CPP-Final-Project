#define _CRT_SECURE_NO_WARNINGS

#ifndef __KONDITORCASHIER_H
#define __KONDITORCASHIER_H

#include "Konditor.h"
#include "Cashier.h"

#include <iostream>

using namespace std;

class KonditorCashier : public Cashier, public Konditor
{
public:
	KonditorCashier(const string name, double hourlyWage);
	virtual void toOs(ostream& os) const override
	{
		os << "Have two roles" << endl;
		Cashier::toOs(os);
		Konditor::toOs(os);
	}
};

#endif //__KONDITORCASHIER_H

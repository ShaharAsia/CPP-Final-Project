#define _CRT_SECURE_NO_WARNINGS

#ifndef __KONDITOR_H
#define __KONDITOR_H

#include "Employee.h"
#include "PastryWithCount.h"
#include <vector>
#include <iostream>

using namespace std;

class Konditor : virtual public Employee
{
public:
	Konditor(const string name, double hourlyWage);
	void bake(const vector<PastryWithCount> &pastries) const;

	virtual void toOs(ostream& os) const override
	{
		os << "Role: Konditor" << endl;
	}
};

#endif //__KONDITOR_H

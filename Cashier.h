#ifndef __CASHIER_H
#define __CASHIER_H

#include "Employee.h"
#include <iostream>
using namespace std;

class Cashier : virtual public Employee
{

public:
    Cashier(const string name, double hourlyWage);
    void acceptPayment(double amountToPay) const;

    virtual void toOs(ostream &os) const override
    {
        os << "Role: Cashier" << endl;
    }
};

#endif //__CASHIER_H

#define _CRT_SECURE_NO_WARNINGS

#ifndef __SHIFT_H
#define __SHIFT_H

#include "Cashier.h"
#include "Konditor.h"
#include "KonditorCashier.h"

class Shift
{
private:
	Cashier* cashier;
	Konditor* konditor;

public:
	Shift();
	const Cashier* getCashier() const;
	void setCashier(Cashier* cashier);
	const Konditor* getKonditor() const;
	void setKonditor(Konditor* konditor);

	friend ostream& operator<<(ostream& os, const Shift& s)
	{
		if (s.konditor && s.cashier)
		{
			os << "Cashier:\n"
				<< *s.cashier << "Konditor:\n"
				<< *s.konditor << endl;
			
		}
		else if (s.konditor)
		{
			os << "Konditor:\n"
				<< *s.konditor << endl;
			
		}
		else
		{
			os << "Cashier:\n"
				<< *s.cashier << endl;
			
		}
		return os;
	}
};

#endif //__SHIFT_H

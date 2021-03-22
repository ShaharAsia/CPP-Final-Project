#define _CRT_SECURE_NO_WARNINGS

#ifndef __PASTRYWITHCOUNT_H
#define __PASTRYWITHCOUNT_H

#include "Pastry.h"

class PastryWithCount
{
private:
	Pastry pastry;
	int amount;

public:
	PastryWithCount(const Pastry& pastry, int amount = 1);
	
    const Pastry& getPastry() const;
	inline int getAmount();
	void setAmount(int amount);

	friend class Bill;
};

#endif //__PASTRYWITHCOUNT_H
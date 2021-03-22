#ifndef __BILL_H
#define __BILL_H

#include "Pastry.h"
#include "PastryWithCount.h"
#include <vector>
#include <iterator>

class Bill
{
private:
	vector<PastryWithCount> items;

public:
	Bill();
	//~Bill();
    const vector<PastryWithCount>& getItems() const;
	double getTotalPrice() const;
	bool addPastry(const Pastry& pastry, int amount = 1);

	friend ostream& operator<<(ostream& os, const Bill& b)
	{
		os << "Total Price: " << b.getTotalPrice() << endl;
		return os;
	}
};

#endif //__BILL_H

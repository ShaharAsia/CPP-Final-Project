#include "Konditor.h"

Konditor::Konditor(const string name, double hourlyWage) : Employee(name,hourlyWage)
{
}

void Konditor::bake(const vector<PastryWithCount> &pastries) const
{
	cout << pastries.size() << endl;
	for (vector<PastryWithCount>::const_iterator it = pastries.begin(); it != pastries.end(); it++)
	{
		cout << "Baking: " << (*it).getPastry() << endl;
	}
}



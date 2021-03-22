#include "Konditori.h"
#include <string.h>

Konditori* Konditori::konditoriInstance = new Konditori;

Konditori::Konditori()
{
	setName("Konditori");
	this->address.setCity("Tel aviv");
	this->address.setStreet("Heud Manor");
	this->address.setNumber(12);
	this->employees = vector<Employee*>();
	this->pastries = vector<Pastry*>();
	this->currentShift = new Shift();
}

Konditori* Konditori::getInstance()
{
	return konditoriInstance;
}

Konditori::~Konditori()
{
	for (vector<Employee*>::const_iterator it = employees.begin(); it != employees.end(); ++it)
		delete *it;
	employees.clear();

	delete currentShift;
	
}

const string Konditori::getName() const
{
	return name;
}

void Konditori::setName(const string name)
{
	this->name = name;
}

const Address& Konditori::getAddress() const
{
	return address;
}

Address& Konditori::getAddress()
{
	return address;
}

vector<Employee*> Konditori::getEmployees() const
{
	return employees;
}

const Shift& Konditori::getCurrentShift() const
{
	return *currentShift;
}

Shift& Konditori::getCurrentShift()
{
	return *currentShift;
}

vector<Pastry*> Konditori::getPastries() const
{
	return pastries;
}

Konditori::ePastryActionStatus Konditori::addPastry(const Pastry& pastry)
{
	pastries.push_back((Pastry*)&pastry);
	return ePastryActionStatus::SUCCEED;
}

Konditori::ePastryActionStatus Konditori::renamePastry(Pastry& pastry, const string newName)
{
	pastry.setName(newName);
	return ePastryActionStatus::SUCCEED;
}

Pastry* Konditori::getPastryByName(const string pastryName)
{
	for (vector<Pastry*>::const_iterator it = pastries.begin(); it != pastries.end(); ++it)
		if ((*it)->getName() == pastryName) return (*it);
	return nullptr;
}

const Pastry* Konditori::getPastryByName(const string pastryName) const
{
	for (vector<Pastry*>::const_iterator it = pastries.begin(); it != pastries.end(); ++it)
		if ((*it)->getName() == pastryName) return (*it);
	return nullptr;
}

const vector<Bill> Konditori::getBills() const
{
	return bills;
}

int Konditori::getNumOfBills() const
{
	return (int)(bills.size());
}

Konditori& Konditori::operator+=(const Employee& emp)
{
	employees.push_back((Employee*)&emp);
	return *getInstance();
}

Employee* Konditori::getEmployeeById(int id)
{
	for (vector<Employee*>::const_iterator it = employees.begin(); it != employees.end(); ++it)
		if ((*it)->getId() == id) return *it;
	return nullptr;
}

bool Konditori::addBill(const Bill& bill)
{
	bills.push_back(bill);
	return true;
}

Bill* Konditori::sortBillsLowToHigh() const
{
	Bill* sortedBill = new Bill[bills.size()];
	int index = 0;
	for (vector<Bill>::const_iterator it = bills.begin(); it != bills.end(); ++it)
	{
		sortedBill[index] = *it;
		index++;
	}
	int i, j;
	Bill key;
	for (i = 1; i < bills.size(); i++)
	{
		key = sortedBill[i];
		j = i - 1;

		while (j >= 0 && bills[j].getTotalPrice() > key.getTotalPrice())
		{
			sortedBill[j + 1] = sortedBill[j];
			j = j - 1;
		}
		sortedBill[j + 1] = key;
	}
	return sortedBill;
}

const vector<Bill>& Konditori::getLowHalfBills() const
{
	
	Bill* sorted = sortBillsLowToHigh();
	Bill* newBills;
	int sizeOfHalf = (int)((bills.size()/2) ==  0 ? bills.size() : ((bills.size() / 2) + 1));
	
	if (bills.size() % 2 == 0)
	{
		newBills = new Bill[bills.size() / 2];
		memcpy(newBills, sorted, (bills.size() / 2) * sizeof(Bill));
	}
	else
	{
		newBills = new Bill[(bills.size() / 2) + 1];
		memcpy(newBills, sorted, ((bills.size() /2) + 1) * sizeof(Bill));
	}
	vector<Bill>* lowBills = new vector<Bill>();
	for (int i = 0 ; i < sizeOfHalf ; i++ )
	{
		lowBills->push_back(newBills[i]);
	}
	return *lowBills;
}

const vector<Bill>& Konditori::getTopHalfBills() const
{
	Bill* sorted = sortBillsLowToHigh();
	Bill* newBills;
	Bill* startPoint = &sorted[bills.size() / 2];
	int sizeOfHalf = (int)((bills.size() / 2) == 0 ? bills.size() : ((bills.size() / 2) + 1));
	if(bills.size() % 2 == 0)
	{
		newBills = new Bill[bills.size() / 2];
		memcpy(newBills, startPoint, (bills.size() / 2) * sizeof(Bill));
	}
	else
	{
		newBills = new Bill[(bills.size() / 2) + 1];
		memcpy(newBills, startPoint, ((bills.size() / 2) + 1) * sizeof(Bill));
	}
	
	vector<Bill>* highBills = new vector<Bill>();;
	for (int i = 0; i < sizeOfHalf; i++)
	{
		highBills->push_back(newBills[i]);
	}

	return *highBills;
}

#define _CRT_SECURE_NO_WARNINGS

#ifndef __KONDITORI_H
#define __KONDITORI_H

#include "Bill.h"

#include "Employee.h"
#include "Address.h"
#include "Shift.h"
#include "Pastry.h"

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class Konditori
{

public:
	enum class ePastryActionStatus
	{
		SUCCEED,
		FAILED_ALREADY_EXIST,
		FAILED_GENERAL
	};

private:
	string name;
	Address address;
	vector<Employee*> employees; //
	Shift* currentShift;
	vector<Pastry*> pastries; //
	vector<Bill> bills;

	Konditori();
	static Konditori* konditoriInstance;

public:
	static Konditori* getInstance();
	~Konditori();

    const string getName() const;
	void setName(const string name);

	const Address& getAddress() const;
	Address& getAddress();

	vector<Employee*> getEmployees() const;
	Konditori& operator+=(const Employee&);
	Employee* getEmployeeById(int id);

	const Shift& getCurrentShift() const;
	Shift& getCurrentShift();

	vector<Pastry*> getPastries() const;
	ePastryActionStatus addPastry(const Pastry& pastry);
	ePastryActionStatus renamePastry(Pastry& pastry, const string newName);
	Pastry* getPastryByName(const string pastryName);
	const Pastry* getPastryByName(const string pastryName) const;

	Bill* sortBillsLowToHigh() const;
	const vector<Bill> getBills() const;
	int getNumOfBills() const;
	bool addBill(const Bill& bill);
	const  vector<Bill>& getTopHalfBills() const;
	const  vector<Bill>& getLowHalfBills() const;

	friend ostream& operator<<(ostream& os, const Konditori& k)
	{
		os << "Konditori name:"
			<< k.name << "\nAddress: "
			<< k.address << endl;
		return os;
	}
};


#endif //__KONDITORI_H
#define _CRT_SECURE_NO_WARNINGS

#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee
{

private:
	static int currentId;
	int id;
	string name;
	double hourlyWage;

public:
	Employee(const string name, double hourlyWage);
    int getId();
	virtual ~Employee();
	inline const string getName() const;
	inline double getHourlyWage();
	void setName(const string name);
	void setHourlyWage(double hourlyWage);
	virtual void toOs(ostream& os) const {}
	friend ostream& operator<<(ostream& os, const Employee& e)
	{
		os << "Name: " << e.name << ", ID: " << e.id << ", Hourly Wage: " << e.hourlyWage << endl;
		e.toOs(os);
		return os;
	}
};

#endif //__EMPLOYEE_H

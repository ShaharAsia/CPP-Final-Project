#include "Employee.h"

int Employee::currentId = 0;

Employee::Employee(const string name, double hourlyWage) : hourlyWage(hourlyWage)
{
	setName(name);
	this->id = ++currentId;
}

int Employee::getId()
{
	return id;
}

Employee::~Employee()
{
	
}

const string Employee::getName() const
{
	return name;
}

double Employee::getHourlyWage()
{
	return hourlyWage;
}

inline void Employee::setName(const string name)
{
	this->name = name;
}

inline void Employee::setHourlyWage(double hourlyWage)
{
	this->hourlyWage = hourlyWage;
}

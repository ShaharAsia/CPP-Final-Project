#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"

const string Address::getCity() const 
{
	return city;
}

const string Address::getStreet() const
{
	return street;
}

int Address::getNumber() const
{
	return number;
}

void Address::setCity(const string city)
{
	this->city = city;
}

void Address::setStreet(const string street)
{
	this->street = street;
}

void Address::setNumber(int number)
{
	this->number = number;
}

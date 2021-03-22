#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <string>
#include <iostream>
using namespace std;

class Address
{

private:
    string city;
    string street;
    int number;

public:
    //Address();
    const string getCity() const;
	const string getStreet() const;
    int getNumber() const;

    void setCity(const string city);
    void setStreet(const string street);
    void setNumber(int number);

    friend ostream &operator<<(ostream &os, const Address &a)
    {
        os << a.street << " " << a.number << ", " << a.city << endl;
        return os;
    }
};

#endif //__ADDRESS_H

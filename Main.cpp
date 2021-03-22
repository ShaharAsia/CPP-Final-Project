#include <iostream>
using namespace std;
#include "Main.h"

int main()
{
	Konditori* k = Konditori::getInstance();
	editKonditoriName(*k);
	editKonditoriCity(k->getAddress());
	editKonditoriStreet(k->getAddress());
	editKonditoriHouseNumber(k->getAddress());
	mainMenu(*k);
	delete k;
	return 0;
}

static void mainMenu(Konditori& k)
{
	bool isExit = false;
	int option;
	do
	{
		cout << k;
		cout << "<<<<<<<Please choose an option>>>>>>>" << endl
			<< "1.Edit Konditori information" << endl //implemented
			<< "2.Add employee" << endl //implemented
			<< "3.Show emplyees" << endl //implemented
			<< "4.Edit shift" << endl //implemented
			<< "5.Show shift" << endl //implemented
			<< "6.Add pastry" << endl //implemented
			<< "7.Edit pastry" << endl //implemented
			<< "8.Show pastry" << endl //implemented
			<< "9.Show top/less bills" << endl //implemented
			<< "10.Shop" << endl
			<< "0.Exit" << endl
			<< "Your option: ";
		cin >> option;
		char a = getchar();
		switch (option)
		{
		case 0:
			isExit = true;
			break;
		case 1:
			editKonditoriInformation(k);
			break;
		case 2:
			addEmployee(k);
			break;
		case 3:
			showEmployees(k.getEmployees(), (int)k.getEmployees().size());
			break;
		case 4:
			editShift(k);
			break;
		case 5:
			showShift(k.getCurrentShift());
			break;
		case 6:
			addPastry(k);
			break;
		case 7:
			editPastry(k);
			break;
		case 8:
			showPastry(k);
			break;
		case 9:
			showBills(k);
			break;
		case 10:
			shop(k);
			break;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	} while (!isExit);
	cout << "Bye :)\n";
}

static void editKonditoriInformation(Konditori& k)
{
	int option;

	while (true)
	{
		cout << "\nWhich konditori option would you like to edit?" << endl
			<< "1.Konditori name" << endl
			<< "2.City name" << endl
			<< "3.Street name" << endl
			<< "4.House number" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		char a = getchar();
		switch (option)
		{
		case 1:
			editKonditoriName(k);
			return;
		case 2:
			editKonditoriCity(k.getAddress());
			return;
		case 3:
			editKonditoriStreet(k.getAddress());
			return;
		case 4:
			editKonditoriHouseNumber(k.getAddress());
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

static void editKonditoriName(Konditori& k)
{
	string newName;
	cout << "Insert konditori name: ";
	getline(cin,newName);
	k.setName(newName);
}

static void editKonditoriCity(Address& a)
{
	string newName;
	cout << "Insert city name:";
	getline(cin, newName);
	a.setCity(newName);
}

static void editKonditoriStreet(Address& a)
{
	string newName;
	cout << "Insert street name:";
	getline(cin, newName);
	a.setStreet(newName);
}

static void editKonditoriHouseNumber(Address& a)
{
	unsigned int newHouseNumber;
	cout << "Insert house number:";
	cin >> newHouseNumber;
	char aa = getchar();
	a.setNumber(newHouseNumber);
}

static void addEmployee(Konditori& k)
{
	int option;
	double hourlyWage;
	string name;
	cout << "Insert employee name:";
	getline(cin, name);
	cout << endl;
	cout << "Insert hourly wadge:";
	cin >> hourlyWage;
	char a = getchar();
	cout << endl;
	while (true)
	{
		cout << "What is the employee role?" << endl
			<< "1.Cashier" << endl
			<< "2.Konditor" << endl
			<< "3.Konditor-Cashier" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		a = getchar();
		switch (option)
		{
		case 1:
			k+=(*new Cashier(name, hourlyWage));
			return;
		case 2:
			k+=(*new Konditor(name, hourlyWage));
			return;
		case 3:
			k+=(*new KonditorCashier(name, hourlyWage));
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

static void showEmployees(vector<Employee*> employees, int size)
{
	cout << "Employees:\n";
	for (vector<Employee*>::const_iterator it = employees.begin(); it != employees.end(); ++it)
		cout << *(*it) << endl;
}

static void editShift(Konditori& k)
{
	int option;
	while (true)
	{
		int id;
		cout << "insert employee id: ";
		cin >> id;
		char a = getchar();
		Employee* employee = k.getEmployeeById(id);
		if (!employee)
		{
			cout << "Employee not found";
			break;
		}
		cout << "\nWhich emplyee whould you like to replace in shift?" << endl
			<< "1.Cashier" << endl
			<< "2.Konditor" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		a;
		switch (option)
		{
		case 1:
			k.getCurrentShift().setCashier(dynamic_cast<Cashier*>(employee));
			return;
		case 2:
			k.getCurrentShift().setKonditor(dynamic_cast<Konditor*>(employee));
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

static void showShift(const Shift& shift)
{
	cout << "Showing shift:\n";
	cout << shift;
}

static void addPastry(Konditori& k)
{
	string name;
	double price;
	cout << "Insert pastry name:";
	getline(cin, name);
	cout << "Insert price:";
	cin >> price;
	char a = getchar();
	Recipe* recipe = initRecipeFromUser();
	Pastry* pastry = new Pastry(name, price, *recipe);
	printPastryActionStatus(k.addPastry(*pastry));
}

static Recipe* initRecipeFromUser()
{
	Recipe* recipe = new Recipe();
	bool isLoop = true;
	char userChoice;
	while (isLoop)
	{
		Ingredient newIngredient = initIngredientFromUser();
		cout << "Are you sure? y for yes ";
		cin >> userChoice;
		char a = getchar();
		if (userChoice == 'y')
		{
			*recipe += newIngredient;
		}
		cout << "Add another? y for yes ";
		cin >> userChoice;
		char b = getchar();
		isLoop = (userChoice == 'y');
	}
	return recipe;
}

static Ingredient initIngredientFromUser()
{
	int amount;
	string ingredientName;
	cout << "Insert ingredient name:";
	getline(cin, ingredientName);
	cout << endl;
	cout << "Insert amount:";
	cin >> amount;
	char a = getchar();
	return Ingredient(ingredientName, amount);
}

static void editPastry(Konditori& k)
{
	string name_to_search;
	Pastry* pastryFound;
	cout << "Insert pastry name:";
	getline(cin, name_to_search);
	cout << endl;
	pastryFound = k.getPastryByName(name_to_search);
	if (pastryFound)
	{
		editPastryMenu(k, *pastryFound);
	}
	else
	{
		cout << "Pastry not found\n";
	}
}

static void editPastryMenu(Konditori& k, Pastry& p)
{
	int option;
	while (true)
	{
		cout << "\nWhich attribute would you like to edit?" << endl
			<< "1.Pastry name" << endl
			<< "2.Pastry price" << endl
			<< "3.Recipe" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		char a = getchar();
		switch (option)
		{
			case 1:
			{
				string newName;
				cout << "Insert new name:";
				getline(cin, newName);
				printPastryActionStatus(k.renamePastry(p, newName));
				return;
			}
			case 2:
				double newPrice;
				cout << "Insert new price:";
				cin >> newPrice;
				cout << endl;
				p.setPrice(newPrice);
				cout << "Action succeed!\n";
				return;
			case 3:
				p.setRecipe(*initRecipeFromUser());
				cout << "Action succeed!\n";
				return;
			case 0:
				return;
			default:
				cout << "Invalid Input!\n";
				break;
		}
	}
}

void printPastryActionStatus(Konditori::ePastryActionStatus status)
{
	switch (status)
	{
	case Konditori::ePastryActionStatus::SUCCEED:
		cout << "Action succeed!\n";
		break;
	case Konditori::ePastryActionStatus::FAILED_ALREADY_EXIST:
		cout << "ERROR: pastry with this name already exist\n";
		break;
	case Konditori::ePastryActionStatus::FAILED_GENERAL:
		cout << "ERROR: general failure\n";
		break;
	}
}

static void showPastry(const Konditori& k)
{
	string name_to_search;
	const Pastry* pastryFound;
	cout << "Insert pastry name:";
	getline(cin, name_to_search);
	cout << endl;
	pastryFound = k.getPastryByName(name_to_search);
	if (pastryFound)
	{
		cout << *pastryFound << endl;
	}
	else
	{
		cout << "Pastry not found\n";
	}
}

static void showBills(const Konditori& k)
{
	int option, numOfBillsToPrint, numOfBills = k.getNumOfBills();
	if(numOfBills % 2 == 0)
		numOfBillsToPrint = numOfBills/2;
	else
		numOfBillsToPrint = ((numOfBills / 2) + 1 );
	while (true)
	{
		cout << "\nWhich bills would you like see?" << endl
			<< "1.Top half" << endl
			<< "2.Low half" << endl
			<< "0.Return to main menu" << endl
			<< "Your option: ";
		cin >> option;
		char a = getchar();
		switch (option)
		{
		case 1:
			printBills(k.getTopHalfBills());
			return;
		case 2:
			printBills(k.getLowHalfBills());
			return;
		case 0:
			return;
		default:
			cout << "Invalid Input!\n";
			break;
		}
	}
}

static void printBills(const vector<Bill> &bills)
{
	cout << "Bills:\n";

	for (vector<Bill>::const_iterator it = bills.begin(); it != bills.end(); it++)
	{
		cout <<*it << endl;
	}
}

static void shop(Konditori& k)
{
	string name_to_search;
	char userChoice;
	Pastry* pastryFound;
	Bill* bill = new Bill();
	bool isLoop = true;
	int amount;

	Shift& shift = k.getCurrentShift();
	const Cashier* currentCashier = shift.getCashier();
	const Konditor* currentKonditor = shift.getKonditor();
	if (!currentCashier)
	{
		cout << "No cashier in current shift! Can't accept payment!";
		return;
	}
	if (!currentKonditor)
	{
		cout << "No konditor in current shift! Can't bake!";
		return;
	}

	while (isLoop)
	{
		cout << "Insert pastry name:";
		getline(cin, name_to_search);
		pastryFound = k.getPastryByName(name_to_search);
		if (pastryFound)
		{
			cout << "Insert amount:";
			cin >> amount;
			char a = getchar();
			bill->addPastry(*pastryFound, amount);
		}
		else
		{
			cout << "Pastry not found\n";
		}
		cout << "Add another? y for yes ";
		cin >> userChoice;
		char a1 = getchar();
		isLoop = (userChoice == 'y');
	}
	(*currentCashier).acceptPayment(bill->getTotalPrice());//
	(*currentKonditor).bake(bill->getItems());
	k.addBill(*bill);
}

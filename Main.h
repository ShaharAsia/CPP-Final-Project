#define _CRT_SECURE_NO_WARNINGS

#include "Konditori.h"
#include "Pastry.h"
#include "Recipe.h"
#include "LinkedList.h"
#include <string>

int main();
static void mainMenu(Konditori& k);
static void editKonditoriInformation(Konditori& k);
static void editKonditoriName(Konditori& k);
static void editKonditoriCity(Address& a);
static void editKonditoriStreet(Address& a);
static void editKonditoriHouseNumber(Address& a);
static void addEmployee(Konditori& k);
static void showEmployees(vector<Employee*> employees, int size);
static void editShift(Konditori& k);
static void showShift(const Shift& shift);
static void addPastry(Konditori& k);
static Recipe* initRecipeFromUser();
static Ingredient initIngredientFromUser();
static void editPastry(Konditori& k);
static void editPastryMenu(Konditori& k, Pastry& p);
void printPastryActionStatus(Konditori::ePastryActionStatus status);
static void showPastry(const Konditori& k);
static void showBills(const Konditori& k);
static void printBills(const vector<Bill> &bills);
static void shop(Konditori& k);

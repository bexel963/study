#include <iostream>
#include <cstring>
#include "Q02_Person.h"

Person::Person()
{
	this->lName = "";
	this->fName[0] = '\0';
}
Person::Person(const string& ln, const char* fn)
{
	this->lName = ln;
	strcpy(this->fName, fn);
}

void Person::show() const
{
	cout << this->lName << ", " << this->fName << endl;
}

void Person::formalShow() const
{
	cout << this->fName << ", " << this->lName << endl;
}
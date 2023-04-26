#include <iostream>
#include "Q02_Person.h"

int main()
{
	Person one;
	Person two("smythecraft");
	Person three("Dimwiddy", "Sam");

	one.show();
	cout << endl;
	one.formalShow();
	cout << endl;

	two.show();
	cout << endl;
	two.formalShow();
	cout << endl;

	three.show();
	cout << endl;
	three.formalShow();
	cout << endl;
}
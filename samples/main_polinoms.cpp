#include <iostream>
#include "polinoms.h"
#include "list.h"
#include <string>
using namespace std;

int main()
{
	polinom p1("1 123+-5.5 101");
	polinom p2("2.4 100+3.3 201");
	cout << "first polinom: " << p1 << endl;
	cout << "second polinom: " << p2 << endl;
	cout << "addition: " << p1 + p2 << endl;
	cout << "subtracion: " << p1 - p2 << endl;
	cout << "multiplication: " << p1 * p2 << endl;
	cout << "multiplication with num: " << p1 * 2.5 << endl;
	cout << "square: " << p2 * p2 << endl;
}
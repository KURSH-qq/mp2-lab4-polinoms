#include <iostream>
#include "polinoms.h"
#include "list.h"
#include <string>
#include <locale.h>
using namespace std;

int main()
{
	int choise;
	polinom p1;
	polinom p2;

	enum operations
	{
		addition = 1,
		subtraction,
		mulptiplication,
		multiplication_with_num
	};
	
	cout << "enter polinom like this: 1*123+-3*321" << endl;
	cout << "the polinom is entered without spaces, the degrees are written without variables," << endl;
	cout << "with a negative value of the coefficient plus is also written before monom" << endl;
	cout << "enter first polinom" << endl;
	cin >> p1;
	cout << p1 << endl;
	cout << "enter second polinom" << endl;
	cin >> p2;
	cout << p2 << endl;
	cout << "enter operation" << endl;
	cout << "available operation:" << endl;
	cout << "1 - addition of polinoms" << endl;
	cout << "2 - subtraction of polinoms" << endl;
	cout << "3 - multiplication with polinom" << endl;
	cout << "4 - multiplacation with num" << endl;
	cin >> choise;
	switch (choise) {
	case addition:
	{
		cout << p1 + p2 << endl;
		break;
	}
	case subtraction:
	{
		cout << p1 - p2 << endl;
		cout << p2 - p1 << endl;
		break;
	}
	case mulptiplication: 
	{
		cout << p1 * p2 << endl;
		break;
	}
	case multiplication_with_num:
	{
		double num;
		cout << "enter num for multiplication" << endl;
		cin >> num;
		cout << p1 * num << endl;
		cout << p2 * num << endl;
		break;
	}
		
	}
}




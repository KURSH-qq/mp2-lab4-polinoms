#include <iostream>
#include "polinoms.h"
#include "list.h"
#include <string>
#include <locale.h>
using namespace std;

int main()
{
	//polinom p1("1 123+-5.5 101");
	//polinom p2("2.4 100+3.3 201");
	
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
	setlocale(0, "");
	cout << "������ ����� �������� 1*123+-3*321" << endl;
	cout << "������� �������� ��� ��������, ������� ������������ ��� ����������," << endl;
	cout << "��� ������������� �������� ����������� ���� ����� ������� ���� �������" << endl;
	cout << "������� ������ �������" << endl;
	cin >> p1;
	cout << p1 << endl;
	cout << "������� ������ �������" << endl;
	cin >> p2;
	cout << p2 << endl;
	cout << "������� ��������" << endl;
	cout << "��������� ��������:" << endl;
	cout << "1 - �������� ���������" << endl;
	cout << "2 - ��������� ���������" << endl;
	cout << "3 - ��������� �������� �� �������" << endl;
	cout << "4 - ��������� �������� �� �����" << endl;
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
		cout << "������� ����� ��� ���������" << endl;
		cin >> num;
		cout << p1 * num << endl;
		cout << p2 * num << endl;
		break;
	}
		
	}
	/*
	polinom p1("1*101");
	polinom p2("3*311");
	cout << p1 * p2 << endl;
	
	*/
	
}




#include <iostream>
#include <cmath>
#include <conio.h>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

class name_surname_B1
{
protected:
	string name;
	string surname;
	name_surname_B1() {}
	name_surname_B1(string name, string surname)
	{
		this->name = name;
		this->surname = surname;
	}
	~name_surname_B1() {}
public:
	void show_B1()
	{
		cout << "B1" << endl;
	}
};
class test_1_D1 : protected name_surname_B1
{
public:
	test_1_D1() : name_surname_B1() {}
	test_1_D1(string name, string surname) : name_surname_B1(name, surname) {}
	int get_test1()
	{
		return rand() % 5;
	}
	void show_D1()
	{
		show_B1();
		cout << "D1" << endl;
	}
};
class test_2_D2 : public name_surname_B1
{
protected:
	int get_test2()
	{
		return rand() % 5;
	}
public:
	void show_D2()
	{
		show_B1();
		cout << "D2" << endl;
	}
};
class extended_B2
{
protected:
	int get_extended(int b, int t)
	{
		return b + t;
	}
	void show_B2()
	{
		cout << "B2" << endl;
	}
};
class test_3_D3 : protected test_2_D2, protected extended_B2
{
public:
	int get_test3()
	{
		return rand() % 5;
	}
	void show_D3()
	{
		show_B2();
		show_D2();
		cout << "D3" << endl;
	}
};
class test_4_D4 : public test_1_D1 , public test_3_D3
{
public:
	int test_1, test_2, test_3, test_4;
	int basic, extended;
	test_4_D4() : test_1_D1() {}
	test_4_D4(string name, string surname): test_1_D1(name, surname) {}
	int get_test4()
	{
		return rand() % 5;
	}
	void show_D4()
	{
		show_D1();
		show_D3();
		cout << "D4" << endl;
	}
	void show_results()
	{
		cout << "Name, Surname: " << test_1_D1::name << " " << test_1_D1::surname << endl;
		cout << "Test1: " << test_1 << endl;
		cout << "Test2: " << test_2 << endl;
		cout << "Test3: " << test_3 << endl;
		cout << "Res.Basic: " << basic << endl;
		cout << "Test4: " << test_4 << endl;
		cout << "Res.Extended: " << extended << endl;
		cout << endl;
	}
	void get_results()
	{
		test_1 = get_test1();
		test_2 = get_test2();
		test_3 = get_test3();
		test_4 = get_test4();
		basic = test_1 + test_2 + test_3;
		extended = get_extended(basic, test_4);
		cout << endl;
	}
	~test_4_D4() {}
};
int main()
{
	cout << "How many students?, Answer: ";
	test_4_D4 *students;
	int i;
	cin >> i;
	students = new test_4_D4[i];
	string name;
	string surname;
	for (int j = 0; j < i; j++)
	{
		srand(time(NULL));
		Sleep(1000);
		cout << "Enter a name: ";
		cin >> name;
		cout << "Enter a surname: ";
		cin >> surname;
		students[j] = test_4_D4(name, surname);
		students[j].get_results();
	}
	cout << endl;
	for (int j = 0; j < i; j++)
		students[j].show_results();
	cout << "Which ierarchy u want to see D1/D2/D3/D4 = 1/2/3/4 on keybord" << endl;
	while (true)
	{
		if (_kbhit)
		{
			switch (_getch())
			{
			case 49:
			{	cout << "D1 tree:" << endl;
				test_1_D1 d1;
			d1.show_D1();
			break; }
			case 50:
			{   cout << "D2 tree:" << endl;
				test_2_D2 d2;
			d2.show_D2();
			break; }
			case 51:
			{	cout << "D3 tree:" << endl;
				test_3_D3 d3;
			d3.show_D3();
			break; }
			case 52:
			{	cout << "D4 tree:" << endl;
				test_4_D4 d4;
			d4.show_D4();
			break; }
			}
		}
		break;
	}
	delete[] students;
	return 0;
}

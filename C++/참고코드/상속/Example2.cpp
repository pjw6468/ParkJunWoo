#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A�� ������" << endl;
	}
	~A()
	{
		cout << "A�� �Ҹ���" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B�� ������" << endl;
	}
	~B()
	{
		cout << "B�� �Ҹ���" << endl;
	}
};

void main()
{
	B b;
}

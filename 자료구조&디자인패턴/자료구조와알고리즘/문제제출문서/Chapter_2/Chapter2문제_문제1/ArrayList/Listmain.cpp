#include"ArrayList.h"
#include<iostream>
using namespace std;

int main(void)
{
	List list;
	LData data;
	int Sum = 0;

	/*���� 1*/
	ListInit(&list);
	for (int i = 0; i < 9; i++)
	{
		Linsert(&list, i);
	}
	/*����2*/
	if (LFirst(&list, &data))
	{
		Sum += data;
		while (LNext(&list, &data))
			Sum += data;
	}
	cout << "List�� ����� ���� �� : " << Sum<<endl;
	/*����3_2�� ����� 3�� ��� ����*/
	if(LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
	}
	while (LNext(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			 LRemove(&list);
	}
	/*����4*/
	if (LFirst(&list, &data))
	{
		cout <<"List�� ����� ������ : "<< data << " ";
		while (LNext(&list, &data))
			cout << data << " ";
	}
	cout << endl;
	
}
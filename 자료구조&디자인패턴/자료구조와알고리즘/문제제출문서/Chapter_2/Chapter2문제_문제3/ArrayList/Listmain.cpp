#include"ArrayList.h"
#include<iostream>
using namespace std;

int main(void)
{
	List list;
	LData data;
	int multi = 1;
	int Num[5];

	/*���� 1. ����Ʈ�� ���� �� �ʱ�ȭ �� ����, 5���� �Է� �޴´� . �Է� ���� ���� ����Ʈ�� �����Ѵ�.*/
	ListInit(&list);
	cout << "5���� ���� �Է��Ͻÿ� : ";
	cin >> Num[0] >> Num[1] >> Num[2]>>Num[3]>>Num[4];
	for (int i = 0; i < 5; i++)
	{
		Linsert(&list, Num[i]);
	}
	/*���� 2. ����Ʈ�� ����� ���� ���������� �����Ͽ� ¦���� ���� ����Ѵ�.*/
	if (LFirst(&list, &data))
	{
		if(data % 2 == 0)
			multi *= data;
		while (LNext(&list, &data))
			if (data % 2 == 0)
				multi *= data;
	}
	cout << "List�� ����� �� �� ¦���� �� : " << multi <<endl;
	/*���� 3. ����Ʈ�� ����� ���� �� Ȧ���� �ش��ϴ� ���� ��� �����Ѵ�.*/
	cout << "���� �� Ȧ�� �� : ";
	if(LFirst(&list, &data))
	{
		if (data % 2 != 0)
		{
			cout << data << " ";
			LRemove(&list);
		}
	}
	while (LNext(&list, &data))
	{
		if (data % 2 != 0)
		{
			cout << data << " ";
			LRemove(&list);
		}
	}
	cout << endl;
	/*���� 4. ���������� ����Ʈ�� ����� �����͸� ������� ����Ѵ�.*/
	if (LFirst(&list, &data))
	{
		cout <<"List�� ����� ������ : "<< data << " ";
		while (LNext(&list, &data))
			cout << data << " ";
	}
	cout << endl;
	
}
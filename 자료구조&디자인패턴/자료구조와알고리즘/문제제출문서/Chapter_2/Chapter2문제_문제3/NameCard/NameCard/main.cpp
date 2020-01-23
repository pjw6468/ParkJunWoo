#include"ArrayList.h"
#include"NameCard.h"

int main(void)
{
	List list;
	NameCard* NCard;
	int Num;
	char name[10], phone[12];

	ListInit(&list);

	/*1. �Է� ���� ����ŭ�� ��ȭ��ȣ ������ ArrayList�� �����Ѵ� */


	cout << "����� �����ϰڽ��ϱ� : " << endl;
	cin >> Num;
	for (int i = 0; i < Num; i++)
	{
		cout << i + 1 << "��° ����� �̸��� �Է����ּ��� :  ";
		cin >> name;
		cout << i + 1 << "��° ����� ��ȣ�� �Է����ּ���(11�ڸ�,- ����) :   ";
		cin >> phone;
		NCard = MakeNameCard(name, phone);
		Linsert(&list, NCard);
	}
	/*2. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�.*/
	if (LFirst(&list, &NCard))
	{
		if (!NameCompare(NCard, "���ϴ�"))
			ShowNameCardInfo(NCard);
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "���ϴ�"))
				{
					ShowNameCardInfo(NCard);
					break;
				}
			}
		}
	}
	/*3. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ ������ �����Ѵ�.*/
	if (LFirst(&list, &NCard))
	{
		if (!NameCompare(NCard, "���̺�"))
		{
			ChangePhoneNum(NCard, "01023234545");
		}
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "���̺�"))
				{
					ChangePhoneNum(NCard, "01023234545");
					break;
				}
			}
		}
	}
	/*4. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�.*/
	if (LFirst(&list, &NCard))
	{
		if (!NameCompare(NCard, "�ڼ���"))
		{
			NCard = LRemove(&list);
			free(NCard);
		}
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "�ڼ���"))
				{
					NCard = LRemove(&list);
					free(NCard);
					break;
				}
			}
		}
	}
	/*5. ������ �����ִ� ��� ����� ��ȭ��ȣ ������ ����Ѵ�.*/
	cout << "���� �����ִ� ��ȭ��ȣ ���� �� : " << LCount(&list) << endl;
	if (LFirst(&list, &NCard))
	{
			ShowNameCardInfo(NCard);
			while (LNext(&list, &NCard))
			{
					ShowNameCardInfo(NCard);
			}
		
	}
}
	


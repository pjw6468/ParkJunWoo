#include"ArrayList.h"
#include"NameCard.h"

int main(void)
{
	List list;
	NameCard* NCard;

	ListInit(&list);

	/*�� 3���� ��ȭ��ȣ ������, ArrayList�� �����Ѵ�. */

		NCard = MakeNameCard("���ϴ�", "010-1234-4567");
		Linsert(&list, NCard);

		NCard = MakeNameCard("�ڼ���", "010-5588-9966");
		Linsert(&list, NCard);

		NCard = MakeNameCard("���̺�", "010-7755-3366");
		Linsert(&list, NCard);
	
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
			ChangePhoneNum(NCard, "010-2323-4545");
		}
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "���̺�"))
				{
					ChangePhoneNum(NCard, "010-2323-4545");
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
	


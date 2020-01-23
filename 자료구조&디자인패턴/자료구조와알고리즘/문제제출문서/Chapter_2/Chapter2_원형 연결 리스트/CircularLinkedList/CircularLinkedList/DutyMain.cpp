#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"CLinkedList.h"
#include"Employee.h"


Employee * pEmp;
void EmployeeInfo(Employee * emp);
Employee * WhoDutyEmployee(List * plist, const char * name, int day);

int main(void)
{
	List list;
	ListInit(&list);

	/* ���� ���� ���*/
	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "�̼���");
	pEmp->empIDnum = 1234;
	LInsert(&list, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "���ϳ�");
	pEmp->empIDnum = 5678;
	LInsert(&list, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "���ϳ�");
	pEmp->empIDnum = 9012;
	LInsert(&list, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "���ϴ�");
	pEmp->empIDnum = 3456;
	LInsert(&list, pEmp);

	// ��ü ������ 1ȸ ��� ///////
	printf("���� ���  \n");
	if (LFirst(&list, &pEmp))
	{
		EmployeeInfo(pEmp);

		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &pEmp))
				EmployeeInfo(pEmp);
		}
	}

	/*������ ���*/
	printf("\n������ ���\n");
	pEmp = WhoDutyEmployee(&list, "�̼���", 7);
	EmployeeInfo(pEmp);

	/*����*/
	if (LCount(&list) != 0)
	{
		LFirst(&list, &pEmp);
		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			LNext(&list, &pEmp);
				LRemove(&list);
		}
	}

}

Employee * WhoDutyEmployee(List * plist, const char * name, int day)
{
	int i;
	int EmpNum = LCount(plist);
	Employee *remp;

	if (EmpNum != 0)
	{
		LFirst(plist, &remp);
		if (strcmp(remp->name, name) != 0)
		{
			for (i = 0; i < EmpNum - 1; i++)
			{
				LNext(plist, &remp);
				if (strcmp(remp->name, name) == 0)
					break;
			}
			if (i >= EmpNum - 1)
				return NULL;
		}
	}
	for (i = 0; i < day; i++)
	{
		LNext(plist, &remp);
	}
	return remp;
}

void EmployeeInfo(Employee * emp)
{
	printf("���� �̸� : %s ", emp->name);
	printf("���� ��ȣ : %d \n", emp->empIDnum);
	
}
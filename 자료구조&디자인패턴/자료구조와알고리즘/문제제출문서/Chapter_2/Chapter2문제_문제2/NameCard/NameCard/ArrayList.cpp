#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0; // ����Ʈ�� ����� �������� ���� 0!
	(plist->curPosition) = -1; // ���� �ƹ� ��ġ�� ����Ű�� ����!
}

void Linsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN) // �� �̻� ������ ������ ���ٸ顦
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data; // ������ ����
	(plist->numOfData)++; // ����� �������� �� ����
}

int LFirst(List* plist, LData* pdata) // ù ��° ��ȸ
{
	if (plist->numOfData == 0) // ����� �����Ͱ� �ϳ��� ���ٸ�!
		return FALSE;

	(plist->curPosition) = 0; // ���� ��ġ �ʱ�ȭ! ù ��° �������� ������ �ǹ�!
	*pdata = plist->arr[0]; // pdata�� ����Ű�� ������ ������ ����

	return TRUE;
}

int LNext(List* plist, LData* pdata) // �� ��° ���� ��ȸ
{
	if (plist->curPosition >= (plist->numOfData) - 1) // �� �̻� ������ �����Ͱ� ���ٸ�!
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition; // ������ �������� �ε��� �� ����
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos]; // ������ �����͸� �ӽ÷� ����

									// ������ ���� �������� �̵��� �����ϴ� �ݺ���
	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--; // �������� �� ����
	(plist->curPosition)--; // ���� ��ġ�� �ϳ� �ǵ�����.
	return rdata;		   // ������ �������� ��ȯ
}

int LCount(List* plist)
{
	return plist->numOfData;
}
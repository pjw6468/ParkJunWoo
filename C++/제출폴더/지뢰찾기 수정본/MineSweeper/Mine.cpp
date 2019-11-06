#include "Mine.h"

//�ʱ� 9*9 ���� 10��
//�߱� 16*16 ���� 40��
//��� 30*16 ���� 99��

Mine::Mine()
{
}

void Mine::TileSet()
{
	int i = 0;
	int Checking = 0;
	int CheckingCount = 0;
	int Rnum;
	for (int i = 0; i < TileCount; i++) { TileList[i].MineState = false; }
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x+=2)
		{
			TileList[i].x = x;
			TileList[i].y = y;
			i++;
		}
	}
	for (int i = 0; i < MineCount; i++)
	{
		Rnum = rand() % TileCount;
		if (TileList[Rnum].MineState == true) //������ Ÿ���� �̹� �����ϰ�� i�� 1 ���༭ �ٽõ���
			i--;
		else { TileList[Rnum].MineState = true; TileList[Rnum].NearMineCount = 99; }
			
	}
	for (int i = 0; i < TileCount; i++)
	{
		TileList[i].NearMineCount = NearMineSearch(i);
	}
}

void Mine::MineCreate(int Level)
{
	int Rnum;
	switch (Level)
	{
	case GAME_LEVEL_EASY:
		MineCount = 10;
		TileCount = 81;
		Width = 18;
		Height = 9;
		break;
	case GAME_LEVEL_NORMAL:
		MineCount = 40;
		TileCount = 256;
		Width =  32;
		Height = 16;
		break;
	case GAME_LEVEL_HARD:
		MineCount = 99;
		TileCount = 480;
		Width = 60;
		Height = 16;
		break;
	}
	TileList = new GAME_TILE[TileCount];

}

void Mine::MineShow()
{
	for (int i = 0; i < TileCount; i++)
	{
		gotoxy(TileList[i].x, TileList[i].y);
		if (TileList[i].MineState == true) { cout << "��"; }
		else 
		{
			if (TileList[i].NearMineCount ==0)
			{
				cout << "��";
			}
			else if(TileList[i].NearMineCount == 1)
				cout << "��";
			else if (TileList[i].NearMineCount == 2)
				cout << "��";
			else if (TileList[i].NearMineCount == 3)
				cout << "��";
			else if (TileList[i].NearMineCount == 4)
				cout << "��";
			else if (TileList[i].NearMineCount == 5)
				cout << "��";
			else if (TileList[i].NearMineCount == 6)
				cout << "��";
			else if (TileList[i].NearMineCount == 7)
				cout << "��";
			else if (TileList[i].NearMineCount == 8)
				cout << "��";
		}
	}
	system("pause");
}

int Mine::NearMineSearch(int ListNum)
{
	int Count = 0;
	if (TileList[ListNum].y != 0 && TileList[ListNum - 10].MineState == true) //������ Y�� 0�϶� ����X
		Count++;
	if (TileList[ListNum].y !=0 && TileList[ListNum - 11].MineState == true) //�� Y�� 0�϶� ���� X
		Count++;
	if (TileList[ListNum].y != 0 && TileList[ListNum - 9].MineState == true) //������ Y�� 0�϶� ���� X
		Count++;
	if (TileList[ListNum].x != 0&& TileList[ListNum - 1].MineState == true) //���� X�� 0�϶� ���� X
		Count++;
	if (TileList[ListNum].x != Width-2 && TileList[ListNum + 1].MineState == true) //������ X�� ������ ���϶� ����X
		Count++;
	if (TileList[ListNum].y != Height-1 && TileList[ListNum + 9].MineState == true) //�޾Ʒ� Y�� �� �Ʒ��϶� ���� X
		Count++;
	if (TileList[ListNum].y != Height - 1 &&TileList[ListNum + 10].MineState == true) //�Ʒ� Y�� �� �Ʒ��϶� ���� X
		Count++;
	if (TileList[ListNum].y != Height - 1 && TileList[ListNum + 11].MineState == true) //�����Ʒ� Y�� �� �Ʒ��϶� ���� X
		Count++;
	return Count;
}

Mine::~Mine()
{
}

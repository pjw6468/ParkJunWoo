#include "Mine.h"

//초급 9*9 지뢰 10개
//중급 16*16 지뢰 40개
//고급 30*16 지뢰 99개

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
		if (TileList[Rnum].MineState == true) //랜덤한 타일이 이미 지뢰일경우 i를 1 빼줘서 다시돌림
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
		if (TileList[i].MineState == true) { cout << "※"; }
		else 
		{
			if (TileList[i].NearMineCount ==0)
			{
				cout << "□";
			}
			else if(TileList[i].NearMineCount == 1)
				cout << "①";
			else if (TileList[i].NearMineCount == 2)
				cout << "②";
			else if (TileList[i].NearMineCount == 3)
				cout << "③";
			else if (TileList[i].NearMineCount == 4)
				cout << "④";
			else if (TileList[i].NearMineCount == 5)
				cout << "⑤";
			else if (TileList[i].NearMineCount == 6)
				cout << "⑥";
			else if (TileList[i].NearMineCount == 7)
				cout << "⑦";
			else if (TileList[i].NearMineCount == 8)
				cout << "⑧";
		}
	}
	system("pause");
}

int Mine::NearMineSearch(int ListNum)
{
	int Count = 0;
	if (TileList[ListNum].y != 0 && TileList[ListNum - 10].MineState == true) //왼쪽위 Y가 0일땐 동작X
		Count++;
	if (TileList[ListNum].y !=0 && TileList[ListNum - 11].MineState == true) //위 Y가 0일땐 동작 X
		Count++;
	if (TileList[ListNum].y != 0 && TileList[ListNum - 9].MineState == true) //오른위 Y가 0일땐 동작 X
		Count++;
	if (TileList[ListNum].x != 0&& TileList[ListNum - 1].MineState == true) //왼쪽 X가 0일땐 동작 X
		Count++;
	if (TileList[ListNum].x != Width-2 && TileList[ListNum + 1].MineState == true) //오른쪽 X가 오른쪽 끝일땐 동작X
		Count++;
	if (TileList[ListNum].y != Height-1 && TileList[ListNum + 9].MineState == true) //왼아래 Y가 맨 아래일땐 동작 X
		Count++;
	if (TileList[ListNum].y != Height - 1 &&TileList[ListNum + 10].MineState == true) //아래 Y가 맨 아래일땐 동작 X
		Count++;
	if (TileList[ListNum].y != Height - 1 && TileList[ListNum + 11].MineState == true) //오른아래 Y가 맨 아래일땐 동작 X
		Count++;
	return Count;
}

Mine::~Mine()
{
}

#include "Mine.h"

//초급 9*9 지뢰 10개
//중급 16*16 지뢰 40개
//고급 30*16 지뢰 99개

Mine::Mine()
{
}

void Mine::MineCreate(int Level)
{
	GameLevel = Level;
	int i = 0;
	int Checking = 0;
	int CheckingCount = 0;
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
	for (int i = 0; i < TileCount; i++) { TileList[i].MineState = false; TileList[i].Openstatus = false; }
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x += 2)
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
		if (TileList[i].NearMineCount == 0)
			TileList[i].Icon = "□";
		else if (TileList[i].NearMineCount == 1)
			TileList[i].Icon = "①";
		else if (TileList[i].NearMineCount == 2)
			TileList[i].Icon = "②";
		else if (TileList[i].NearMineCount == 3)
			TileList[i].Icon = "③";
		else if (TileList[i].NearMineCount == 4)
			TileList[i].Icon = "④";
		else if (TileList[i].NearMineCount == 5)
			TileList[i].Icon = "⑤";
		else if (TileList[i].NearMineCount == 6)
			TileList[i].Icon = "⑥";
		else if (TileList[i].NearMineCount == 7)
			TileList[i].Icon = "⑦";
		else if (TileList[i].NearMineCount == 8)
			TileList[i].Icon = "⑧";

	}
}

void Mine::TileOpen(int TileNum)
{
	if (TileList[TileNum].Openstatus == false)
	{
		gotoxy(TileList[TileNum].x, TileList[TileNum].y);
		cout << TileList[TileNum].Icon;
		TileList[TileNum].Openstatus = true;
	}
}

void Mine::MineShow()
{
	for (int i = 0; i < TileCount; i++)
	{
		gotoxy(TileList[i].x, TileList[i].y);
		if (TileList[i].MineState == true) { cout << "※"; }
	}
}

void Mine::AllShow()
{
	for (int i = 0; i < TileCount; i++)
	{
		gotoxy(TileList[i].x, TileList[i].y);
		if (TileList[i].MineState == true) { cout << "※"; }
		else
		{
			cout << TileList[i].Icon;
		}
	}
}

void Mine::NearTileOpen(int TileNum)
{
	if (GameLevel == GAME_LEVEL_EASY) //쉬움 난이도일경우
	{
		if (TileList[TileNum].y != 0 && TileList[TileNum].x != 0 && TileList[TileNum - 10].MineState == false) //왼쪽위 Y가 0일땐 동작X
			TileOpen(TileNum - 10);
		if (TileList[TileNum].y != 0 && TileList[TileNum - 9].MineState == false) //위 Y가 0일땐 동작 X
			TileOpen(TileNum - 9);
		if (TileList[TileNum].y != 0 && TileList[TileNum].x != Width - 2 && TileList[TileNum - 8].MineState == false) //오른위 Y가 0일땐 동작 X
			TileOpen(TileNum - 8);
		if (TileList[TileNum].x != 0 && TileList[TileNum - 1].MineState == false) //왼쪽 X가 0일땐 동작 X
			TileOpen(TileNum - 1);
		if (TileList[TileNum].x != Width - 2 && TileList[TileNum + 1].MineState == false) //오른쪽 X가 오른쪽 끝일땐 동작X
			TileOpen(TileNum + 1);
		if (TileList[TileNum].y != Height - 1 && TileList[TileNum].x != 0 && TileList[TileNum + 8].MineState == false) //왼아래 Y가 맨 아래일땐 동작 X
			TileOpen(TileNum + 8);
		if (TileList[TileNum].y != Height - 1 && TileList[TileNum + 9].MineState == false) //아래 Y가 맨 아래일땐 동작 X
			TileOpen(TileNum + 9);
		if (TileList[TileNum].y != Height - 1 && TileList[TileNum].x != Width - 2 && TileList[TileNum + 10].MineState == false) //오른아래 Y가 맨 아래일땐 동작 X
			TileOpen(TileNum + 10);
	}
}

void Mine::MineSearchManage(int TileNum)
{
	switch (GameLevel)
	{
	case GAME_LEVEL_EASY: //9
		MineSearch(TileNum, -10);  //왼위
		MineSearch(TileNum, -9);  //위
		MineSearch(TileNum, -8); //오른위
		MineSearch(TileNum, -1);  //왼
		MineSearch(TileNum, 1);   //오른
		MineSearch(TileNum, 8);   //왼아래
		MineSearch(TileNum, 9);   //아래
		MineSearch(TileNum, 10);  //오른아래
		break;
	case GAME_LEVEL_NORMAL: // 16
		MineSearch(TileNum, -17);  //왼위
		MineSearch(TileNum, -16);  //위
		MineSearch(TileNum, -15); //오른위
		MineSearch(TileNum, -1);  //왼
		MineSearch(TileNum, 1);   //오른
		MineSearch(TileNum, 15);   //왼아래
		MineSearch(TileNum, 16);   //아래
		MineSearch(TileNum, 17);  //오른아래
		break;
	case GAME_LEVEL_HARD: //30
		MineSearch(TileNum, -31);  //왼위
		MineSearch(TileNum, -30);  //위
		MineSearch(TileNum, -29); //오른위
		MineSearch(TileNum, -1);  //왼
		MineSearch(TileNum, 1);   //오른
		MineSearch(TileNum, 29);   //왼아래
		MineSearch(TileNum, 30);   //아래
		MineSearch(TileNum, 31);  //오른아래
		break;
	}
}

void Mine::MineSearch(int TileNum, int num)
{
	if (GameLevel == GAME_LEVEL_EASY) //쉬움 난이도일경우
	{
		if (TileList[TileNum].NearMineCount == 0)
			MineSearch(TileNum + num, num);
		//else if (TileList[TileNum].NearMineCount != 0)
		//	return;
		else if (TileList[TileNum].x == 0)
			return;
		else if (TileList[TileNum].x == Width)
			return;
		else if (TileList[TileNum].y == 0)
			return;
		else if (TileList[TileNum].y == Height)
			return;
		NearTileOpen(TileNum);
	}
}

int Mine::NearMineSearch(int ListNum)
{

	int Count = 0;
	if (GameLevel == GAME_LEVEL_EASY) //쉬움 난이도일경우
	{
		if (TileList[ListNum].y != 0 && TileList[ListNum].x != 0 && TileList[ListNum - 10].MineState == true) //왼쪽위 Y가 0일땐 동작X
			Count++;
		if (TileList[ListNum].y != 0 && TileList[ListNum - 9].MineState == true) //위 Y가 0일땐 동작 X
			Count++;
		if (TileList[ListNum].y != 0 && TileList[ListNum].x != Width - 2 && TileList[ListNum - 8].MineState == true) //오른위 Y가 0일땐 동작 X
			Count++;
		if (TileList[ListNum].x != 0 && TileList[ListNum - 1].MineState == true) //왼쪽 X가 0일땐 동작 X
			Count++;
		if (TileList[ListNum].x != Width - 2 && TileList[ListNum + 1].MineState == true) //오른쪽 X가 오른쪽 끝일땐 동작X
			Count++;
		if (TileList[ListNum].y != Height - 1 && TileList[ListNum].x != 0 && TileList[ListNum + 8].MineState == true) //왼아래 Y가 맨 아래일땐 동작 X
			Count++;
		if (TileList[ListNum].y != Height - 1 && TileList[ListNum + 9].MineState == true) //아래 Y가 맨 아래일땐 동작 X
			Count++;
		if (TileList[ListNum].y != Height - 1 && TileList[ListNum].x != Width - 2 && TileList[ListNum + 10].MineState == true) //오른아래 Y가 맨 아래일땐 동작 X
			Count++;
	}



	if (GameLevel == GAME_LEVEL_NORMAL) //보통 난이도일경우
	{

	}


	if (GameLevel == GAME_LEVEL_HARD) // 어려움 난이도일경우
	{

	}
	return Count;
}

bool Mine::MineCheck(int TileNum)
{
	if (TileList[TileNum].MineState == true)
		return true;
	return false;
}
Mine::~Mine()
{
}

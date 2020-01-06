#include "Mine.h"

//�ʱ� 9*9 ���� 10��
//�߱� 16*16 ���� 40��
//��� 30*16 ���� 99��

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
		if (TileList[Rnum].MineState == true) //������ Ÿ���� �̹� �����ϰ�� i�� 1 ���༭ �ٽõ���
			i--;
		else { TileList[Rnum].MineState = true; TileList[Rnum].NearMineCount = 99; }

	}
	for (int i = 0; i < TileCount; i++)
	{
		TileList[i].NearMineCount = NearMineSearch(i);
		if (TileList[i].NearMineCount == 0)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 1)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 2)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 3)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 4)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 5)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 6)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 7)
			TileList[i].Icon = "��";
		else if (TileList[i].NearMineCount == 8)
			TileList[i].Icon = "��";

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
		if (TileList[i].MineState == true) { cout << "��"; }
	}
}

void Mine::AllShow()
{
	for (int i = 0; i < TileCount; i++)
	{
		gotoxy(TileList[i].x, TileList[i].y);
		if (TileList[i].MineState == true) { cout << "��"; }
		else
		{
			cout << TileList[i].Icon;
		}
	}
}

void Mine::NearTileOpen(int TileNum)
{
	if (GameLevel == GAME_LEVEL_EASY) //���� ���̵��ϰ��
	{
		if (TileList[TileNum].y != 0 && TileList[TileNum].x != 0 && TileList[TileNum - 10].MineState == false) //������ Y�� 0�϶� ����X
			TileOpen(TileNum - 10);
		if (TileList[TileNum].y != 0 && TileList[TileNum - 9].MineState == false) //�� Y�� 0�϶� ���� X
			TileOpen(TileNum - 9);
		if (TileList[TileNum].y != 0 && TileList[TileNum].x != Width - 2 && TileList[TileNum - 8].MineState == false) //������ Y�� 0�϶� ���� X
			TileOpen(TileNum - 8);
		if (TileList[TileNum].x != 0 && TileList[TileNum - 1].MineState == false) //���� X�� 0�϶� ���� X
			TileOpen(TileNum - 1);
		if (TileList[TileNum].x != Width - 2 && TileList[TileNum + 1].MineState == false) //������ X�� ������ ���϶� ����X
			TileOpen(TileNum + 1);
		if (TileList[TileNum].y != Height - 1 && TileList[TileNum].x != 0 && TileList[TileNum + 8].MineState == false) //�޾Ʒ� Y�� �� �Ʒ��϶� ���� X
			TileOpen(TileNum + 8);
		if (TileList[TileNum].y != Height - 1 && TileList[TileNum + 9].MineState == false) //�Ʒ� Y�� �� �Ʒ��϶� ���� X
			TileOpen(TileNum + 9);
		if (TileList[TileNum].y != Height - 1 && TileList[TileNum].x != Width - 2 && TileList[TileNum + 10].MineState == false) //�����Ʒ� Y�� �� �Ʒ��϶� ���� X
			TileOpen(TileNum + 10);
	}
}

void Mine::MineSearchManage(int TileNum)
{
	switch (GameLevel)
	{
	case GAME_LEVEL_EASY: //9
		MineSearch(TileNum, -10);  //����
		MineSearch(TileNum, -9);  //��
		MineSearch(TileNum, -8); //������
		MineSearch(TileNum, -1);  //��
		MineSearch(TileNum, 1);   //����
		MineSearch(TileNum, 8);   //�޾Ʒ�
		MineSearch(TileNum, 9);   //�Ʒ�
		MineSearch(TileNum, 10);  //�����Ʒ�
		break;
	case GAME_LEVEL_NORMAL: // 16
		MineSearch(TileNum, -17);  //����
		MineSearch(TileNum, -16);  //��
		MineSearch(TileNum, -15); //������
		MineSearch(TileNum, -1);  //��
		MineSearch(TileNum, 1);   //����
		MineSearch(TileNum, 15);   //�޾Ʒ�
		MineSearch(TileNum, 16);   //�Ʒ�
		MineSearch(TileNum, 17);  //�����Ʒ�
		break;
	case GAME_LEVEL_HARD: //30
		MineSearch(TileNum, -31);  //����
		MineSearch(TileNum, -30);  //��
		MineSearch(TileNum, -29); //������
		MineSearch(TileNum, -1);  //��
		MineSearch(TileNum, 1);   //����
		MineSearch(TileNum, 29);   //�޾Ʒ�
		MineSearch(TileNum, 30);   //�Ʒ�
		MineSearch(TileNum, 31);  //�����Ʒ�
		break;
	}
}

void Mine::MineSearch(int TileNum, int num)
{
	if (GameLevel == GAME_LEVEL_EASY) //���� ���̵��ϰ��
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
	if (GameLevel == GAME_LEVEL_EASY) //���� ���̵��ϰ��
	{
		if (TileList[ListNum].y != 0 && TileList[ListNum].x != 0 && TileList[ListNum - 10].MineState == true) //������ Y�� 0�϶� ����X
			Count++;
		if (TileList[ListNum].y != 0 && TileList[ListNum - 9].MineState == true) //�� Y�� 0�϶� ���� X
			Count++;
		if (TileList[ListNum].y != 0 && TileList[ListNum].x != Width - 2 && TileList[ListNum - 8].MineState == true) //������ Y�� 0�϶� ���� X
			Count++;
		if (TileList[ListNum].x != 0 && TileList[ListNum - 1].MineState == true) //���� X�� 0�϶� ���� X
			Count++;
		if (TileList[ListNum].x != Width - 2 && TileList[ListNum + 1].MineState == true) //������ X�� ������ ���϶� ����X
			Count++;
		if (TileList[ListNum].y != Height - 1 && TileList[ListNum].x != 0 && TileList[ListNum + 8].MineState == true) //�޾Ʒ� Y�� �� �Ʒ��϶� ���� X
			Count++;
		if (TileList[ListNum].y != Height - 1 && TileList[ListNum + 9].MineState == true) //�Ʒ� Y�� �� �Ʒ��϶� ���� X
			Count++;
		if (TileList[ListNum].y != Height - 1 && TileList[ListNum].x != Width - 2 && TileList[ListNum + 10].MineState == true) //�����Ʒ� Y�� �� �Ʒ��϶� ���� X
			Count++;
	}



	if (GameLevel == GAME_LEVEL_NORMAL) //���� ���̵��ϰ��
	{

	}


	if (GameLevel == GAME_LEVEL_HARD) // ����� ���̵��ϰ��
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

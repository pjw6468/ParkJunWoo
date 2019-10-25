#include "Mine.h"

//�ʱ� 9*9 ���� 10��
//�߱� 16*16 ���� 40��
//��� 30*16 ���� 99��

Mine::Mine()
{
}

//void Mine::TileSet()
//{
//	int i = 0;
//	for (int y = 0; y < Height; y++)
//	{
//		for (int x = 0; x < Width; x += 2)
//		{
//			TileList[i].x = x;
//			TileList[i].y = y;
//			i++;
//		}
//	}
//	for (int i = 0; i < Width*Height; i++)
//	{
//		
//	}
//}

bool Mine::MineCheck(int x, int y)
{
	for (int i = 0; i < MineCount; i++)
	{
		if (x == MineList[i].x && y == MineList[i].y)
			return true;
	}
	return false;
}

void Mine::MineCreate(int Level)
{
	switch (Level)
	{
	case GAME_LEVEL_EASY:
		MineCount = 10;
		Width = 16;
		Height = 8;
		break;
	case GAME_LEVEL_NORMAL:
		MineCount = 40;
		Width = 30;
		Height = 15;
		break;
	case GAME_LEVEL_HARD:
		MineCount = 99;
		Width = 58;
		Height = 15;
		break;
	}
	MineList = new GAME_MINE[MineCount];
	//TileList = new GAME_TILE[Width*Height];
	//TileSet();
	for (int i = 0; i < MineCount; i++)
	{
		Rnum = rand() % Width; //���� x�� �����ٰ�
		if (Rnum % 2 !=0) { Rnum++; } //���� ���ڰ� Ȧ���� �̻��Ѱ����� �� ��쿡�� +1�����༭ x��ǥ�� ¦���� �������
		MineList[i].x = Rnum;
		MineList[i].y = rand() % Height; //���� y��
		for (int j = 0; j < i; j++){if (MineList[i].x == MineList[j].x && MineList[i].y == MineList[j].y) { i--;	break; }} //���� ��ǥ�� ��ĥ��� for�� �ٽõ����� ���� ����
	}
}

void Mine::MineShow()
{
	for (int i = 0; i < MineCount; i++)
	{
		gotoxy(MineList[i].x, MineList[i].y);
		cout << "��";
	}
}

void Mine::MineSearchManager(int x, int y)
{
	MineSearch(x, y, -2, -1);   //���� �밢�� ��
	MineSearch(x, y, 0, -1);    //��
	MineSearch(x, y, +2, -1);   //���� �밢�� ��
	MineSearch(x, y, -2, 0);    //����
	MineSearch(x, y, +2, 0);    //������
	MineSearch(x, y, -2, +1);   //���� �밢�� �Ʒ�
	MineSearch(x, y, 0, +1);    //�Ʒ�
	MineSearch(x, y, +2, +1);   //���� �밢�� �Ʒ�
}

void Mine::MineSearch(int x, int y,int AddX,int AddY)
{
	//bool Check = false;
	//bool MineCheck;
	//for (int i = 0; i < MineCount; i++)
	//{
	//	if (x + AddX == MineList[i].x && y+AddY == MineList[i].y) { Check = true; break; }
	//}
	////if (x == Width|| x == 0 || y == 0 || y == Height) { return; }
	//if (Check == false)
	//	MineSearch(x +AddX, y+AddY, AddX, AddY);
	//else
	//{
	//	MineCheck = NearMineSearchManager(x,y);
	//}
	//if (MineCheck == true)
	//	return;
	//----------------------------------------------------------------------------------------------------//
	bool Check;
	Check = NearMineSearchManager(x,y);
	if (Check == false)
		MineSearch(x, y, AddX, AddY);
	else
		return;
}
bool Mine::NearMineSearchManager(int x, int y)
{
	int NearMineCount = 0;
	NearMineCount += NearMineSearch(x - 2, y - 1);//���� �밢�� ��
	NearMineCount += NearMineSearch(x, y - 1);     //��
	NearMineCount += NearMineSearch(x + 2, y - 1); //���� �밢�� ��
	NearMineCount += NearMineSearch(x - 2, y);      //����
	NearMineCount += NearMineSearch(x + 2, y);    //������
	NearMineCount += NearMineSearch(x - 2, y + 1);//���� �밢�� �Ʒ�
	NearMineCount += NearMineSearch(x, y + 1);    //�Ʒ�
	NearMineCount += NearMineSearch(x + 2, y + 1);//���� �밢�� �Ʒ�
	gotoxy(x, y);
	if (x == Width+2 || x == 0 || y == 0 || y == Height+1) { return true; }
	if (NearMineCount == 0) {cout << "��";}
	else
	{
		if (NearMineCount == 1)
			cout << "��";
		else if (NearMineCount == 2)
			cout << "��";
		else if (NearMineCount == 3)
			cout << "��";
		else if (NearMineCount == 4)
			cout << "��";
		else if (NearMineCount == 5)
			cout << "��";
		else if (NearMineCount == 6)
			cout << "��";
		else if (NearMineCount == 7)
			cout << "��";
		else if (NearMineCount == 8)
			cout << "��";
		return true;
	}
	return false;
}

int Mine::NearMineSearch(int x, int y)
{
	for (int i = 0; i < MineCount; i++)
	{
		if (x == MineList[i].x && y == MineList[i].y)
			return 1;
	}
	return 0;
}

Mine::~Mine()
{
}

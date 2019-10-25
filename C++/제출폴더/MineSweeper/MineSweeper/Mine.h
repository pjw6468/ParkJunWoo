#pragma once
#include "Mecro.h"
struct GAME_TILE
{
	int x;
	int y;
	int NearMineCount;
	char Icon;
};
struct GAME_MINE
{
	int x;
	int y;
};

class Mine
{
private:
	int MineCount;
	int Rnum;
	int Width;
	int Height;
protected:
	GAME_MINE* MineList;
	GAME_TILE* TileList;
public:
	void TileSet();
	void MineCreate(int Level);
	void MineShow();
	void MineSearchManager(int x, int y);//MineSearch �Լ��� �������� �Լ�
	void MineSearch(int x, int y, int AddX,int AddY); //���ڰ� ��ó�� �ִ� ����� ã�� �Լ�
	bool NearMineSearchManager(int x, int y); // NearMineSearch �Լ��� �������� �Լ�
	int NearMineSearch(int x, int y); //�ֺ� 3*3����� ���ڰ����� ã�� �Լ�
	bool MineCheck(int x, int y); //���� ������ �������� Ȯ���ϴ� �Լ�
	inline int MineCountReturn() { return MineCount; }
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Mine();
	~Mine();
};


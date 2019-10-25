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
	void MineSearchManager(int x, int y);//MineSearch 함수를 쓰기위한 함수
	void MineSearch(int x, int y, int AddX,int AddY); //지뢰가 근처에 있는 블록을 찾는 함수
	bool NearMineSearchManager(int x, int y); // NearMineSearch 함수를 쓰기위한 함수
	int NearMineSearch(int x, int y); //주변 3*3블록의 지뢰갯수를 찾는 함수
	bool MineCheck(int x, int y); //누른 지점이 지뢰인지 확인하는 함수
	inline int MineCountReturn() { return MineCount; }
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Mine();
	~Mine();
};


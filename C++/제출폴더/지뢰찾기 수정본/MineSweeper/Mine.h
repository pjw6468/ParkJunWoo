#pragma once
#include "Mecro.h"
struct GAME_TILE
{
	int x;
	int y;
	int NearMineCount;
	bool MineState;
};
class Mine
{
private:
	int TileCount;
	int MineCount;
	int Rnum;
	int Width;
	int Height;
	bool Check;
protected:
	GAME_TILE* TileList;
public:
	void TileSet();
	void MineCreate(int Level);
	void MineShow();
	int NearMineSearch(int ListNum);
	inline int MineCountReturn() { return MineCount; }
	inline bool CheckReturn() { return Check; }
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Mine();
	~Mine();
};


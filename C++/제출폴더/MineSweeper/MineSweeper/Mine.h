#pragma once
#include "Mecro.h"
struct GAME_TILE
{
	int x;
	int y;
	int NearMineCount;
	bool MineState;
	bool Openstatus;
	string Icon;
};
class Mine
{
private:
	int GameLevel;
	int TileCount;
	int MineCount;
	int Rnum;
	int Width;
	int Height;
	bool Check;
protected:
	GAME_TILE* TileList;
public:
	void MineCreate(int Level);
	void MineShow();
	void MineSearchManage(int TileNum);
	void MineSearch(int TileNum,int Add);
	void NearTileOpen(int TIleNum);
	void TileOpen(int TileNum);
	void AllShow();
	bool MineCheck(int TileNum);
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


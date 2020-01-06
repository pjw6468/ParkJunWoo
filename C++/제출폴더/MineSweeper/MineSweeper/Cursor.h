#pragma once
#include "Mecro.h"


class Cursor
{
private:
	int x;
	int y;
	int NowTileNum;
	int TIleNumPM;
	int Width;
	int Height;
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
public:
	int CursorMove();
	void CursorSet(int Level);
	void CursorDraw();
	inline int ReturnX() { return x; }
	inline int ReturnY() { return y; }
		inline int ReturnTileNum() { return NowTileNum; }
	Cursor();
	~Cursor();
};


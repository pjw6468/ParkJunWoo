#pragma once
#include "Mecro.h"

struct FLAG
{
	int x;
	int y;
};

class Cursor
{
private:
	int x;
	int y;
	int OldX;
	int OldY;
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
	Cursor();
	~Cursor();
};


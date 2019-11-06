#pragma once
#include"Mecro.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13
#define YES 1
#define NO 0
class MapDraw
{
public:
	void CheckDraw(int Level);
	void DrawLine(int Start_y,int Width);
	void BoxDraw(int Start_x,int Start_y, int Width, int Height);
	void InputDelete(int End_x, int y);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void LineErase();
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};


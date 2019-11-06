#include "Cursor.h"



Cursor::Cursor()
{
}
void Cursor::CursorDraw()
{
	gotoxy(x, y);
}

int Cursor::CursorMove()
{
	char ch;
	if (kbhit())
	{
		ch = getch();
		if ((ch == 'a' || ch == 'A') && (x != 0))
			x -= 2;
		else if ((ch == 'd' || ch == 'D') && (x != Width))
			x += 2;
		else if ((ch == 'w' || ch == 'W') && (y != 0))
			y--;
		else if ((ch == 's' || ch == 'S') && (y != Height))
			y++;
		else if (ch == 'z' || ch == 'Z')
			return CURSOR_OPEN;
		else if (ch == 'f' || ch == 'F')
			return CURSOR_FLAG;
	}
	return CURSOR_MOVE;
}

void Cursor::CursorSet(int Level)
{
	switch (Level)
	{
	case 1:
		x = 6;
		y = 5;
		Width = 16;
		Height = 8;
		break;
	case 2:
		x = 8;
		y = 8;
		Width = 30;
		Height = 15;
		break;
	case 3:
		x = 16;
		y = 8;
		Width = 58;
		Height = 15;
		break;
	}
}

Cursor::~Cursor()
{
}

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
		{
			x -= 2;
			NowTileNum--;
		}
		else if ((ch == 'd' || ch == 'D') && (x != Width-2))
		{
			x += 2;
			NowTileNum++;
		}
		else if ((ch == 'w' || ch == 'W') && (y != 0))
		{
			y--; 
			NowTileNum -= TIleNumPM;
		}
		else if ((ch == 's' || ch == 'S') && (y != Height-1))
		{
			y++;
			NowTileNum += TIleNumPM;
		}
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
	case GAME_LEVEL_EASY:
		x = 0;
		y = 0;
		Width = 18;
		Height = 9;
		TIleNumPM = 9;
		break;
	case GAME_LEVEL_NORMAL:
		x = 0;
		y = 0;
		Width =32;
		Height = 16;
		TIleNumPM = 16;
		break;
	case 3:
		x = 0;
		y = 0;
		Width = 60;
		Height = 16;
		TIleNumPM = 30;
		break;
	}
	NowTileNum = 0;
}

Cursor::~Cursor()
{
}

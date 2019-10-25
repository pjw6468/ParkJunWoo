	#include "MapDraw.h"


MapDraw::MapDraw()
{

}
void MapDraw::CheckDraw(int Level)
{
	int Width;
	int Height;
	switch (Level)
	{
	case GAME_LEVEL_EASY:
		Width = 9;
		Height = 9;
		break;
	case GAME_LEVEL_NORMAL:
		Width = 16;
		Height = 16;
		break;
	case GAME_LEVEL_HARD:
		Width = 30;
		Height = 16;
		break;
	}

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
		//	if (y == 0 && x == 0)
		//		cout << "¦£";
		//	else if (y == 0 && x == Width - 1)
		//		cout << "¦¤";
		//	else if (y == Height - 1 && x == 0)
		//		cout << "¦¦";
		//	else if (y == Height - 1 && x == Width - 1)
		//		cout << "¦¥";
		//	else if (y == 0)
		//		cout << "¦¨";
		//	else if (y == Height - 1)
		//		cout << "¦ª";
		//	else if (x == 0)
		//		cout << "¦§";
		//	else if (x == Width - 1)
		//		cout << "¦©";
		//	else
		//		cout << "¦«";
		//}
			if (y == 0 && x == 0)
				cout << "¡á";
			else if (y == 0 && x == Width - 1)
				cout << "¡á";
			else if (y == Height - 1 && x == 0)
				cout << "¡á";
			else if (y == Height - 1 && x == Width - 1)
				cout << "¡á";
			else if (y == 0)
				cout << "¡á";
			else if (y == Height - 1)
				cout << "¡á";
			else if (x == 0)
				cout << "¡á";
			else if (x == Width - 1)
				cout << "¡á";
			else
				cout << "¡á";
		}
		cout << endl;
	}
	for (int x = 0; x < Width*2; x++)
	{
		gotoxy(x, Height);
		cout << "-";
	}
}
void MapDraw::DrawLine(int Start_y,int Width)
{
	for (int x = 2; x< Width-2; x++)
	{
		gotoxy(x, Start_y);
		cout << "=";
	}
}
void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x*2, y);
	cout << str;
	gotoxy(-1,-1);
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}
void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}
void MapDraw::InputDelete(int End_x, int y)
{
	for (int x = 60; x < End_x; x++)
	{
		gotoxy(x, y);
		cout << " ";
	}
}
void MapDraw::BoxErase(int Width, int Height)
{
	for (int y = 1; y < Height - 1; y++)
	{
		gotoxy(2, y);
		for (int x = 1; x < Width - 1; x++)
			cout << "  ";
	}
}

void MapDraw::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y+y);
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¡";
			cout << "¦¥";
		}
		else
		{
			cout << "¦¢";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "¦¢";
		}
	}
	return;
}

int MapDraw::MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
{
	int Select = 1;
	RED
	DrawPoint("¢¹", x, y);
	ORIGINAL
		while (1)
		{
			switch (getch())
			{
			case UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= AddCol;
					Select--;
				}
				break;
			case DOWN:
				if (Select + 1 <= MenuLen)
				{
					ErasePoint(x, y);
					y += AddCol;
					Select++;
				}
				break;
			case ENTER:
				return Select;
			}
			RED
				DrawPoint("¢¹", x, y);
			ORIGINAL
		}
}
void MapDraw::LineErase()
{
	for (int x = 20; x < 60; x++)
	{
		for (int y = 10; y < 20; y++)
		{
			gotoxy(x*2, y);
			cout << "  ";
		}
	}
}
MapDraw::~MapDraw()
{
}

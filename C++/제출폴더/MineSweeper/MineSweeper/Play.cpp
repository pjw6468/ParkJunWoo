#include "Play.h"



Play::Play()
{
}
void Play::Menu()
{
	while (1)
	{
		switch(MainMenu())
		{
			case 1:
				switch (m_iLevel = LevelMenu())
				{
				default:
					Playing();
					break;
				case 4:
					break;
				}
				break;
			case 2:
				return;
		}
	}
}
void Play::Playing()
{
	int Select;
	int NearCount;
	m_bGameFlag = true;
	MineCreate(m_iLevel);
	GameMenu(m_iLevel);
	CheckDraw(m_iLevel);
	CursorSet(m_iLevel);
	//MineShow(); //지뢰만 보여주는 함수
	//AllShow(); //모든거 다볼수있는 함수
	while (m_bGameFlag)
	{
		Select = CursorMove();
		CursorDraw();
		if (Select == CURSOR_OPEN)
		{
			if (MineCheck(ReturnTileNum()) == true)
				m_bGameFlag = false;
			else
			{
				//if (NearMineSearch(ReturnTileNum()) == 0) //근처에 지뢰가 없을때
				//{
				TileOpen(ReturnTileNum());
					MineSearchManage(ReturnTileNum());
				//}
				//else //근처에 지뢰가 있을때
				//{
				//	TileOpen(ReturnTileNum());
				//}
			}
		}
		else if (Select == CURSOR_FLAG)
		{
			MapDraw::gotoxy(TileList[ReturnTileNum()].x, TileList[ReturnTileNum()].y);
			cout << "★";
		}
	}
}

Play::~Play()
{
}

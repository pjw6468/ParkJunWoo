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
	MineShow(); //지뢰만 보여주는 함수
	//AllShow(); //모든거 다볼수있는 함수
	while (m_bGameFlag)
	{
		Select = CursorMove();
		CursorDraw();
		if (Select == CURSOR_OPEN)
		{
			if (MineCheck(ReturnTileNum()) == true && TileList[ReturnTileNum()].FlagStatus != true)
				m_bGameFlag = false;
			else if(MineCheck(ReturnTileNum())==false&&TileList[ReturnTileNum()].FlagStatus!=true)
			{
				if (TileList[ReturnTileNum()].Openstatus == false && TileList[ReturnTileNum()].FlagStatus != true)
				{
					TileOpen(ReturnTileNum());
					MineSearchManage(ReturnTileNum());
				}
			}
		}
		else if (Select == CURSOR_FLAG)
		{
			if (TileList[ReturnTileNum()].Openstatus != true && TileList[ReturnTileNum()].FlagStatus != true)
			{
				TileList[ReturnTileNum()].FlagStatus = true;
				MapDraw::gotoxy(TileList[ReturnTileNum()].x, TileList[ReturnTileNum()].y);
				cout << "★";
			}
			else if (TileList[ReturnTileNum()].Openstatus != true && TileList[ReturnTileNum()].FlagStatus != false)
			{
				TileList[ReturnTileNum()].FlagStatus = false;
				MapDraw::gotoxy(TileList[ReturnTileNum()].x, TileList[ReturnTileNum()].y);
				cout << "■";
			}
		}
		if (WinCheck() == false)
			m_bGameFlag = false;
	}
}

Play::~Play()
{
}

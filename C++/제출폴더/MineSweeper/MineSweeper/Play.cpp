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
	m_bGameFlag = true;
	MineCreate(m_iLevel);
	GameMenu(m_iLevel);
	CheckDraw(m_iLevel);
	CursorSet(m_iLevel);
	MineShow();
	while (m_bGameFlag)
	{
		Select = CursorMove();
		CursorDraw();
		if (Select == CURSOR_OPEN)
		{
			if (MineCheck(ReturnX(), ReturnY()))
			{
				m_bGameFlag = false;
			}
			else
			{
				if (!NearMineSearchManager(ReturnX(), ReturnY()))
					MineSearchManager(ReturnX(), ReturnY());
			}
		}
		else if (Select == CURSOR_FLAG)
			;
	}
}

Play::~Play()
{
}

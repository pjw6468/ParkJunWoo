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
	//MineShow(); //���ڸ� �����ִ� �Լ�
	//AllShow(); //���� �ٺ����ִ� �Լ�
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
				//if (NearMineSearch(ReturnTileNum()) == 0) //��ó�� ���ڰ� ������
				//{
				TileOpen(ReturnTileNum());
					MineSearchManage(ReturnTileNum());
				//}
				//else //��ó�� ���ڰ� ������
				//{
				//	TileOpen(ReturnTileNum());
				//}
			}
		}
		else if (Select == CURSOR_FLAG)
		{
			MapDraw::gotoxy(TileList[ReturnTileNum()].x, TileList[ReturnTileNum()].y);
			cout << "��";
		}
	}
}

Play::~Play()
{
}

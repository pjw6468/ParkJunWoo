#include "Interface.h"
//�ʱ� 9*9 ���� 10��
//�߱� 16*16 ���� 40��
//��� 30*16 ���� 99��

//system("mode con cols=80 lines=25");
Interface::Interface()
{
}
int Interface::MainMenu()
{
	int Select;
	system("mode con cols=60 lines=35");
	BoxDraw(0, 0, 30, 30);
	DrawMidText("�� �� �� ã �� ��", 30, 6);
	DrawMidText("1. ���� ����",30, 15);
	DrawMidText("2. ����", 30, 18);
	Select = MenuSelectCursor(2, 3, 10, 15);
	return Select;
}
int Interface::LevelMenu()
{
	int Select;
	BoxErase(30, 30);
	DrawMidText("���� ����", 30, 6);
	DrawMidText("1.�ʱ� : 9*9 ���� 10��", 30, 15);
	DrawMidText("2.�߱� : 16*16 ���� 40��", 30, 18);
	DrawMidText("3.��� : 30*16 ���� 99��", 30, 21);
	DrawMidText("4.���ư���",30, 24);
	Select = MenuSelectCursor(4, 3, 5, 15);
	return Select;
}
void Interface::GameMenu(int Level)
{
	switch (Level)
	{
	case GAME_LEVEL_EASY:
		system("mode con cols=22 lines=14");
		break;
	case GAME_LEVEL_NORMAL:
		system("mode con cols=36 lines=21");
		break;
	case GAME_LEVEL_HARD:
		system("mode con cols=62 lines=21");
		break;
	}
}

Interface::~Interface()
{
}

#include "Interface.h"
//초급 9*9 지뢰 10개
//중급 16*16 지뢰 40개
//고급 30*16 지뢰 99개

//system("mode con cols=80 lines=25");
Interface::Interface()
{
}
int Interface::MainMenu()
{
	int Select;
	system("mode con cols=60 lines=35");
	BoxDraw(0, 0, 30, 30);
	DrawMidText("★ 지 뢰 찾 기 ★", 30, 6);
	DrawMidText("1. 게임 시작",30, 15);
	DrawMidText("2. 종료", 30, 18);
	Select = MenuSelectCursor(2, 3, 10, 15);
	return Select;
}
int Interface::LevelMenu()
{
	int Select;
	BoxErase(30, 30);
	DrawMidText("레벨 선택", 30, 6);
	DrawMidText("1.초급 : 9*9 지뢰 10개", 30, 15);
	DrawMidText("2.중급 : 16*16 지뢰 40개", 30, 18);
	DrawMidText("3.고급 : 30*16 지뢰 99개", 30, 21);
	DrawMidText("4.돌아가기",30, 24);
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

#pragma once
#include "Mecro.h"
#include "MapDraw.h"
class Interface : public  MapDraw
{
private:
protected:
public:
	int MainMenu();
	int LevelMenu();
	void GameMenu(int Level);
	Interface();
	~Interface();
};


#pragma once
#include"Mecro.h"
#include "Interface.h"
#include "Cursor.h"
#include "Mine.h"
class Play :public Interface,Cursor,Mine
{
private:
	bool m_bGameFlag;
	int m_iLevel;
public:
	void Menu();
	void Playing();
	Play();
	~Play();
};


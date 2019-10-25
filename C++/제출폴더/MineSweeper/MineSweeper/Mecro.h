#pragma once
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
#include <fstream>
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
using namespace std;
enum CURSOR_SELECT
{
	CURSOR_MOVE = 1,
	CURSOR_OPEN,
	CURSOR_FLAG
};
enum GAME_LEVEL
{
	GAME_LEVEL_EASY =1,
	GAME_LEVEL_NORMAL,
	GAME_LEVEL_HARD
};
class Mecro
{
public:
	Mecro();
	~Mecro();
};


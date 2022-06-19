#pragma once
#include "WordData.h"
#include "Game.h"

class GameManager
{
public:
	bool menu_loop = true;
	bool game_loop = true;
	WordData wd_object;
	Game game_object;

	void Menu();
	void MainGame();
	void PostGame();
};
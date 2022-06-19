#include "GameLoop.h"

void GameLoop::MenuLoop()
{
	while (gm_object.menu_loop == true)
	{
		gm_object.Menu();
	}
}

void GameLoop::PostGameLoop()
{
	while (gm_object.game_loop == true)
	{
		gm_object.PostGame();
	}
}
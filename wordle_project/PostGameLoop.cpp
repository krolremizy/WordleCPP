#include "PostGameLoop.h"

void PostGameLoop::Loop()
{
	while (gm_object.game_loop == true)
	{
		gm_object.PostGame();
	}
}
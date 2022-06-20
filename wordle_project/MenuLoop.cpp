#include "MenuLoop.h"

void MenuLoop::Loop()
{
	while (gm_object.menu_loop == true)
	{
		gm_object.Menu();
	}
}
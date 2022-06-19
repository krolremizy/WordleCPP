#pragma once
#include "GameManager.h"

class GameLoop
{
public:

	GameManager gm_object;

	void MenuLoop();
	void PostGameLoop();
};
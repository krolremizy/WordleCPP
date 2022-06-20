#pragma once
#include "LoopHandler.h"
#include "GameManager.h"

class MenuLoop : public LoopHandler
{
public:

	GameManager gm_object;
	void Loop();
};
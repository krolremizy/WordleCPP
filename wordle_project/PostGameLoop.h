#pragma once
#include "LoopHandler.h"
#include "GameManager.h"

class PostGameLoop : public LoopHandler
{
public:
	GameManager gm_object;
	void Loop();
};
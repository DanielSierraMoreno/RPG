#pragma once
#include "InputManager.h"

class Player
{
private:

public:
	int x;
	int y;
	Player() { x = 10; y = 5; }
	void playerInputs(InputManager* inputs);
};


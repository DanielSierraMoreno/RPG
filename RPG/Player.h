#pragma once
#include "InputManager.h"
#include "ConsoleControl.h"

class Player
{
private:
public:	
	ConsoleControl consoleControl;

	enum PlayerState{UP,RIGHT,LEFT,DOWN,STAY,POTION};

	PlayerState playerState;
	int x;
	int y;
	char player;
	Player() { x = 16; y = 6; playerState = STAY; player = 'P'; }

};


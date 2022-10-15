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
	Player() { x = 10; y = 5; playerState = STAY; player = 'P'; }

};


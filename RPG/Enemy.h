#pragma once
#include "ConsoleControl.h"

class Enemy
{
private:
	ConsoleControl consoleControl;
public:	
	int x;
	int y;
	bool inMovement = true;
	char enemigo = 'E';
	void moveEnemy();
};


#pragma once
#include "ConsoleControl.h"
#include <json/json.h>

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


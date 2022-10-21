#pragma once
#include "ConsoleControl.h"
#include "Sala.h"

#include <json/json.h>
#include "Sala.h"

class Enemy
{
private:
	ConsoleControl consoleControl;
public:	
	int x;
	int y;
	bool inMovement = true;
	char enemigo = 'E';
	void moveEnemy(Sala* sala);
};


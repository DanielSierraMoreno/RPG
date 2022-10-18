#pragma once
#include "ConsoleControl.h"
#include <json/json.h>

class Cofre
{
private:
	ConsoleControl consoleControl;

public:
	int x;
	int y;
	char cofre = 'C';

	char spawnRandomObject();

};


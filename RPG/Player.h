#pragma once
#include "InputManager.h"
#include "ConsoleControl.h"
#include <json/json.h>

class Player
{
private:

	
public:	
	int vidas = 3;
	int monedas;
	int pociones;
	std::string weapon = "espada";
	ConsoleControl consoleControl;

	enum PlayerState{UP,RIGHT,LEFT,DOWN,STAY,POTION};

	PlayerState playerState;
	int x;
	int y;
	char player;
	Player() { x = 16; y = 6; playerState = STAY; player = 'J'; monedas = 0; }

	void addCoin();
	void addPotion();
	void addLife();

	void usePotion();

	void upgradeWeapon();

	void writeToJson();

	static Player* Parse(Json::Value jsonValue);

	Json::Value ToJsonValue();
	
};


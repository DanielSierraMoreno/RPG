#pragma once
#include "InputManager.h"
#include "ConsoleControl.h"
#include <json/json.h>

class Player
{
private:

	
public:	
	int vidas;
	int monedas;
	int pociones;

	bool gameloop;

	std::string weapon = "lanza";
	ConsoleControl consoleControl;

	enum PlayerState{UP,RIGHT,LEFT,DOWN,STAY,POTION};

	PlayerState playerState;
	int x;
	int y;
	char player;
	Player() { x = 16; y = 6; playerState = STAY; player = 'J'; monedas = 0; gameloop = true; vidas = 3; }

	void addCoin();
	void addPotion();
	void addLife();
	void receivedamage();
	void usePotion();

	void upgradeWeapon();

	void writeToJson();

	static Player* Parse(Json::Value jsonValue);

	Json::Value ToJsonValue();
	
};


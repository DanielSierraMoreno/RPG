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
	Player();

	void addCoin();
	void addPotion();
	void addLife();
	void receivedamage();
	void usePotion();

	void upgradeWeapon();

	void readPlayer();

	void savePlayer();
	void Parse(Json::Value jsonValue);

	Json::Value ToJsonValue();
	
};


#pragma once
#include "ConsoleControl.h"
#include "player.h"

#include <json/json.h>

class Sala;
class Enemy
{
private:
	ConsoleControl consoleControl;
	enum direction {ARRIBA,ABAJO,IZQ,DER,SPAWN};
public:	
	int x;
	int y;
	int vida;
	bool inMovement;
	bool esquivarEnY;
	direction direccion;
	Enemy();
	char enemigo = 'E';
	void moveEnemy(Sala* sala);
	void drawEnemy(int movX, int movY, Sala* sala);
	void attackPlayer(Player* player);
	void receiveDamage();


	Json::Value ToJsonValue();
};


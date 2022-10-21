#pragma once
#include "ConsoleControl.h"
#include "player.h"

#include <json/json.h>

class Sala;
class Enemy
{
private:
	ConsoleControl consoleControl;
public:	
	int x;
	int y;
	int vida;
	bool caminoBloqueado = false;
	bool inMovement = true;
	Enemy() { vida = 2; }
	char enemigo = 'E';
	void moveEnemy(Sala* sala);
	void drawEnemy(int movX, int movY, Sala* sala);
	void attackPlayer(Player* player);
	void receiveDamage();
};


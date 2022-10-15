#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
#include "Cofre.h"
#include "Player.h"


class Sala
{
private:
	std::string fileName;
	std::vector<Enemy> enemies;
	std::vector<Cofre> cofres;

public:	
	char sala[11][22];
	Player* player;
	Sala(std::string fileName) { this->fileName = fileName; }
	void leerSala();
	void pintarSala();
	void crearCofre();
	void crearEnemigo();
	void playerInputs(InputManager inputs);
	void playerAction();
};


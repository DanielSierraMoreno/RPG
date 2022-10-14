#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
#include "Cofre.h"
#include "Player.h"


class Sala
{
private:
	char sala[11][22];
	std::string fileName;
	std::vector<Enemy> enemies;
	std::vector<Cofre> cofres;
public:	
	Player* player;

	Sala(std::string fileName) { this->fileName = fileName; }
	void leerSala();
	void pintarSala();
	void crearCofre();
	void crearEnemigo();
};


#pragma once
#include <string>
#include <vector>
#include "Enemy.h"
#include "Cofre.h"
#include "Player.h"
#include <map>


class Sala
{
private:
	std::string fileName;
	std::vector<Enemy> enemies;
	std::vector<Cofre> cofres;
	std::map<string, string> locations;
public:	
	std::string location;
	char sala[11][22];
	Player* player;
	Sala(std::string fileName) { this->fileName = fileName; }
	void leerSala();
	void pintarSala();
	void crearCofre();
	void crearEnemigo();
	void playerInputs(InputManager inputs);
	void playerAction();
	void addPortal(string loc, string sala) { locations.insert({loc, sala}); }
};


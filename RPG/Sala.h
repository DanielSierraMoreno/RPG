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
	std::string JsonName;

public:	
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>();
	std::vector<Cofre> cofres;
	std::map<string, string> locations;
	int sizeX = 34; 
	int sizeY = 13;

	std::string location;
	char** sala = new char*[sizeY];
	Player* player;
	Sala(std::string fileName, std::string name) { this->fileName = fileName; JsonName = name; for (int i = 0; i < sizeY; ++i) { sala[i] = new char[sizeX]; } }
	void leerSala();
	void guardarSala();

	void pintarSala();
	void crearCofre();
	void crearEnemigo();
	void salirSala();
	void spawnRandomObject(int x, int y);

	void addPortal(string loc, string sala) { locations.insert({loc, sala}); }

	Enemy* Parse(Json::Value jsonValue);

	void leerEnemigos();
	void leerCofres();
	void guardarCofres();
	void guardarEnemigos();

};


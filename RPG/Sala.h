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

public:	
	std::vector<Enemy*>* enemies = new std::vector<Enemy*>();
	std::vector<Cofre> cofres;
	std::map<string, string> locations;
	int sizeX = 34; 
	int sizeY = 13;

	std::string location;
	char** sala = new char*[sizeY];
	Player* player;
	Sala(std::string fileName) { this->fileName = fileName; for (int i = 0; i < sizeY; ++i) { sala[i] = new char[sizeX];}}
	void leerSala();
	void pintarSala();
	void crearCofre();
	void crearEnemigo();
	void crearThreadEnemigo();
	void salirSala();

	void pintarElementos();
	void addPortal(string loc, string sala) { locations.insert({loc, sala}); }

	void leerEnemigos();
	void leerCofres();
	void guardarCofres();
	void guardarEnemigos();

};


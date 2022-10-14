#pragma once
#include <map>
#include "Sala.h"

class Mapa
{
private:
public:	
	std::map<std::string, Sala> mapa;
	Player player;
	void crearMapa();
	void leerMapa();
	void pintarMapa(std::string zona);
};


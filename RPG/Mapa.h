#pragma once
#include <map>
#include "Sala.h"

class Mapa
{
private:
public:	
	std::map<std::string, Sala> mapa;

	void crearMapa();
	void leerMapa();
	void guardarMapa();
	void pintarMapa(std::string zona);
};


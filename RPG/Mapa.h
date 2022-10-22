#pragma once
#include <map>
#include "Sala.h"
#include <json/json.h>

class Mapa
{
private:
public:	
	std::map<std::string, Sala> mapa;
	Player* player;
	std::string zona;
	Mapa(Player* player);
	void crearMapa();
	void leerMapa();
	void pintarMapa();
	Sala* salaActual() { return &mapa.find(zona)->second; }

	void playerInputs(InputManager* inputs);
	void playerAction();

	void eventoSala();

	void guardarPartida();
	void guardarSalaActual();
	void leerSalaActual();

	void cargarPartida();
	void leerTodosLosEnemigos();
	void leerTodosLosCofres();


};


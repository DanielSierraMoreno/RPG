#pragma once
#include <map>
#include "Sala.h"

class Mapa
{
private:
public:	
	bool enemigoCreado = false;
	std::map<std::string, Sala> mapa;
	Player* player;
	std::string zona;
	Mapa(Player* player) { this->player = player; }
	void crearMapa();
	void leerMapa();
	void pintarMapa();
	Sala* salaActual() { return &mapa.find(zona)->second; }

	void playerInputs(InputManager* inputs);
	void playerAction();

	void eventoSala();

	void leerPlayer();
	void leerZona();
	void guardarPlayer();
	void guardarZona();
};


#include "Mapa.h"
#include "Sala.h"
#include <iostream>

void Mapa::crearMapa() {
	Sala sala0("Mapa/Mapa0.txt");
	Sala sala1("Mapa/Mapa1.txt");
	Sala sala2("Mapa/Mapa2.txt");
	Sala sala3("Mapa/Mapa3.txt");
	Sala sala4("Mapa/Mapa4.txt");
	Sala sala5("Mapa/Mapa5.txt");
	Sala sala6("Mapa/Mapa6.txt");
	Sala sala7("Mapa/Mapa7.txt");
	Sala sala8("Mapa/Mapa8.txt");


	mapa.insert({"arribaIzq", sala0 });
	mapa.insert({ "arriba", sala1 });
	mapa.insert({ "arribaDer", sala2 });
	mapa.insert({ "medioIzq", sala3 });
	mapa.insert({ "medio", sala4 });
	mapa.insert({ "medioDer", sala5 });
	mapa.insert({ "abajoIzq", sala6 });
	mapa.insert({ "abajo", sala7 });
	mapa.insert({ "abajoDer", sala8 });
}
void Mapa::leerMapa() {
	try
	{
        for (auto it = mapa.begin(); it != mapa.end(); it++) {
			it->second.leerSala();
			it->second.player = player;
	    }
	}
	catch (std::string error) {
		std::cout << error;
	}
}

void Mapa::pintarMapa(std::string zona) {

	mapa.find(zona)->second.pintarSala();
}

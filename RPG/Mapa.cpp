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



	mapa.find("arribaIzq")->second.addPortal("Este", "arriba");
	mapa.find("arribaIzq")->second.addPortal("Sur", "medioIzq");

	mapa.find("arriba")->second.addPortal("Oeste", "arribaIzq");
	mapa.find("arriba")->second.addPortal("Sur", "medio");
	mapa.find("arriba")->second.addPortal("Este", "arribaDer");

	mapa.find("arribaDer")->second.addPortal("Oeste", "arriba");
	mapa.find("arribaDer")->second.addPortal("Sur", "medioDer");

	mapa.find("medioIzq")->second.addPortal("Norte", "arribaIzq");
	mapa.find("medioIzq")->second.addPortal("Este", "medio");
	mapa.find("medioIzq")->second.addPortal("Sur", "abajoIzq");

	mapa.find("medio")->second.addPortal("Norte", "arriba");
	mapa.find("medio")->second.addPortal("Sur", "abajo");
	mapa.find("medio")->second.addPortal("Oeste", "medioIzq");
	mapa.find("medio")->second.addPortal("Este", "medioDer");

	mapa.find("medioDer")->second.addPortal("Norte", "arribaDer");
	mapa.find("medioDer")->second.addPortal("Oeste", "medio");
	mapa.find("medioDer")->second.addPortal("Sur", "abajoDer");

	mapa.find("abajoIzq")->second.addPortal("Norte", "medioIzq");
	mapa.find("abajoIzq")->second.addPortal("Este", "abajo");

	mapa.find("abajo")->second.addPortal("Norte", "medio");
	mapa.find("abajo")->second.addPortal("Este", "abajoDer");
	mapa.find("abajo")->second.addPortal("Oeste", "abajoIzq");

	mapa.find("abajoDer")->second.addPortal("Norte", "medioDer");
	mapa.find("abajoDer")->second.addPortal("Oeste", "abajo");
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

void Mapa::pintarMapa() {

	mapa.find(zona)->second.pintarSala();
}

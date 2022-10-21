#include "Mapa.h"
#include "InputManager.h"
#include "ConsoleControl.h"
#include <thread>

int main() {
	//Teclas posibles
	vector<int> keys{ KB_UP , KB_DOWN , KB_LEFT , KB_RIGHT , KB_SPACE };

	InputManager inputManager(keys);

	std::thread inputController(&InputManager::StartListener, inputManager);
	inputController.detach();

	Player player;
	Mapa mapa(&player);
	mapa.crearMapa();
	mapa.leerMapa();
	mapa.zona = "medio";

	std::thread playerMove(&Mapa::playerInputs, &mapa, &inputManager);
	playerMove.detach();

	std::thread creadorCofreEnemigo(&Mapa::eventoSala, &mapa);
	creadorCofreEnemigo.detach();


	mapa.pintarMapa();


	while (mapa.player->gameloop)
	{
		//Cambio de sala al atravesar un portal 
		if (mapa.salaActual()->location != "") {
			mapa.salaActual()->salirSala();
			std::string loc = mapa.salaActual()->location;
			mapa.salaActual()->location = "";
			mapa.zona = loc;
			system("cls");
			mapa.pintarMapa();
		}

	}
	system("CLS");
	std::printf("\n\n\n\n\n\n                You died \n\n\n\n\n\n");
}
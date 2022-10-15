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
	mapa.zona = "arriba";
	mapa.pintarMapa();


	bool gameloop = true;

	while (gameloop)
	{
		mapa.salaActual()->playerInputs(inputManager);
		
	}

}
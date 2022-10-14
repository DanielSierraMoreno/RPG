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

	Mapa mapa;
	mapa.crearMapa();
	mapa.leerMapa();
	mapa.pintarMapa("medio");


	bool gameloop = true;

	while (gameloop)
	{
		std::thread playerMovement(&Player::playerInputs, mapa.player, &inputManager);
		playerMovement.detach();
		
	}

}
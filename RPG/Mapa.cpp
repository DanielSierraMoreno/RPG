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

void Mapa::playerInputs(InputManager* inputs) {


	while (true)
	{

		switch (inputs->GetKey())
		{
		case KB_UP:
			player->playerState = Player::UP;
			break;
		case KB_DOWN:
			player->playerState = Player::DOWN;

			break;
		case KB_LEFT:
			player->playerState = Player::LEFT;

			break;
		case KB_RIGHT:
			player->playerState = Player::RIGHT;

			break;
		case KB_SPACE:
			player->playerState = Player::POTION;

			break;
		default:
			break;
		}

		playerAction();
	}

}

void Mapa::playerAction() {


	switch (player->playerState)
	{
	case Player::UP:
	{
		if (salaActual()->sala[player->y - 1][player->x] == '#')break;
		else if (salaActual()->sala[player->y - 1][player->x] == 'E')
		{

		}
		else if (salaActual()->sala[player->y - 1][player->x] == 'C')
		{

		}
		else if (salaActual()->sala[player->y - 1][player->x] == 'O')
		{
			salaActual()->location = salaActual()->locations.find("Norte")->second;
			player->y += salaActual()->sizeY - 3;
		}
		else
		{
			player->consoleControl.LockMutex();

			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->y--;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;

			player->consoleControl.UnlockMutex();

		}
		player->playerState = Player::STAY;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		break;
	}
	case Player::RIGHT:
	{
		if (salaActual()->sala[player->y][player->x + 1] == '#')break;
		else if (salaActual()->sala[player->y][player->x + 1] == 'E')
		{

		}
		else if (salaActual()->sala[player->y][player->x + 1] == 'C')
		{

		}
		else if (salaActual()->sala[player->y][player->x + 1] == 'O')
		{
			salaActual()->location = salaActual()->locations.find("Este")->second;
			player->x -= salaActual()->sizeX - 4;

		}
		else
		{
			player->consoleControl.LockMutex();

			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->x++;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;

			player->consoleControl.UnlockMutex();

		}
		player->playerState = Player::STAY;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		break;
	}
	case Player::LEFT:
	{
		if (salaActual()->sala[player->y][player->x - 1] == '#')break;
		else if (salaActual()->sala[player->y][player->x - 1] == 'E')
		{

		}
		else if (salaActual()->sala[player->y][player->x - 1] == 'C')
		{

		}
		else if (salaActual()->sala[player->y][player->x - 1] == 'O')
		{
			salaActual()->location = salaActual()->locations.find("Oeste")->second;
			player->x += salaActual()->sizeX - 4;

		}
		else
		{
			player->consoleControl.LockMutex();

			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->x--;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;

			player->consoleControl.UnlockMutex();

		}
		player->playerState = Player::STAY;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		break;
	}
	case Player::DOWN:
	{
		if (salaActual()->sala[player->y + 1][player->x] == '#')break;
		else if (salaActual()->sala[player->y + 1][player->x] == 'E')
		{

		}
		else if (salaActual()->sala[player->y + 1][player->x] == 'C')
		{

		}
		else if (salaActual()->sala[player->y + 1][player->x] == 'O')
		{
			salaActual()->location = salaActual()->locations.find("Sur")->second;
			player->y -= salaActual()->sizeY - 3;

		}
		else
		{
			player->consoleControl.LockMutex();

			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->y++;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;

			player->consoleControl.UnlockMutex();

		}
		player->playerState = Player::STAY;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		break;
	}
	case Player::POTION:
	{


		break;
	}
	default:
		break;
	}
}


void Mapa::eventoSala() {
	
	while (true)
	{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	switch ((int)rand()% 2)
	{
	case 0:
		salaActual()->crearCofre();
		break;
	case 1:
		salaActual()->crearEnemigo();
		break;
	default:
		break;
	}
	}



}

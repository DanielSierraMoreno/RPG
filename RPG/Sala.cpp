#include "Sala.h"
#include "ConsoleControl.h"

#include <iostream>
#include <fstream>
#include <string>
#include <random>

void Sala::leerSala() {
	std::fstream mapa(fileName, std::ios::in);

	if (!mapa.is_open()) throw "Error reading file " + fileName;

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapa >> std::noskipws >> sala[y][x];
		}
	}
	mapa.close();
	//Al leer el mapa se leen los enters, en la ultima linea no tiene que mostrar nada
	sala[sizeY-1][sizeX-1] = ' ';

}

void Sala::pintarSala() {
	for (int i = 0; i < cofres.size(); i++) {
		sala[cofres[i].y][cofres[i].x] = cofres[i].cofre;
	}
	for (int i = 0; i < enemies.size(); i++) {
		sala[enemies[i].y][enemies[i].x] = enemies[i].enemigo;
	}
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			std::cout << sala[y][x];
		}
	}
	player->consoleControl.SetPosition(player->x, player->y);
	std::cout << player->player;
}
void Sala::crearCofre() {
	Cofre cofre;
	bool espacioIncorrecto = true;
	int y;
	int x;
	while (espacioIncorrecto) {
		x = rand() % (sizeX-2) + 1;
		y = rand() % 1 + (sizeY-2);
		if (sala[y][x] == ' ')
		{
			if (y == player->y - 1 && x == player->x - 1) {}
			else if (y == player->y - 1 && x == player->x) {}
			else if (y == player->y - 1 && x == player->x + 1) {}
			else if (y == player->y && x == player->x - 1) {}
			else if (y == player->y && x == player->x + 1) {}
			else if (y == player->y + 1 && x == player->x - 1) {}
			else if (y == player->y + 1 && x == player->x) {}
			else if (y == player->y + 1 && x == player->x + 1) {}
			else
			{
				espacioIncorrecto = false;
			}
		}
	}
	cofre.x = x;
	cofre.y = y;

	cofres.push_back(cofre);

}
void Sala::crearEnemigo() {
	Enemy enemy;
	bool espacioIncorrecto = true;
	int y;
	int x;
	while (espacioIncorrecto) {
		x = rand() % (sizeX-2) + 1;
		y = rand() % 1 + (sizeY-2);
		if (sala[y][x] == ' ')
		{
			if (y == player->y - 1 && x == player->x - 1) {}
			else if (y == player->y - 1 && x == player->x) {}
			else if (y == player->y - 1 && x == player->x + 1) {}
			else if (y == player->y && x == player->x - 1) {}
			else if (y == player->y && x == player->x + 1) {}
			else if (y == player->y + 1 && x == player->x - 1) {}
			else if (y == player->y + 1 && x == player->x) {}
			else if (y == player->y + 1 && x == player->x + 1) {}
			else
			{
				espacioIncorrecto = false;
			}
		}
	}
	enemy.x = x;
	enemy.y = y;

	enemies.push_back(enemy);
}


void Sala::playerInputs(InputManager inputs) {



	switch (inputs.GetKey())
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

void Sala::playerAction() {


	switch (player->playerState)
	{
	case Player::UP:
		if (sala[player->y - 1][player->x] == '#')break;
		else if (sala[player->y - 1][player->x] == 'E')
		{

		}
		else if (sala[player->y - 1][player->x] == 'C')
		{

		}
		else if (sala[player->y - 1][player->x] == 'O')
		{
			location = locations.find("Norte")->second;
			player->y += sizeY - 3;
		}
		else
		{
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->y--;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;
		}
		player->playerState = Player::STAY;

		break;
	case Player::RIGHT:
		if (sala[player->y][player->x + 1] == '#')break;
		else if (sala[player->y][player->x + 1] == 'E')
		{

		}
		else if (sala[player->y][player->x + 1] == 'C')
		{

		}
		else if (sala[player->y][player->x + 1] == 'O')
		{
			location = locations.find("Este")->second;
			player->x -= sizeX-4;

		}
		else
		{
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->x++;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;
		}
		player->playerState = Player::STAY;

		break;
	case Player::LEFT:
		if (sala[player->y][player->x - 1] == '#')break;
		else if (sala[player->y][player->x - 1] == 'E')
		{

		}
		else if (sala[player->y][player->x - 1] == 'C')
		{

		}
		else if (sala[player->y][player->x - 1] == 'O')
		{
			location = locations.find("Oeste")->second;
			player->x += sizeX - 4;

		}
		else
		{
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->x--;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;
		}
		player->playerState = Player::STAY;

		break;
	case Player::DOWN:
		if (sala[player->y + 1][player->x] == '#')break;
		else if (sala[player->y + 1][player->x] == 'E')
		{

		}
		else if (sala[player->y + 1][player->x] == 'C')
		{

		}
		else if (sala[player->y + 1][player->x] == 'O')
		{
			location = locations.find("Sur")->second;
			player->y -= sizeY - 3;

		}
		else
		{
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << ' ';
			player->y++;
			player->consoleControl.SetPosition(player->x, player->y);
			std::cout << player->player;
		}
		player->playerState = Player::STAY;

		break;
	case Player::POTION:

		break;
	default:
		break;
	}
}

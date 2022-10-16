#include "Sala.h"
#include "ConsoleControl.h"

#include <iostream>
#include <fstream>
#include <string>
#include <random>

void Sala::leerSala() {
	std::fstream mapa(fileName, std::ios::in);

	if (!mapa.is_open()) throw "Error reading file " + fileName;

	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 22; x++) {
			mapa >> std::noskipws >> sala[y][x];
		}
	}
	mapa.close();

	for (int i = 0; i < cofres.size(); i++) {
		sala[cofres[i].y][cofres[i].x] = cofres[i].cofre;
	}
	for (int i = 0; i < enemies.size(); i++) {
		sala[enemies[i].y][enemies[i].x] = enemies[i].enemigo;
	}
}

void Sala::pintarSala() {
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 22; x++) {
			std::cout << sala[y][x];
		}
	}
}
void Sala::crearCofre() {
	Cofre cofre;
	bool espacioIncorrecto = true;
	int y;
	int x;
	while (espacioIncorrecto) {
		x = rand() % 19 + 1;
		y = rand() % 1 + 9;
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
		x = rand() % 19 + 1;
		y = rand() % 1 + 9;
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

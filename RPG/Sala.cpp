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

		enemies[i].inMovement = true;
		std::thread enemyThread(&Enemy::moveEnemy, &enemies[i]);
		enemyThread.detach();

	}
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			std::cout << sala[y][x];
		}
	}
	player->consoleControl.LockMutex();

	player->consoleControl.SetPosition(player->x, player->y);
	std::cout << player->player;

	player->consoleControl.UnlockMutex();

}

void Sala::crearCofre() {
	Cofre cofre;
	bool espacioIncorrecto = true;
	int y;
	int x;
	while (espacioIncorrecto) {
		x = rand() % (sizeX-2) + 1;
		y = rand() % (sizeY-2) + 1;
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

	player->consoleControl.LockMutex();

	player->consoleControl.SetPosition(cofre.x, cofre.y);
	std::cout << cofre.cofre;

	player->consoleControl.UnlockMutex();

}
void Sala::crearEnemigo() {
	Enemy enemy;
	bool espacioIncorrecto = true;
	int y;
	int x;
	while (espacioIncorrecto) {
		x = rand() % (sizeX-2) + 1;
		y = rand() % (sizeY-2) + 1;
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

	std::thread enemyThread(&Enemy::moveEnemy, &enemy);
	enemyThread.detach();

	enemies.push_back(enemy);
}

void Sala::salirSala() {
	for (int i = 0; i < enemies.size(); i++) {

		enemies[i].inMovement = false;

	}
}



void Sala::leerEnemigos() {

}
void Sala::leerCofres() {

}
void Sala::guardarCofres() {

}
void Sala::guardarEnemigos() {

}


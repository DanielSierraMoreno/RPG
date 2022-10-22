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

void Sala::guardarSala() {
	std::fstream mapa(fileName, std::ios::out);

	if (!mapa.is_open()) throw "Error reading file " + fileName;

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapa << sala[y][x];
		}
	}
	mapa.close();

}

void Sala::pintarSala() {

	for (int i = 0; i < cofres.size(); i++) {
		sala[cofres[i].y][cofres[i].x] = cofres[i].cofre;
	}

	player->consoleControl.LockMutex();

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			std::cout << sala[y][x];
		}
	}
	for (int i = 0; i < enemies->size(); i++) {
		((*enemies)[i])->inMovement = true;
		std::thread enemyMove(&Enemy::moveEnemy, (*enemies)[i], this);
		enemyMove.detach();

	}

	player->consoleControl.SetPosition(player->x, player->y);
	std::cout << player->player;

	player->consoleControl.SetPosition(50, 1);
	std::cout << "Vidas: " << player->vidas;

	player->consoleControl.SetPosition(50, 3);
	std::cout << "Monedas: " << player->monedas;

	player->consoleControl.SetPosition(50, 5);
	std::cout << "Pociones: " << player->pociones;

	player->consoleControl.SetPosition(50, 7);
	std::cout << "Arma: " << player->weapon;

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

	sala[y][x] = cofre.cofre;
	cofres.push_back(cofre);

	player->consoleControl.LockMutex();

	player->consoleControl.SetPosition(cofre.x, cofre.y);
	std::cout << cofre.cofre;

	player->consoleControl.UnlockMutex();

}
void Sala::crearEnemigo() {
	Enemy* enemy = new Enemy();
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
	enemy->x = x;
	enemy->y = y;



	enemies->push_back(enemy);


	std::thread  enemyMove(&Enemy::moveEnemy, enemy, this);
	enemyMove.detach();
}


void Sala::salirSala() {
	for (int i = 0; i < enemies->size(); i++) {

		((*enemies)[i])->inMovement = false;

	}
}

void Sala::spawnRandomObject(int x, int y) {

	int i = rand() % 20;

	player->consoleControl.LockMutex();

	player->consoleControl.SetPosition(x, y);
	if (i < 15) {
		sala[y][x] = 'M';
		std::cout << 'M';
	}
	else if (i >= 15 && i < 19) {
		sala[y][x] = 'P';
		std::cout << 'P';
	}
	else {
		sala[y][x] = 'A';
		std::cout << 'A';
	}
	player->consoleControl.UnlockMutex();

}

Enemy* Sala::Parse(Json::Value jsonValue)
{
	try
	{
		Enemy* enemy = new Enemy();
		enemy->vida = jsonValue["life"].asInt();
		enemy->x = jsonValue["posX"].asInt();
		enemy->y = jsonValue["posY"].asInt();
		enemy->inMovement = jsonValue["inMove"].asBool();

		return enemy;

	}
	catch (const std::exception&)
	{
	}
}

void Sala::leerEnemigos() {
	std::ifstream* jsonReadFile = new std::ifstream("Enemigos/" + JsonName, std::ifstream::binary);

	if (!jsonReadFile->fail())
	{

		Json::Value jsonValue;
		*jsonReadFile >> jsonValue;
		jsonReadFile->close();


		for (int i = 0; i < jsonValue["numeroEnemigos"].asInt(); i++)
		{
			Enemy* enemy = Sala::Parse(jsonValue["Enemigo" + to_string(i)]);
			enemies->push_back(enemy);
		}
	}
}
void Sala::leerCofres() {
	std::ifstream* jsonReadFile = new std::ifstream("Cofres/" + JsonName, std::ifstream::binary);

	if (!jsonReadFile->fail())
	{

		Json::Value jsonValue;
		*jsonReadFile >> jsonValue;
		jsonReadFile->close();


		for (int i = 0; i < jsonValue["numeroCofres"].asInt(); i++)
		{
			Cofre cofre;
			cofre.x = jsonValue["Cofre" + to_string(i) + "x"].asInt();
			cofre.y = jsonValue["Cofre" + to_string(i) + "y"].asInt();

			cofres.push_back(cofre);
		}

	}
}
void Sala::guardarCofres() {
	std::ofstream* jsonWriteFile = new std::ofstream("Cofres/" + JsonName, std::ifstream::binary);

	Json::Value newJsonValue;


	if (!jsonWriteFile->fail())
	{
		for (int i = 0; i < cofres.size(); i++)
		{
			newJsonValue["Cofre" + to_string(i) + "x"] = cofres[i].x;
			newJsonValue["Cofre" + to_string(i) + "y"] = cofres[i].y;

		}
		newJsonValue["numeroCofres"] = cofres.size();

		*jsonWriteFile << newJsonValue;

		jsonWriteFile->close();
	}
}
void Sala::guardarEnemigos() {
	std::ofstream* jsonWriteFile = new std::ofstream("Enemigos/" + JsonName, std::ifstream::binary);

	Json::Value newJsonValue;



	if (!jsonWriteFile->fail())
	{
	for (int i = 0; i < enemies->size(); i++)
	{
		newJsonValue["Enemigo" + to_string(i)] = (*enemies)[i]->ToJsonValue();
	}
	newJsonValue["numeroEnemigos"] = enemies->size();

		*jsonWriteFile << newJsonValue;

		jsonWriteFile->close();
	}
}


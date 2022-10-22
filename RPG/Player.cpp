#include "Player.h"
#include "ConsoleControl.h"
#include "Sala.h"
#include <iostream>
#include <fstream>
#include <thread>

void Player::receivedamage() {
    if (vidas > 1)
    {
        vidas--;

        consoleControl.SetPosition(50, 1);
        std::cout << "Vidas: " << vidas;

    }
    else
    {

        gameloop = false;
    }
   
}

void Player::addCoin() {
	monedas++;


	consoleControl.SetPosition(50, 3);
	std::cout << "Monedas: " << monedas;

}
void Player::addPotion() {
	pociones++;


	consoleControl.SetPosition(50, 5);
	std::cout << "Pociones: " << pociones;

}
void Player::addLife() {
	vidas++;


	consoleControl.SetPosition(50, 1);
	std::cout << "Vidas: " << vidas;

}
void Player::upgradeWeapon() {
	weapon = "lanza ";


	consoleControl.SetPosition(50, 7);
	std::cout << "Arma: " << weapon;

}



void Player::Parse(Json::Value jsonValue)
{
    try
    {

        this->vidas = jsonValue["life"].asInt();
        this->monedas = jsonValue["coins"].asInt();
        this->pociones = jsonValue["potions"].asInt();
        this->x = jsonValue["posX"].asInt();
        this->y = jsonValue["posY"].asInt();
        this->weapon = jsonValue["weapon"].asString();


    }
    catch (const std::exception&)
    {
   
    }
}

void Player::readPlayer()
{
    std::ifstream* jsonReadFile = new std::ifstream("Player.json", std::ifstream::binary);

    if(!jsonReadFile->fail())
    {
    
        Json::Value jsonValue;
        *jsonReadFile >> jsonValue;
        jsonReadFile->close();
    
        
       Player::Parse(jsonValue["Player"]);

    }

}

Json::Value Player::ToJsonValue()
{
    Json::Value jsonValue;

    jsonValue["life"] = this->vidas;
    jsonValue["coins"] = this->monedas;
    jsonValue["potions"] = this->pociones;
    jsonValue["posX"] = this->x;
    jsonValue["posY"] = this->y;
    jsonValue["weapon"] = this->weapon;

    return jsonValue;
}

void Player::savePlayer() {
    std::ofstream* jsonWriteFile = new std::ofstream("Player.json", std::ifstream::binary);

    Json::Value newJsonValue; 
    newJsonValue["Player"] = this->ToJsonValue();

    if (!jsonWriteFile->fail())
    {
        *jsonWriteFile << newJsonValue;

        jsonWriteFile->close();
    }

    
}


void Player::usePotion() {
	pociones--;

	consoleControl.SetPosition(50, 5);
	std::cout << "Pociones: " << pociones;

	addLife();
}

Player::Player(){
  playerState = STAY; 
  player = 'J';  
  gameloop = true; 
  readPlayer();
}
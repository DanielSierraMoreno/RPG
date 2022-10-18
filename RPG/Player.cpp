#include "Player.h"
#include "ConsoleControl.h"
#include "Sala.h"
#include <iostream>
#include <fstream>
#include <thread>


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



static Player* Parse(Json::Value jsonValue)
{
    Player* newPlayer = new Player();
    try
    {

        newPlayer->vidas = jsonValue["life"].asInt();
        newPlayer->monedas = jsonValue["coins"].asInt();

       /* Json::Value weaponsArray = Json::Value(Json::arrayValue);
        weaponsArray = jsonValue["weapons"];

        for (int i = 0; i < weaponsArray.size(); i++)
        {
            Json::Value weaponJson = weaponsArray[i];
            Weapon* newWeapon = Weapon::Parse(weaponJson);

            if (newWeapon != nullptr)
            {
                newCharacter->weapons->push_back(newWeapon);
            }
        }*/

        return newPlayer;
    }
    catch (const std::exception&)
    {
        delete newPlayer;
        return nullptr;
    }
}

void Player::writeToJson()
{
    std::ifstream* jsonReadFile = new std::ifstream("Player.json", std::ifstream::binary);

   /* if(!jsonReadFile->fail())
    {
    
        Json::Value jsonValue;
        *jsonReadFile >> jsonValue;
        jsonReadFile->close();
    
        Player* newChar = Player::Parse(jsonValue["Player"]); 


        if (newChar != nullptr)
        {

            Json::Value newJsonValue; 
            newJsonValue["Player"] = newChar->ToJsonValue(); 
           

            std::ofstream* jsonWriteFile = new std::ofstream("Player.json", std::ifstream::binary); 

            if (!jsonWriteFile->fail()) 
            {
                *jsonWriteFile << newJsonValue; 
                jsonWriteFile->close(); 
            }
        }
    
    
    
    }*/

}

Json::Value Player::ToJsonValue()
{
    Json::Value jsonValue;

    jsonValue["life"] = this->vidas;
    jsonValue["coins"] = this->monedas;
    return jsonValue;
}

void Player::usePotion() {
	pociones--;

	consoleControl.SetPosition(50, 5);
	std::cout << "Pociones: " << pociones;

	addLife();
}

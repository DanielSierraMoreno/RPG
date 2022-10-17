#include "Player.h"
#include "ConsoleControl.h"
#include "Sala.h"

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
	weapon = "lanza";


	consoleControl.SetPosition(50, 7);
	std::cout << "Arma: " << weapon;

}

void Player::usePotion() {
	pociones--;

	consoleControl.SetPosition(50, 5);
	std::cout << "Pociones: " << pociones;

	addLife();
}

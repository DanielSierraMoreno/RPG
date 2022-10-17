#include "Enemy.h"
#include <chrono>
#include <thread>
#include <iostream>


void Enemy::moveEnemy() {

	while (inMovement)
	{
    consoleControl.LockMutex();

	consoleControl.SetPosition(x,y);
	std::cout << enemigo;

	consoleControl.UnlockMutex();

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	}

}



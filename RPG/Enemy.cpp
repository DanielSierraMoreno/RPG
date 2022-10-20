#include "Enemy.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "Sala.h"


void Enemy::moveEnemy(Sala* sala) {

	while (inMovement)
	{
    consoleControl.LockMutex();
	consoleControl.SetPosition(x, y);
	std::cout << ' ';
	sala->sala[y][x] = ' ';
	consoleControl.SetPosition(x,y);
	std::cout << enemigo;
	x++;
	sala->sala[y][x] = enemigo;
	consoleControl.UnlockMutex();

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	}

}



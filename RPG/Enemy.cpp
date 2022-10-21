#include "Enemy.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "Sala.h"
#include <cmath>

void Enemy::drawEnemy(int movX, int movY, Sala* sala) {

	sala->sala[y][x] = ' ';
	consoleControl.SetPosition(x, y);
	std::cout << ' ';

	x += movX;
	y += movY;

	sala->sala[y][x] = enemigo;
	consoleControl.SetPosition(x,y);
	if (vida == 2)
	{
	std::cout << "\x1b[33m" << enemigo << "\x1b[0m"; //Color amarillo
	}
	else
	{
	std::cout << "\x1b[31m" << enemigo << "\x1b[0m"; // Color rojo
	}
}

void Enemy::attackPlayer(Player* player) {
	player->receivedamage();
}

void Enemy::receiveDamage() {
	vida--;
}

void Enemy::moveEnemy(Sala* sala) {

	while (inMovement)
	{
    consoleControl.LockMutex();

	if (abs(sala->player->x - x) < abs(sala->player->y - y))
	{
		if ((sala->player->y - y) < 0)
		{
			if (sala->sala[y-1][x] == ' ') 
			{
				drawEnemy(0, -1, sala);
			}
			else if (sala->sala[y - 1][x] == 'J')
			{
				attackPlayer(sala->player);
			}
			else
			{
				if ((sala->player->x - x) < 0)
				{
					if (sala->sala[y][x - 1] == ' ')
					{
						drawEnemy(-1, 0, sala);
					}
				}
				else
				{
					if (sala->sala[y][x + 1] == ' ')
					{
						drawEnemy(1, 0, sala);
					}
				}
			}
		}
		else
		{
			if (sala->sala[y + 1][x] == ' ')
			{
				drawEnemy(0, 1, sala);
			}
			else if (sala->sala[y + 1][x] == 'J')
			{
				attackPlayer(sala->player);
			}
			else
			{
				if ((sala->player->x - x) < 0)
				{
					if (sala->sala[y][x - 1] == ' ')
					{
						drawEnemy(-1, 0, sala);
					}
				}
				else
				{
					if (sala->sala[y][x + 1] == ' ')
					{
						drawEnemy(1, 0, sala);
					}
				}
			}
		}
	}
	else 
	{
		if ((sala->player->x - x) < 0)
		{
			if (sala->sala[y][x-1] == ' ')
			{
				drawEnemy(-1, 0, sala);
			}
			else if (sala->sala[y][x-1] == 'J')
			{
				attackPlayer(sala->player);
			}
			else
			{
				if ((sala->player->y - y) < 0)
				{
					if (sala->sala[y-1][x] == ' ')
					{
						drawEnemy(0, -1, sala);
					}
				}
				else
				{
					if (sala->sala[y+1][x] == ' ')
					{
						drawEnemy(0, 1, sala);
					}
				}
			}
		}
		else
		{
			if (sala->sala[y][x+1] == ' ')
			{
				drawEnemy(1, 0, sala);
			}
			else if (sala->sala[y][x+1] == 'J')
			{
				attackPlayer(sala->player);
			}
		}
	}

	consoleControl.UnlockMutex();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}

}



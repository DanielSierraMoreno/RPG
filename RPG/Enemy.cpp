#include "Enemy.h"
#include "Sala.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
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
	consoleControl.SetPosition(x, y);
	std::cout << "\x1b[31m" << enemigo << "\x1b[0m"; // Color rojo

}

void Enemy::moveEnemy(Sala* sala) {

	while (inMovement)
	{
    consoleControl.LockMutex();

	if (abs(sala->player->x - x) < abs(sala->player->y - y) && (direccion != direction::DER && direccion != direction::IZQ))
	{
		if ((sala->player->y - y) < 0 && direccion != direction::ABAJO)
		{
			if (sala->sala[y-1][x] == ' ') 
			{
				drawEnemy(0, -1, sala);
				direccion = direction::SPAWN;

			}
			else if (sala->sala[y - 1][x] == 'J')
			{
				attackPlayer(sala->player);
				direccion = direction::SPAWN;

			}
			else
			{
	
					if (sala->sala[y][x - 1] == ' ' && sala->sala[y-1][x - 1] == ' ')
					{
						drawEnemy(-1, 0, sala);
						direccion = direction::ARRIBA;

					}
					else if(sala->sala[y][x + 1] == ' ' && sala->sala[y - 1][x + 1] == ' ')
					{
						drawEnemy(1, 0, sala);
						direccion = direction::ARRIBA;

					}
					else if (sala->sala[y][x - 1] == ' ')
					{
						drawEnemy(-1, 0, sala);
						direccion = direction::IZQ;

					}
					else if (sala->sala[y][x + 1] == ' ')
					{
						drawEnemy(1, 0, sala);
						direccion = direction::DER;

					}
					else if (sala->sala[y+1][x] == ' ' && sala->sala[y + 1][x - 1] == ' ')
					{
						drawEnemy(0, 1, sala);
						direccion = direction::IZQ;

					}
					else if (sala->sala[y+1][x] == ' ' && sala->sala[y + 1][x + 1] == ' ')
					{
						drawEnemy(0, 1, sala);
						direccion = direction::DER;

					}
		
			}
		}
		else
		{
			if (sala->sala[y + 1][x] == ' ')
			{
				drawEnemy(0, 1, sala);
				direccion = direction::SPAWN;

			}
			else if (sala->sala[y + 1][x] == 'J')
			{
				attackPlayer(sala->player);
				direccion = direction::SPAWN;

			}
			else
			{
					if (sala->sala[y][x - 1] == ' ' && sala->sala[y+1][x - 1] == ' ')
					{
						drawEnemy(-1, 0, sala);
						direccion = direction::ABAJO;

					}
					else if(sala->sala[y][x + 1] == ' ' && sala->sala[y + 1][x + 1] == ' ')
					{
						drawEnemy(1, 0, sala);
						direccion = direction::ABAJO;

					}
					else if (sala->sala[y][x - 1] == ' ')
					{
						drawEnemy(-1, 0, sala);
						direccion = direction::IZQ;

					}
					else if (sala->sala[y][x + 1] == ' ')
					{
						drawEnemy(1, 0, sala);
						direccion = direction::DER;

					}
					else if (sala->sala[y-1][x] == ' ' && sala->sala[y - 1][x - 1] == ' ')
					{
						drawEnemy(0, -1, sala);
						direccion = direction::IZQ;

					}
					else if (sala->sala[y-1][x] == ' ' && sala->sala[y - 1][x + 1] == ' ')
					{
						drawEnemy(0, -1, sala);
						direccion = direction::DER;

					}
			}

		}
	}
	else 
	{
		if ((sala->player->x - x) < 0 && direccion != direction::DER)
		{
			if (sala->sala[y][x-1] == ' ')
			{
				drawEnemy(-1, 0, sala);
				direccion = direction::SPAWN;

			}
			else if (sala->sala[y][x-1] == 'J')
			{
				attackPlayer(sala->player);
				direccion = direction::SPAWN;

			}
			else
			{
				if (sala->sala[y-1][x] == ' ' && sala->sala[y - 1][x - 1] == ' ')
				{
					drawEnemy(0, -1, sala);
					direccion = direction::IZQ;

				}
				else if (sala->sala[y+1][x] == ' ' && sala->sala[y + 1][x - 1] == ' ')
				{
					drawEnemy(0, 1, sala);
					direccion = direction::IZQ;

				}
				else if (sala->sala[y-1][x] == ' ')
				{
					drawEnemy(0, -1, sala);
					direccion = direction::ARRIBA;

				}
				else if (sala->sala[y+1][x] == ' ')
				{
					drawEnemy(0, 1, sala);
					direccion = direction::ABAJO;

				}
				else if (sala->sala[y][x+1] == ' ' && sala->sala[y - 1][x + 1] == ' ')
				{
					drawEnemy(1, 0, sala);
					direccion = direction::ARRIBA;

				}
				else if (sala->sala[y][x+1] == ' ' && sala->sala[y + 1][x + 1] == ' ')
				{
					drawEnemy(1, 0, sala);
					direccion = direction::ABAJO;

				}
			}

		}
		else
		{
			if (sala->sala[y][x+1] == ' ')
			{
				drawEnemy(1, 0, sala);
				direccion = direction::SPAWN;

			}
			else if (sala->sala[y][x+1] == 'J')
			{
				attackPlayer(sala->player);
				direccion = direction::SPAWN;

			}
			else
			{
				if (sala->sala[y - 1][x] == ' ' && sala->sala[y - 1][x + 1] == ' ')
				{
					drawEnemy(0, -1, sala);
					direccion = direction::DER;

				}
				else if (sala->sala[y + 1][x] == ' ' && sala->sala[y + 1][x + 1] == ' ')
				{
					drawEnemy(0, 1, sala);
					direccion = direction::DER;

				}
				else if (sala->sala[y - 1][x] == ' ')
				{
					drawEnemy(0, -1, sala);
					direccion = direction::ARRIBA;

				}
				else if (sala->sala[y + 1][x] == ' ')
				{
					drawEnemy(0, 1, sala);
					direccion = direction::ABAJO;

				}
				else if (sala->sala[y][x-1] == ' ' && sala->sala[y - 1][x - 1] == ' ')
				{
					drawEnemy(-1, 0, sala);
					direccion = direction::ARRIBA;

				}
				else if (sala->sala[y][x-1] == ' ' && sala->sala[y + 1][x - 1] == ' ')
				{
					drawEnemy(-1, 0, sala);
					direccion = direction::ABAJO;

				}
			}

		}
	}

	consoleControl.UnlockMutex();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}

}






Json::Value Enemy::ToJsonValue()
{
	Json::Value jsonValue;

	jsonValue["life"] = this->vida;
	jsonValue["posX"] = this->x;
	jsonValue["posY"] = this->y;
	jsonValue["inMove"] = this->inMovement;


	return jsonValue;
}



Enemy::Enemy() {
	 vida = 2;
	 inMovement = true;
	 direccion = direction::SPAWN;
}
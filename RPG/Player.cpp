#include "Player.h"
#include "Timer.h"
#include "ConsoleControl.h"

#include <thread>

void Player::playerInputs(InputManager* inputs) {
	std::thread esperar(timer, 1.0f);
	esperar.join();

	if (!inputs->keyPressed())return;
	switch (inputs->GetKey())
	{
	case KB_UP:

		break;
	case KB_DOWN:

		break;
	case KB_LEFT:

		break;
	case KB_RIGHT:

		break;
	case KB_SPACE:

		break;
	default:
		break;
	}
}

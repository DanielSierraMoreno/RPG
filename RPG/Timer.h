#pragma once
#include <chrono>
#include <ctime>    

void timer(float waitTime) {
	std::time_t start = std::time(nullptr);


	while (start- std::time(nullptr) < waitTime)
	{
	}
}
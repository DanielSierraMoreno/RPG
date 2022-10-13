#include "Sala.h"
#include <iostream>
#include <fstream>
#include <string>

void Sala::leerSala() {
	std::fstream mapa(fileName, std::ios::in);

	if (!mapa.is_open()) throw "Error reading file " + fileName;

	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 22; x++) {
			mapa >> std::noskipws >> sala[y][x];
		}
	}
	mapa.close();
}
void Sala::guardarSala() {
	std::fstream mapa(fileName, std::ios::out);

	if (!mapa.is_open()) throw "Error reading file " + fileName;

	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 22; x++) {
			mapa << sala[y][x];
		}
	}
	mapa.close();
}
void Sala::pintarSala() {
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 22; x++) {
			std::cout << sala[y][x];
		}
	}
}

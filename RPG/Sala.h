#pragma once
#include <string>


class Sala
{
private:
	char sala[11][22];
	std::string fileName;
public:
	Sala(std::string fileName) { this->fileName = fileName; }
	void leerSala();
	void guardarSala();
	void pintarSala();

};


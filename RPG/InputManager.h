#pragma once
#include <vector>
#include <mutex>

using namespace std;

class InputManager
{
private:
    vector<int> validKeyCodes;
    vector<int>* inputsRead = new vector<int>();
    mutex* inputsReadMutex = new mutex();

    bool activated = false;
    mutex* activatedMutex = new mutex();
public:
    InputManager(vector<int> validKeyCodes); //Usamos por copia y no por puntero para que luego no lo puedan modificar
    void StartListener();
    void StopListener();
    int GetKey();
};


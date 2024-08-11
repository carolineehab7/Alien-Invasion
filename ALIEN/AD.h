#pragma once
#include <iostream>
#include "Units.h"
using namespace std;
class Game;

class AD : public Units {
private:

public:
	AD();
	AD(int id, string type, int jt, int health, int power, int AC);
	void attack();
	//void operator =(AD& ad);
};


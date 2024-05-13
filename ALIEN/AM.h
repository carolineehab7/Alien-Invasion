#pragma once
#include <iostream>
#include "Units.h"
using namespace std;
class Game;


class AM : public Units {
private:

public:
	AM(int id, string type, int jt, int health, int power, int AC);

	void attack();

}; 
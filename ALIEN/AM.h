#pragma once
#include <iostream>
#include <string>
#include "Units.h"
#include"AlienArmy.h"
using namespace std;
class Units;

class AM : public Units {
private:

public:
	AM(int id, string type, int jt, int health, int power, int AC);

	void attack();

};
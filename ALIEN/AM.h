#pragma once
#include <iostream>
#include "Units.h"
#include "AlienArmy.h"
#include"EarthArmy.h"
using namespace std;


class AM : public Units {
private:

public:
	AM(int id, string type, int jt, int health, int power, int AC);

	void attack();

};
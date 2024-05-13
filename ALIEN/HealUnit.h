#pragma once
#include "Units.h"
#include <string>
class HealUnit: public Units
{
public:
	HealUnit();
	HealUnit(int id, string type, int jt, int health, int power, int AC);
	void attack();

};


#pragma once
#include "Units.h"
class HealUnit: public Units
{
public:
	HealUnit();
	HealUnit(int id, string type, int jt, int health, int power, int AC);
	void attack();

};


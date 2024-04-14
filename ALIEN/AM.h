#pragma once
using namespace std;
#include "Units.h"
#include <iostream>
#include"AlienArmy.h"
class AM : public Units{
private:

public:
	AM(int id, string type, int jt, int health, int power, int AC);

	void attack();

};

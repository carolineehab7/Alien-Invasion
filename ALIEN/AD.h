#pragma once
using namespace std;
#include "Units.h"
#include <iostream>
#include"AlienArmy.h"
class AD : public Units{
private:

public:
	AD(int id, string type, int jt, int health, int power, int AC);

	void attack();

};

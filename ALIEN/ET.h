#pragma once
#include <iostream>
#include "ArrayStack.h"
#include "AM.h"
#include "AS.h"
#include "Game.h"
#include "ES.h"
#include"AlienArmy.h"
#include"EarthArmy.h"
#include "Units.h"
using namespace std;


class ET :public Units {
private:

public:
	ET(int id, string type, int jt, int health, int power, int AC);
	void attack();

};
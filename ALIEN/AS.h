#pragma once
#include <iostream>
#include <string>
#include "Units.h"
#include"AlienArmy.h"
using namespace std;

class AS : public Units{
private:

public:
	AS(int id, string type, int jt, int health, int power, int AC);
	void attack();
};
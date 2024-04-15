#pragma once
#include <iostream>
#include <string>
#include"AlienArmy.h"
using namespace std;
class Units;

class AS : public Units{
private:

public:
	AS(int id, string type, int jt, int health, int power, int AC);
	void attack();
};
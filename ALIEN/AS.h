#pragma once
#include <iostream>
#include "Units.h"
using namespace std;
class Game;


class AS : public Units{
private:

public:
	AS();
	AS(int id, string type, int jt, int health, int power, int AC);
	void attack();
};
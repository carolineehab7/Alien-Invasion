#pragma once
#include <iostream>
#include "Units.h"
#include "LinkedQueue.h"
#include <cmath>
#include "ES.h"
using namespace std;


class AS : public Units{
private:

public:
	AS();
	AS(int id, string type, int jt, int health, int power, int AC);
	void attack();
};
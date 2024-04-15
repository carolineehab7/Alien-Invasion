#pragma once
#include <iostream>
#include <string>
using namespace std;
class Units;

class AD : public Units{
private:

public:
	AD(int id, string type, int jt, int health, int power, int AC);
	void attack();
};

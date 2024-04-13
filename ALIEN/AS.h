#pragma once
#include <iostream>
using namespace std;
#include "Units.h"
#include<string>
#include"AlienArmy.h"
class AS : public Units{
private:

public:
	AS(int id, string type, int jt, int health, int power, int AC);
	void attack();
};

inline std::ostream& operator<<(std::ostream& os,AS& as) {
	os << as.getID();
	return os;
}

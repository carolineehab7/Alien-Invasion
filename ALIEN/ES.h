#pragma once
#include <iostream>
using namespace std;
#include "Units.h"
#include<string>
#include "EarthArmy.h"
class ES : public Units {
private:

};

inline std::ostream& operator<<(std::ostream& os, ES& es) {
	os << es.getID();
	return os;
}
public:
	ES(int id, string type, int jt, int health, int power, int AC);
	void attack();
};

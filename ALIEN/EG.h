#pragma once
#include "Units.h"
class EG:public Units {

};

inline std::ostream& operator<<(std::ostream& os, EG& eg) {
	os << eg.getID();
	return os;
}

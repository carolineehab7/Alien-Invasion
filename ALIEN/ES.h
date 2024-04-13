#pragma once
#include "Units.h"
class ES: public Units{

};

inline std::ostream& operator<<(std::ostream& os, ES& es) {
	os << es.getID();
	return os;
}

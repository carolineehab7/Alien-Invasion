#pragma once
#include "Units.h"
class AS : public Units{

};

inline std::ostream& operator<<(std::ostream& os,AS& as) {
	os << as.getID();
	return os;
}

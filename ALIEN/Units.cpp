#include "Units.h"
#include <string>
Units::Units(int id, string type, int JT, int health, int power, int AC) {
	setID(id);
	setType(type);
	setJoinTime(JT);
	setHealth(health);
	setPower(power);
	setAttackCapacity(AC);

}
void Units::setID(int id) {
	if (id > 0) {
		ID = id;
	}
}
void Units::setType(string type) {
	if (type == "EG")
		Type = "EG";
	else if (type == "ET")
		Type = "ET";
	else if (type == "ES")
		Type = "ES";
	else if (type == "AS")
		Type = "AS";
	else if (type == "AD")
		Type = "AD";
	else if (type == "AM")
		Type = "AM";
}
void Units::setJoinTime(int JT) {
	if (JT > 0 && JT<50)
		JoinTime = JT;
	else
		cout << "error";
}

void Units::setHealth(int health) {
	if (health > 0 && health <= 100)
		Health = health;
	else if (health <= 0) {
		Health = 0;
		cout << "The Unit is Dead";
	}
	else
		Health = 100;
}
void Units::setPower(int power) {
	if (power > 0)
		Power = power;
	else if (power == 0)
		cout << "The Unit is Dead";
	else
		cout << "Power error";
}
void Units::setAttackCapacity(int AC) {
	if (AC > 0)
		AttackCapacity = AC;
	else
		cout << "error ";
}

int Units::getID() {
	return ID;
}
string Units::getType() {
	return Type;
}
int Units::getJoinTime() {
	return JoinTime;
}
int Units::getHealth() {
	return Health;
}
int Units::getPower() {
	return Power;
}
int Units::getAttackCapacity() {
	return AttackCapacity;
}
Units::~Units() {

}

inline std::ostream& operator<<(std::ostream& os, Units& es) {
	os << es.getID();
	return os;
}
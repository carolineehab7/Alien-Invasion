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
	Type = type;
}
void Units::setJoinTime(int JT) {
	JoinTime = JT;
}
void Units::setHealth(int health) {
	Health = health;
}
void Units::setPower(int power) {
	Power = power;
}
void Units::setAttackCapacity(int AC) {
	AttackCapacity = AC;
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

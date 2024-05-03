#include "EG.h"

EG::EG(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}

EG::EG()
{
}

int EG::getScore() {
	int Score = getHealth() * getPower();
	return Score;
}


void EG::attack() {

}
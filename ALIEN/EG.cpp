#include "EG.h"
#include "Units.h"
#include <iostream>
using namespace std;

EG::EG(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
double EG::getScore() {
	int score = getHealth() * getPower();
	return score;
}
//EG EG ::operator < (EG* obj1) {
//	getScore(this->Power, this->Health) < getScore(obj1->Power, obj1->Health);
//}
void EG::attack() {

}
#include<iostream>
#include"EarthArmy.h"
using namespace std;

EarthArmy::EarthArmy() {
	
;
}

bool EarthArmy::addUnit(Units* U) {

	if (U->getType() == "ES")
		ES_LIST.enqueue(dynamic_cast<ES*>(U));
	else if (U->getType() == "EG")
		EG_LIST.enqueue(dynamic_cast<EG*>(U),dynamic_cast<EG*>(U)->getScore());
	else if (U->getType() == "ET")
		ET_LIST.push(dynamic_cast<ET*>(U));
	else
		return false;
	return true;
}

ES* EarthArmy::pickES()
{
	ES* ESptr = new ES(); 
	if((ES_LIST.isEmpty()))
		ES_LIST.dequeue(ESptr);
	return ESptr;
}

EG* EarthArmy::pickEG()
{
	EG* EGptr = NULL;
	int pri = 1;
	if (!EG_LIST.isEmpty()) {
		EG_LIST.dequeue(EGptr, pri);
	}
	
	return EGptr;
}

ET* EarthArmy::pickET()
{
	ET* ETptr = NULL;
	if (!ET_LIST.isEmpty()) {
		ET_LIST.pop(ETptr);
	}
	return ETptr;
}

LinkedQueue<ES*> EarthArmy::getESList()
{
	return ES_LIST;
}

priQueue<EG*> EarthArmy::getEGList()
{
	return EG_LIST;
}

ArrayStack<ET*> EarthArmy::getETList()
{
	return ET_LIST;
}


void EarthArmy::printEA() {

		Units* U;

		cout << "============== Earth Army Alive Units ==============" << endl;

		cout << ES_LIST.length << " ES [ ";
		ES_LIST.printLQ();

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << EG_LIST.length << " EG [ ";
		EG_LIST.printPriQ();

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << ET_LIST.getTop() + 1 << " ET [ ";
		ArrayStack<ET*> Temp3;
		ET* et;
		for (int i = 0; i < ET_LIST.getTop() + 1; ++i) {

			ET_LIST.peek(et);

			cout << et->getID() << ', ';

			ET_LIST.pop(et);
			Temp3.push(et);
		}
		cout << " ]" << endl;
		for (int i = 0; i < Temp3.getTop() + 1; ++i) {
			Temp3.peek(et);
			Temp3.pop(et);
			ET_LIST.push(et);
		}
	
}

void EarthArmy::AttackAA()
{
	ES* esAttacker;
	if (ES_LIST.peek(esAttacker)) //if there is ES let it attack 
		esAttacker->attack();

	ET* etAttacker;
	if (ET_LIST.peek(etAttacker)) //if there is ET let it attack 
		etAttacker->attack();

	/*
	
	EG* egAttacker;
	int EGscore;
	if (EG_LIST.peek(egAttacker, EGscore)) // if there is ET let it attack
		egAttacker->attack();

	*/

}

EarthArmy::~EarthArmy() {

}
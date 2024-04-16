#include<iostream>
#include"Units.h"
#include"EG.h"
#include"ES.h"
#include"ET.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"priNode.h"
#include"EarthArmy.h"
#include"LinkedQueue.h"
#include"Node.h"
using namespace std;

EarthArmy::EarthArmy() {
	ES_LIST = new LinkedQueue<ES*>;
	EG_LIST = new priQueue<EG*>;
	ET_LIST = new ArrayStack<ET*>;

}

bool EarthArmy::addUnit(Units* U) {

	if (U->getType() == "ES")
		ES_LIST->enqueue(dynamic_cast<ES*>(U));
	else if (U->getType() == "EG")
		EG_LIST->enqueue(dynamic_cast<EG*>(U),dynamic_cast<EG*>(U)->getScore());
	else if (U->getType() == "ET")
		ET_LIST->push(dynamic_cast<ET*>(U));
	else
		return false;
	return true;
}

ES* EarthArmy::pickES()
{
	ES* ESptr;
	ES_LIST->dequeue(ESptr);
	return ESptr;
}

EG* EarthArmy::pickEG()
{
	EG* EGptr;
	int pri = 1;
	EG_LIST->dequeue(EGptr,pri);
	return EGptr;
}

ET* EarthArmy::pickET()
{
	ET* ETptr;
	ET_LIST->pop(ETptr);

	return ETptr;
}


void EarthArmy::printEA() {
	if (!(ES_LIST->isEmpty() || EG_LIST->isEmpty() || ET_LIST->isEmpty())) {

		Units* U;

		cout << "============== Earth Army Alive Units ==============" << endl;

		cout << ES_LIST->length << " ES [ ";
		Node<ES*>* Temp = ES_LIST->getfrontPtr();  // Temp Points to the Head

		while (Temp) {
			cout << Temp->getItem()->getID() << ", ";
			Temp = Temp->getNext();
		}

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << EG_LIST->length << " EG [ ";
		priNode<EG*>* Temp2 = EG_LIST->getHead();  // Temp Points to the Head
		int x;
		while (Temp2) {
			cout << Temp2->getItem(x)->getID() << " ";
			Temp2 = Temp2->getNext();
		}

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << ET_LIST->getTop() + 1 << " ET [ ";
		ArrayStack<ET*> Temp3;
		ET* t;
		for (int i = 0; i < ET_LIST->getTop() + 1; ++i) {

			ET_LIST->peek(t);

			cout << t->getID() << ', ';

			ET_LIST->pop(t);
			Temp3.push(t);
		}
		cout << " ]" << endl;
		for (int i = 0; i < Temp3.getTop() + 1; ++i) {
			Temp3.peek(t);
			Temp3.pop(t);
			ET_LIST->push(t);
		}
	}

	/*
	cout << ET_LIST.getTop()+1 << " ET [ ";
	
		for (int i = ET_LIST.getTop() + 1; i >= 0; --i) {
			cout << ET_LIST.getItems()->getID() << " ";
		}

	cout << " ]" << endl;
	*/

}


EarthArmy::~EarthArmy() {

}
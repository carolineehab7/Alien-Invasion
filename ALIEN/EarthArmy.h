#pragma once
#include<iostream>
#include"Units.h"
#include"EG.h"
#include"ES.h"
#include"ET.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
using namespace std;

class EarthArmy {

private:

	LinkedQueue<ES*> ES_List;
	LinkedQueue<EG*> EG_List;
	ArrayStack<ET*> ET_List;

public:

	bool addUnit(Units* U) {
		if (U->getType() == "ES")
			ES_List.enqueue(dynamic_cast<ES*>(U));
		else if (U->getType() == "EG")
			EG_List.enqueue(dynamic_cast<EG*>(U));
		else if (U->getType() == "ET")
			ET_List.push(dynamic_cast<ET*>(U));
	}
	
	void printEA() {

		cout << "============== Earth Army Alive Units ==============" << endl;
		cout << ES_List.length << " ES [";
		ES_List.print();
		cout << "]" << endl;

	  ////////////////////////////////////////////////////////////////////////

		cout << EG_List.length << " EG [";
		EG_List.print();
		cout << "]" << endl;

	  ////////////////////////////////////////////////////////////////////////

		cout << ET_List.getTop() << " ET [";
		ET_List.print();
		cout << "]" << endl;
	
	}

};



























/*
	void printEA() {
		ArrayStack<ET*> Temp;
		ET* t;

		cout << "============== Earth Army Alive Units ==============" << endl;

		cout << ES_List.getLength() << " ES [";
		for (int i = 0; i < ES_List.getLength(); ++i) {
			ES* s;
			ES_List.peek(s);

			cout << s->getID() << ',';

			ES_List.dequeue(s);
			ES_List.enqueue(s);
		}
		cout << "]" << endl;

	 ////////////////////////////////////////////////////////////////////////

		cout << EG_List.getLength() << " EG [";
		for (int i = 0; i < EG_List.getLength(); ++i) {
			EG* g;
			EG_List.peek(g);

			cout << g->getID() << ',';

			EG_List.dequeue(g);
			EG_List.enqueue(g);
		}
		cout << "]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << ET_List.getTop() << " ET [";
		for (int i = 0; i < ET_List.getTop(); ++i) {

			ET_List.peek(t);

			cout << t->getID() << ',';

			ET_List.pop(t);
			Temp.push(t);
		}
		cout << "]" << endl;
		for (int i = 0; i < Temp.getTop(); ++i) {
			Temp.peek(t);
			Temp.pop(t);
			ET_List.push(t);
		}

		////////////////////////////////////////////////////////////////////////

	}
	*/
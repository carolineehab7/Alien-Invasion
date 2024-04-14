#pragma once
#include"LinkedQueue.h"
#include"QueueADT.h"
#include"AD.h"
#include"Node.h"
using namespace std;

class Dequeue :public LinkedQueue<AD> {

public:

	bool frontenqueue(const AD&ad) {

		Node<AD>* newNodePtr = new Node<AD>(ad);  // Insert the new node

		if (isEmpty())	//special case if this is the first node to insert
			setbackPtr(newNodePtr); // The queue is empty
		else
			newNodePtr->setNext(getfrontPtr());
		    setfrontPtr(newNodePtr);

		length++;
		return true;

	}

 ////////////////////////////////////////////////////////////////////////////////

	bool backdequeue(const AD& ad) {

		if (isEmpty())
			return false;

		Node<AD>* nodeToDeletePtr = getbackPtr();
		Node<AD>* Current = getfrontPtr();

		if (Current == nodeToDeletePtr) {
			delete Current;
			setbackPtr(nullptr);
			setfrontPtr(nullptr);
		}
		
		while (Current->getNext()!=nodeToDeletePtr) {
			Current = Current->getNext();
		}
		Current->setNext(NULL);
		setbackPtr(Current);
		delete nodeToDeletePtr;
		length--;
		return true;

	}

};
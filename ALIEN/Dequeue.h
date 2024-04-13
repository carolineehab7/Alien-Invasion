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
			setbackPtr(*newNodePtr); // The queue is empty
		else
			newNodePtr->setNext(getfrontPtr());
		    setfrontPtr(*newNodePtr);
		return true;

	}
 ////////////////////////////////////////////////////////////////////////////////

	bool backdequeue(const AD& ad) {

		if (isEmpty())
			return false;

		Node<AD>* nodeToDeletePtr = getbackPtr();

		ad = getbackPtr()->getItem();
		
		// Queue is not empty; remove front
		if (nodeToDeletePtr == getbackPtr())	 // Special case: last node in the queue
			setbackPtr(NULL);

		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;

		return true;

	}


};

/*
Dequeue
Derive a non-template class from Queue then add 2 functions:
1- function to enqueue from the front
2- function to dequeue from the rear
*/

#pragma once
#include"LinkedQueue.h"
#include"QueueADT.h"
#include"AD.h"

class Dequeue :public LinkedQueue<AD> {

public:

	bool frontenqueue(const AD&ad) {
		Node<AD>* newNodePtr = new Node<AD>(ad);  // Insert the new node

		if (isEmpty())  	//special case if this is the first node to insert
			setbackPtr(*newNodePtr); // The queue is empty
		else
			getfrontPtr()->setNext(newNodePtr); // The queue was not empty

		setfrontPtr(*newNodePtr); // New node is the last node now
		return true;
	}


};

/*Dequeue
Derive a non-template class from Queue then add 2 functions:
1- function to enqueue from the front
2- function to dequeue from the rear
*/

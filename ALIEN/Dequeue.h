#pragma once
#include"LinkedQueue.h"
#include"QueueADT.h"
#include"AD.h"
#include"Node.h"
using namespace std;

class Dequeue :public LinkedQueue<AD> {
private:
	Node<AD>* backPtr;
	Node<AD>* frontPtr;

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
		Node<AD>* curr = getfrontPtr();

		if (curr == nodeToDeletePtr) {
			delete curr;
			setbackPtr(nullptr);
			setfrontPtr(nullptr);
		}
		
		while (curr!=nullptr && curr->getNext()!=nodeToDeletePtr) {
			curr = curr->getNext();
		}
		curr->setNext(NULL);
		setbackPtr(curr);
		delete nodeToDeletePtr;
		length--;
		return true;

	}

	Node<AD>* getFrontPTR() {
		return frontPtr;
	}

	Node<AD>* getBackPTR() {
		return backPtr;
	}
};
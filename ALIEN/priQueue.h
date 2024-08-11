#pragma once
#include "priNode.h"
#include <iostream>
using namespace std;


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue

template <typename T>
class priQueue
{
    priNode<T>* head;
public:
    int length;
    priQueue() : head(nullptr) {
        length = 0;
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        length++;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        length--;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return (head == nullptr || length == 0);
    }

    priNode<T>* getHead() {
        return head;
    }
 
 ////////////////////////////////////////////////////////////////////////////////

    void printPriQ() const {
        priNode<T>* Temp2 = head;
        int x;
        while (Temp2) {
            cout << Temp2->getItem(x)->getID() << ", ";
            Temp2 = Temp2->getNext();
        }
    }
        
    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

};

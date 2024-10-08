//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackADT.h"

 //Unless spesificed by the stack user, the default size is 100
template<typename T>
class ArrayStack : public StackADT<T>
{
	enum { MAX_SIZE = 100 };
private:
	T items[MAX_SIZE];		// Array of stack items
	int top;                   // Index to top of stack
	int count;
public:

	ArrayStack()
	{
		top = -1;
		count = 0;
	}  // end default constructor

	bool isEmpty() 
	{
		return top == -1 || count == 0;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (top == MAX_SIZE - 1) return false;	//Stack is FULL

		top++;
		items[top] = newEntry;
		count++;
		return true;
	}  // end push

	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		top--;
		count--;
		return true;
	}  // end pop

	bool peek(T& TopEntry) 
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		return true;
	}  // end peek

	int getTop() {

		return top;
	}
	
	int getCount() {

		return count;

	}

	/*void printARS() const {
		int x;
		ArrayStack<T*> Temp3;
		for (int i=0; i<getTop()+1; ++i){
			peek(x);
			cout<<
		}
	}

	
	T getItems() {

		return items[MAX_SIZE];
	}*/
	


}; // end ArrayStack

#endif

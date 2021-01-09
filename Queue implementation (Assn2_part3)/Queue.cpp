/* 
 * Queue.cpp
 *
 * Description: Queue data collection ADT class.
 *              Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Arsen Nurshaikhy
 * Date: 1st of October, 2019
 */
 
#include "Queue.h"
#include <iostream>
using namespace std;

// Description: Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
	this->elements = new int[INITIAL_SIZE];
} 


// Description: Inserts newElement at the back (O(1))
void Queue::enqueue(int newElement) {
	if (elementCount == capacity)
	{
		//Creating temporary array
		int *temp = new int[capacity * 2];
		//Initialize variable to track the front index
		int index = frontindex;
		for (int i = 0; i < elementCount; i++)
		{
			temp[i] = elements[index];
			index = (index + 1) % capacity;
		}//end for
		//Clean up memory
		delete [] this->elements;
		//Inserting the new element
		temp[elementCount] = newElement;
		//Set up all indexes
		this->capacity *= 2;
		this->frontindex = 0;
		this->backindex = elementCount + 1;
		this->elementCount++;
		//Copy from temporary array
		this->elements = temp;	
	}//end if
	else
	{
		//A new element is inserted at the backindex
		elementCount++;
		elements[backindex] = newElement;
		backindex = (backindex + 1) % capacity;
	}//end else
} 


// Description: Removes the frontmost element (O(1))
// Precondition: Queue not empty
void Queue::dequeue() {
	if (capacity / 2 >= INITIAL_SIZE && elementCount < capacity* 0.25) 
	{
		//Creating temporary array twice smaller
		int *temp = new int[capacity / 2];
		//Initialize variable to track the front index
		int index = frontindex;
		for (int i = 0; i < elementCount; i++)
		{
			temp[i] = elements[index];
			index = (index + 1) % capacity;
		}//end for
		//Clean up memory
		delete [] this->elements;
		//Set up all indexes and sizes
		this->capacity /= 2;
		this->frontindex = (frontindex + 1) % capacity;
		this->elementCount--;
		//Copy from temporary array
		this->elements = temp;	
	}//end if
	else
	{
		elementCount--;
		frontindex = (frontindex + 1) % capacity;
	}//end else
}


// Description: Returns a copy of the frontmost element (O(1))
// Precondition: Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} 


// Description: Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
} 




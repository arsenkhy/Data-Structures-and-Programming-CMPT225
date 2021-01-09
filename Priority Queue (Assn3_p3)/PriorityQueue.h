/* 
 * PriorityQueue.h
 *
 * Description: PriorityQueue data collection ADT class.
 *              Implementation of an template sequence with insert and remove ...
 * Class Invariant: Elements are sorted by their priority value
 *
 * Author: Arsen Nurshaikhy
 * Date: 28th of October
 */

#include <iostream>
#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
using namespace std;

template <class ElementType>
class PriorityQueue {
private:
	//Underlying data structure of PriorityQueue
	BinaryHeap<ElementType> elements;
public:
	/******* Priority Queue Public Interface - START - *******/

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Postcondition:  The Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in the Priority Queue.
   //              It returns "true" if successful, otherwise "false".
   // Time Efficiency: O(log2 n)
   bool enqueue(ElementType& newElement);

   // Description: Removes (but does not return) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   void dequeue() throw(EmptyDataCollectionException);
   
   // Description: Returns (but does not remove) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType& peek() throw(EmptyDataCollectionException);

   //Description: prints all ElementType objects 
   //Precondition: The PriorityQueue is not empty
   //Time efficiency: O(n)
   void printPriorityQueue() const;

   //Decription:Default Constructor
   //Time efficiency: O(1)
   PriorityQueue();

   // Description:  Destructor
   //Time efficiency: O(n)
   ~PriorityQueue();
 
/******* Priority Queue Public Interface - END - *******/
};

//Decription:Default Constructor
//Time efficiency: O(1)
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
	this->elements = BinaryHeap<ElementType>();
}

// Description:  Destructor
//Time efficiency: O(n)
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
	this->elements.~BinaryHeap();
}


// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Postcondition:  The Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
	return this->elements.isEmpty();
}

// Description: Inserts newElement in the Priority Queue.
//It returns "true" if successful, otherwise "false".
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement)
{
	return this->elements.insert(newElement);
}

// Description: Removes (but does not return) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue() throw(EmptyDataCollectionException)
{
	if (this->isEmpty())
		throw EmptyDataCollectionException("dequeue() called with empty PriorityQueue.");
	else
		this->elements.remove();
}

// Description: Returns (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& PriorityQueue<ElementType>::peek() throw(EmptyDataCollectionException)
{
	if (this->isEmpty())
		throw EmptyDataCollectionException("peek() called with empty PriorityQueue.");
	else
		return this->elements.retrieve();
}

//Description: prints all ElementType objects 
//Precondition: The PriorityQueue is not empty
//Time efficiency: O(n)
template <class ElementType>
void PriorityQueue<ElementType>::printPriorityQueue() const
{
	this->elements.printBinaryHeap();
}



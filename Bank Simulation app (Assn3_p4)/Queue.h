/* 
 * Queue.h
 *
 * Description: Queue data collection ADT class.
 *              Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: in FIFO or LILO order
 *
 * Author: Arsen Nurshaikhy
 * Date: 22th of October, 2019
 */

#include <iostream>
#include "EmptyDataCollectionException.h"
using namespace std;

// Description: Nodes for a singly-linked list
template <class ElementType>
class Node {
public:
	ElementType data;
	Node<ElementType> *next;
};

template <class ElementType>
class Queue {
private:
	// Description: head = ptr to the first Node (NULL if empty)
	//              tail = ptr to the last Node (NULL if empty)
	Node<ElementType> *head;
	Node<ElementType> *tail;
public:

	/******* Queue Public Interface - START - *******/
   // Class Invariant:  FIFO or LILO order

   // Description: Returns "true" is this Queue is empty, otherwise "false".
   // Postcondition:  The Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Inserts newElement at the "back" of this Queue 
   //              (not necessarily the "back" of its data structure) and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(ElementType& newElement);
   
   // Description: Removes (but does not return) the element at the "front" of this Queue 
   //              (not necessarily the "front" of its data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
   // Time Efficiency: O(1)
   void dequeue() throw(EmptyDataCollectionException); 
   
   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of its data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType& peek() throw(EmptyDataCollectionException);  

   //Description: prints all ElementType onjects 
   //Precondition: The Queue is not empty
   //Exception: Throws EmptyDataCollectionException if this Queue is empty.
   //Time efficiency: O(n)
   void printQueue() const;

   //Decription:Default Constructor
   //Time efficiency: O(1)
   Queue();

   // Description:  Destructor
   //Time efficiency: O(n)
   ~Queue(); 
 
 
/******* Queue Public Interface - END - *******/
};


//Decription:Default Constructor
//Time efficiency: O(1)
template <class ElementType>
Queue<ElementType>::Queue()
{
	//Make head and tail point to the NULL
	this->head = NULL;
	this->tail = NULL;
}

// Description:  Destructor
//Time efficiency: O(n)
template <class ElementType>
Queue<ElementType>::~Queue()
{
	//Creating a temporary node to traverse the Queue
	Node<ElementType> *current = head;
    while (current != NULL) {
        head = head->next;
        current->next = NULL; 
        delete current;
        current = head;
    }
    tail = NULL;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Postcondition:  The Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
	return head == NULL && tail == NULL;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement)
{
	//Initializing a new node
	Node<ElementType> *newNode = new Node<ElementType>; //new node
    newNode->data = newElement;
    newNode->next = NULL;
	//Checking the position that newNode should go
	bool inserted = false;
    if (tail != NULL)
	{
    	tail->next = newNode;
		inserted = true;
	}
    tail = newNode;
    if (head == NULL) 
	{
    	head = newNode;
		inserted = true;
	}
	return inserted;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue() throw(EmptyDataCollectionException)
{
	// Enforce precondition
    if (isEmpty())
      throw EmptyDataCollectionException("dequeue() called with empty queue.");
	//Deleting the element from the front
	else
	{
		Node<ElementType> *temp = head; //temporary node
		this->head = head->next;
		if (head == NULL)
			tail = NULL;
		temp = NULL;
		delete temp;	//memory clean up
	}//end else
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() throw(EmptyDataCollectionException)
{
	// Enforce precondition
    if (isEmpty())
      throw EmptyDataCollectionException("peek() called with empty queue.");
	//
	else
	{
		ElementType result = head->data;
		return result;
	}//end else
}

//Description: prints all ElementType onjects 
//Precondition: The Queue is not empty
//Exception: Throws EmptyDataCollectionException if this Queue is empty.
//Time efficiency: O(n)
template <class ElementType>
void Queue<ElementType>::printQueue() const
{
	//Checking if Queue is empty
	if (isEmpty())
		cout << ".::Sorry, empty Queue::." << endl;
	else
	{
		//Temporary ptr in order to traverse Queue
		cout << ".::Printing The Queue::." << endl;
		Node<ElementType> *temp = head;
		while(temp != NULL)
		{
			cout << temp->data << "  " << endl;
			temp = temp->next;
		}
	}
}

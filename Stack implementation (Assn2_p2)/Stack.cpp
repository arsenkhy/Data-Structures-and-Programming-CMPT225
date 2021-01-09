/* 
 * Stack.cpp
 *
 * Description: Stack data collection ADT class.
 *              Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Arsen Nurshaikhy
 * Date: 30th of September, 2019
 */

#include "Stack.h"
#include <iostream>

using namespace std;


 // Description: Constructor
 // Postcondition: Stack is empty
 Stack::Stack()
 {
	 //Setting head and tail pointing to the NULL
	 this->head = NULL;
	 this->tail = NULL;
 }

 // Description: Destructor 
 // Postcondition: All memory released
 Stack::~Stack()
 {
	 //Creating temporary node to traverse stack
	 StackNode *temp;
	 while (this->head != NULL)
	 {
		 temp = head;
		 this->head = head->next;
		 //Memory clean up
		 delete temp;
	 }
	 //Setting tail to NULL
	 this->tail = NULL;
 }

 // Description: Insert newElement to the top of the stack. 
 void Stack::push(int newElement)
 {
	 //Creating the Node
	 StackNode* newNode = new StackNode();
	 newNode->data = newElement;
	 newNode->next = NULL;
	 //Inserting Node if stack is empty
	 if (this->head == NULL)
	 {
		 this->head = newNode;
		 this->tail = newNode;
	 }//end if
	 //Inserting if stack is not empty
	 else
	 {
		 tail->next = newNode;
		 this->tail = newNode;
	 }//end else
 }

 // Description: Remove and return element at the top of the stack.
 // Precondition: Stack is not empty   
 int Stack::pop()
 {
	 //Initializing variables
	 int topElement = tail->data;
	 StackNode* temp = tail;
	 this->tail = head;
	 //Traversing to delete the Node of stack's top element
	 if (this->tail->next != NULL)
	 {
		 while(tail->next != temp)
			this-> tail = tail->next;
		 this->tail->next = NULL;
		 //Clean up memory
		 delete temp;
	 }//end if
	 else
	 {
		 this->head = NULL;
		 delete tail;
		 tail = NULL;
	 }// end else
	 
	 return topElement;
 }

 // Description: Return the topmost element of the stack.
 // Precondition: Stack is not empty   
 int Stack::peek() const
 {
	 //Return data at the tail
  	 return this->tail->data;
 }

 // Description: Is stack empty? 
 bool Stack::isEmpty() const
 {
	 bool empty = head == NULL;
	 return empty;
 }


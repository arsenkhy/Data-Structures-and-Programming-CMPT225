/* 
 * BinaryHeap.h
 *
 * Description: BinaryHeap data collection ADT class.
 *              Implementation of an template sequence with insert and remove ...
 * Class Invariant: Minimum Binary Heap, the value of child cannot be less than
 *					parent's value.
 *
 * Author: Arsen Nurshaikhy
 * Date: 22th of October
 */

#include <iostream>
#include <cmath>
#include "EmptyDataCollectionException.h"
using namespace std;

template <class ElementType>
class BinaryHeap {
private:
	static unsigned const INITIAL_SIZE = 3;	    //Default size of the BinaryHeap, expands if inserted more elements
	ElementType *heap;                          //The array of the BinaryHeap
	int elementCount;					        //Count of elements in the BinaryHeap	
	int capacity;                               //Size of the array
	int indexOfRoot;                            //Index of the Root
	int indexOfBottom;                          //Index of the last element in the BinaryHeap
											
public:
	/******* Binary Heap Public Interface - START - *******/
   // Class Invariant: Minimum Binary Heap, the value of child cannot be less than
   //				   parent's value.

   // Description: Returns "true" is this Binary Heap is empty, otherwise "false".
   // Postcondition:  The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in this Binary Heap and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(log2 n)
   bool insert(ElementType& newElement);

   // Description: Removes (but does not return) the element located at the root.
   // Precondition: This Binary Heap is not empty.
   // Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove() throw(EmptyDataCollectionException);
   
   // Description: Returns (but does not remove) the element located at the root.
   // Precondition: This Binary Heap is not empty.   
   // Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
   // Time Efficiency: O(1)
   ElementType& retrieve() throw(EmptyDataCollectionException);

   //Description: prints all ElementType onjects 
   //Precondition: The BinaryHeap is not empty
   //Time efficiency: O(n)
   void printBinaryHeap() const;

   //Decription:Default Constructor
   //Time efficiency: O(1)
   BinaryHeap();

   // Description:  Destructor
   //Time efficiency: O(n)
   ~BinaryHeap(); 

   //Description: Expanding the array that is full
   //Time efficiency: O(n)
   void expandArray(int size);

   //Description: Swaps elements to the right position in order
   //			  to maintain the min BinaryHeap
   //Time efficiency: O(log2n)
   void reHeapUp(int index);

   //Description: Swaps elements to the right position in order
   //			  to maintain the min BinaryHeap
   //Time efficiency: O(log2n)
   void reHeapDown(int index);


/******* Binary Heap Public Interface - END - *******/

};

//Decription:Default Constructor
//Time efficiency: O(1)
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
	this->heap = new ElementType[INITIAL_SIZE];  //Create new array of ElementType
	this->capacity = INITIAL_SIZE;               //Size of the array
	this->elementCount = 0;
	this->indexOfRoot = 0;
	this->indexOfBottom = 0;
}

// Description:  Destructor
//Time efficiency: O(n)
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
	delete[] this->heap;
	this->heap = NULL;                     //Delete the existing array
	this->elementCount = 0;               //Set all variables to zero
	this->capacity = INITIAL_SIZE;
	this->indexOfRoot = 0;
	this->indexOfBottom = 0;
}

// Description: Returns "true" is this Binary Heap is empty, otherwise "false".
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool BinaryHeap<ElementType>::isEmpty() const
{
	return elementCount == 0;
}

// Description: Inserts newElement in this Binary Heap and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement)
{
	if (this->elementCount == 0)
		this->heap = new ElementType[INITIAL_SIZE];
	bool inserted = false;
	//checking if array is full, expand if needed
	if (elementCount == capacity)
		expandArray(capacity * 2);
	if (elementCount < capacity)
		inserted = true;
	//Setting the indexes
	this->indexOfRoot = 0;
	this->indexOfBottom = elementCount;
	//Insert new element at the bottom
	heap[indexOfBottom] = newElement;
	//Increment the elementCount
	this->elementCount++;
	//Calling the reHeapUp in order to have min BinaryHeap
	reHeapUp(indexOfBottom);
	return inserted;
}

//Description: Swaps elements to the right position in order
//			  to maintain the min BinaryHeap
//Time efficiency: O(log2n)
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(int index)
{
	if (index > indexOfRoot)
	{
		//Finding the index of a Parent
		int indexOfParent = floor((index - 1.0) / 2);
		//Swapping the elements;
		if (!(heap[indexOfParent] <= heap[index]))
		{
			ElementType temp = heap[indexOfParent];
			heap[indexOfParent] = heap[index];
			heap[index] = temp;
			//Repeat
			reHeapUp(indexOfParent);
		}//end if
	}//end if
}

//Description: Expanding the array that is full
//Time efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::expandArray(int size)
{
	//Creating temporary array
	ElementType *temp = new ElementType[size];
	//Copy existing elements to temporary array
	for (int i = 0; i < elementCount; i++)
		temp[i] = heap[i];
	//Copy all elements
	heap = new ElementType[size];
	for (int i = 0; i < elementCount; i++)
		 heap[i] = temp[i];
	//Increment capacity
	this->capacity = size;
	//Memory clean-up
	delete []temp;
}

// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() throw(EmptyDataCollectionException)
{
	//Enforce precondition
    if (isEmpty())
      throw EmptyDataCollectionException("remove() called with empty BinaryHeap.");
	else
	{
		//Setting the indexes
		this->indexOfRoot = 0;
		this->indexOfBottom = elementCount - 1;
		//Swap the elements at the bottom and root
		ElementType temp = heap[indexOfBottom];
		heap[indexOfBottom] = heap[indexOfRoot];
		heap[indexOfRoot] = temp;
		//Decrement elementCount
		this->elementCount--;
		//Calling the reHeapDown in order to have min BinaryHeap
		reHeapDown(indexOfRoot);
	}//End else
}

//Description: Swaps elements to the right position in order
//			  to maintain the min BinaryHeap
//Time efficiency: O(log2n)
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(int index)
{
	//Finding the indexes of children
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int minIndex = -1;
	//Case 1: Computing minimum between two children
	if (leftChild < elementCount && rightChild < elementCount)
	{
		minIndex = !(heap[rightChild] <= heap[leftChild]) ? 
				   leftChild : rightChild;
	}//end if
	//Case 2: Only one child 
	else if (leftChild < elementCount && rightChild >= elementCount)
		minIndex = leftChild;
	//Swap if children exist and elements need to be swapped
	if (minIndex != -1)
	{
		if (!(heap[index] <= heap[minIndex]))
		{
			ElementType temp = heap[index];
			heap[index] = heap[minIndex];
			heap[minIndex] = temp;
			//Repeat
			reHeapDown(minIndex);
		}//end if
	}//end if
}

// Description: Returns (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.   
// Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() throw(EmptyDataCollectionException)
{
	//Enforce precondition
    if (isEmpty())
      throw EmptyDataCollectionException("retrieve() called with empty BinaryHeap.");
	else
		return heap[indexOfRoot];
}

//Description: prints all ElementType onjects 
//Precondition: The BinaryHeap is not empty
//Time efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::printBinaryHeap() const
{
	//Checking if BinaryHeap is empty
	if (isEmpty())
		cout << "\t\t\t\t\t\t.::Sorry, empty BinaryHeap::." << endl;
	else
	{
		int n = 1;
		cout << "\t\t\t\t\t\t.::Printing The BinaryHeap::." << endl;	
		for (int i = 0; i < elementCount; i++)
		{
			if (n - 1 == i)
			{
				cout << endl;
				n *= 2;
			}
			cout << heap[i] << "  " ;
		}
		cout << endl;
	}//end else
}
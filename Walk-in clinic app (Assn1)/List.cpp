/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - The List cannot go beyond its maximum capacity
 *					 - The elements in List are stored in descending order 
 *					   of thier care card ID's
 *
 * Author: Arsen Nurshaikhy
 * Date: 17th of September, 2019
 */

#include "List.h"
#include <iostream>
#include <string>

// Default constructor
// Description: The array of size MAX_ELEMENTS is created
List::List()
{
	this->patientList = new Patient[MAX_ELEMENTS];
	this->elementCount = 0;
	this->capacity = MAX_ELEMENTS;
}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const
{
	return this->elementCount;
}

// Description: The sorting algorithm of Patient data type array by the 
//				care card ID's
void bubbleSort(Patient *sortedArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (sortedArr[j].getCareCard() < sortedArr[j + 1].getCareCard())
			{
				Patient temp = sortedArr[j];
				sortedArr[j] = sortedArr[j + 1];
				sortedArr[j + 1] = temp;
			} 
		}
	}
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement)
{
	bool ableToInsert = (this->elementCount < capacity);
	//Checking the existence of the same element in the data collection.
	for (int i = 0; i < elementCount; i++)
		if (patientList[i].getCareCard() == newElement.getCareCard())
			ableToInsert = false;
	if (ableToInsert)
	{
		//Creating new array.
		Patient *temp = new Patient[capacity];
		//Copying patient elements to new array.
		for (int i = 0; i < elementCount; i++)
			temp[i] = patientList[i];
		//Inserting newPatient at the last position.
		temp[elementCount] = newElement;

		bubbleSort(temp, elementCount + 1);   //Sorting the temporary array.

		//Copying the elements from temporary array to patientList class.
		for (int i = 0; i < elementCount + 1; i++)
			patientList[i] = temp[i];

		//Clean up the memory.
		delete [] temp;

		this->elementCount += 1;  //Increasing the elementCount by 1.
	}//end of if

	return ableToInsert;
}//end insert

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved)
{
	bool ableToRemove = false;
	int index;

	//Finding the index of element that needs to be removed.
	for (int i = 0; i < elementCount; i++)
	{
		//Checking the existence of element that need to be removed
		if (patientList[i].getCareCard() == toBeRemoved.getCareCard())
		{
			ableToRemove = true;
			index = i;
			break;
		}
	}
	
	if (ableToRemove)
	{
		//Creating the temporary array.
		int pos = 0;
		Patient *temp = new Patient[capacity];

		//Copying the elements to temporary array except for one that needs to be removed.
		for (int i = 0; i < index; i++)
			temp[pos++] = patientList[i];
		for (int i = index + 1; i < elementCount; i++)
			temp[pos++] = patientList[i];

		this->elementCount -= 1;     //Decrement the size of the elementCount by one.

		//Copying the element from temporary array.
		for (int i = 0; i < elementCount; i++)
			patientList[i] = temp[i];

		//Clean up the memory.
		delete [] temp;

	}//end if

	return ableToRemove;
}//end remove

// Description: Remove all elements.
void List::removeAll()
{
	//Cleaning up the memory.
	delete [] patientList;
	//Deleting the array.
	this->elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
	Patient *toBeReturned = NULL;
	//Checking if the target object exists in the list.
	for (int i = 0; i < elementCount; i++)
		if (patientList[i].getCareCard() == target.getCareCard())
			toBeReturned = &patientList[i];

	return toBeReturned;
}//end search

// Description: Prints all elements stored in List by descending order of search key.
void List::printList()
{
	//Printing already sorted List
	for (int i = 0; i <	elementCount; i++)
		cout << patientList[i] << endl;
}


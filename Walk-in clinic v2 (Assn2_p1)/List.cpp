/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Elements are kept in descending sorted order of element's search key.
 *
 * Author: Arsen Nurshaikhy
 * Date: 30th of September, 2019
 */

#include "List.h"
#include <iostream>
#include <string>


// Default constructor
// Description: The 2D array of MAX_DIGITS is created, the array of maximum SIZE is created
List::List()
{
	//Creating a 2D(10 X 2) array of Patients
	this->patientList = new Patient*[MAX_DIGITS];
	for (int i = 0; i < MAX_DIGITS; i++)
		this->patientList[i] = new Patient[SIZE];

	//Creating the array of numbers of Patients in each row  
	this->elementCount = new int[MAX_DIGITS];
		for (int i = 0; i < MAX_DIGITS; i++)
			this->elementCount[i] = 0;
}

// Copy constructor
// Description: Copies all Patient objects to another List
List::List(const List& lst)
{
	//Initializing the sizes of each row of Patients 
	for (int i = 0; i < MAX_DIGITS; i++)
		this->elementCount[i] = lst.elementCount[i];
	if (this->getElementCount() > 0)
	{
		//Creating new empty rows
		for (int i = 0; i < MAX_DIGITS; i++)
			this->patientList[i] = new Patient[elementCount[i]];
		//Copying the elements to a List
		for (int i = 0; i < MAX_DIGITS; i++)
		{
			for (int j = 0; j < elementCount[i]; j++)
			{
				this->patientList[i][j] = lst.patientList[i][j];
			}//end of loop
		}//end of loop
	
	}//end if
}

// Destructor
// Description: destrcuts List of Patients, sets all sizes to 0
List::~List()
{
	if (this->getElementCount() > 0)
	{
		//Cleaning up the rows of Patient objects
		for (int i = 0; i < MAX_DIGITS; i++)
			delete[] this->patientList[i];
		//Memory clean up
		delete[] this->patientList;
		//Setting all sizes of rows to zero;
		for (int i = 0; i < MAX_DIGITS; i++)
			this->elementCount[i] = 0;
	}//end if
}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const
{
	//Initializing variable
	int count = 0;
	//Loop to find total amount of objects in the List in O(10) or O(1)
	for (int i = 0; i < MAX_DIGITS; i++)
		count+= elementCount[i];
	return count;
}

// Description: returns the first digit of the Patient's careCard
int List::firstDigit(const Patient& person)
{
	//Initializing variable
	string card = person.getCareCard();
	//Return integer value of first careCard's digit
	return card[0] - 48;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.     
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.  
bool List::insert(const Patient& newElement)
{
	//Finding if same element already exists in the List
	int row = this->firstDigit(newElement);
	for (int i = 0; i < elementCount[row]; i++)
		if (patientList[row][i].getCareCard() == newElement.getCareCard())
			return false;                                                     //return false if element is found the List

	//Cheking if given row is full in O(1) 
	if (elementCount[row] >= SIZE)
	{
		//The row now need to expanded
		//Initializing the variables
		int index = 0, position = elementCount[row];
		//Creating temorary array
		Patient *temp = new Patient[elementCount[row] + 1];
		//Set every object in descending order
		for (int i = 0; i < elementCount[row]; i++)
		{
			if (patientList[row][i].getCareCard() > newElement.getCareCard())
			{
				temp[index++] = newElement;
				position = i;
				break;
			}//end if
			else
				temp[index++] = patientList[row][i];
		}//end for
		if (position != elementCount[row])
		{
			for (int i = position; i < elementCount[row]; i++)
				temp[index++] = patientList[row][i];
		}//end if
		else
			temp[index] = newElement;

		//Increment the size of a row
		elementCount[row]++;
		//New patientList row
		patientList[row] = new Patient[elementCount[row] + 1];
		//Copying all objects from temporary array
		for (int i = 0; i < elementCount[row]; i++)
			patientList[row][i] = temp[i];

	}//end if

	else
	{
		int index = 0, position = elementCount[row];
		//Creating temorary array
		Patient *temp = new Patient[SIZE];
		//Set every object in descending order
		for (int i = 0; i < elementCount[row]; i++)
		{
			if (patientList[row][i].getCareCard() > newElement.getCareCard())
			{
				temp[index++] = newElement;
				position = i;
				break;
			}//end if
			else
				temp[index++] = patientList[row][i];
		}//end for
		if (position != elementCount[row])
		{
			for (int i = position; i < elementCount[row]; i++)
				temp[index++] = patientList[row][i];
		}//end if
		else
			temp[index] = newElement;

		//Increment the elementCount of a row
		elementCount[row]++;
		//New patientList row
		patientList[row] = new Patient[elementCount[row]];

		//Copying all objects from temporary array
		for (int i = 0; i < elementCount[row]; i++)
			patientList[row][i] = temp[i]; 
		
	}//end else

	return true; 
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
bool List::remove( const Patient& toBeRemoved )
{
	//Initializing variables
	bool ableToRemove = false;
	int index;
	int row = this->firstDigit(toBeRemoved);

	//Finding the index of element that needs to be removed.
	for (int i = 0; i < elementCount[row]; i++)
	{
		//Checking the existence of element that need to be removed
		if (patientList[row][i].getCareCard() == toBeRemoved.getCareCard())
		{
			ableToRemove = true;
			index = i;
			break;
		}
	}

	if (ableToRemove)
	{
		//Creating the temporary array.
		int position = 0;
		Patient *temp = new Patient[elementCount[row] - 1];

		//Copying the elements to temporary array except for one that needs to be removed.
		for (int i = 0; i < index; i++)
			temp[position++] = patientList[row][i];
		for (int i = index + 1; i < elementCount[row]; i++)
			temp[position++] = patientList[row][i];

		//Decrement the size of the elementCount by one.
		this->elementCount[row]--;

		//Copying the element from temporary array.
		for (int i = 0; i < elementCount[row]; i++)
			patientList[row][i] = temp[i];

		//Clean up the memory.
		delete [] temp;

	}//end if

	return ableToRemove;
}
	
// Description: Remove all elements.
void List::removeAll()
{
	//Cleaning up the rows of Patient objects
	for (int i = 0; i < MAX_DIGITS; i++)
		delete[] this->patientList[i];
	//Setting all sizes of rows to zero;
	for (int i = 0; i < MAX_DIGITS; i++)
		this->elementCount[i] = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target)
{
	int row = this->firstDigit(target);
	Patient *toBeReturned = NULL;
	//Checking if the target object exists in the list.
	for (int i = 0; i < elementCount[row]; i++)
		if (patientList[row][i].getCareCard() == target.getCareCard())
			toBeReturned = &patientList[row][i];

	return toBeReturned;
}
	
// Description: Prints all elements stored in List.
void List::printList()
{
	//Printing already sorted List
	for (int i = MAX_DIGITS - 1; i >= 0; i--)
	{
		for (int j = elementCount[i] - 1; j >= 0; j--)
			cout << patientList[i][j] << endl;
	}//end for
}

/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Elements are kept in descending sorted order of element's search key.
 *
 * Author: Arsen Nurshaikhy
 * Date: 30th of September, 2019
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:

	Patient **patientList;					//The 2D array that contains 10 rows of patients, where 
											//each row corresponds to the first digit of the CareCard
	int *elementCount;						//The array of sizes of patients in each row 
	static const int MAX_DIGITS = 10;		//Maximum number of rows
	static const int SIZE = 2;				//Number of maximum capacity of Patient's in each row 
			
public:

/* 
 * You can add more methods to this interface, 
 * but you cannot remove the methods below 
 * nor can you change their prototype.
 * 
 */

	// Default constructor
	// Description: The 2D array of MAX_DIGITS is created, the array of maximum SIZE is created
	List();

	// Copy constructor
	// Description: Copies all Patient objects to another List
	List(const List& lst);

	// Destructor
	// Description: destrcuts List of Patients, sets all sizes to 0
	~List();

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.     
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.  
	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);
	
	// Description: Prints all elements stored in List.
	void printList();

	// Description: returns the first digit of the Patient's careCard
	int firstDigit(const Patient& person);

}; // end List.h  

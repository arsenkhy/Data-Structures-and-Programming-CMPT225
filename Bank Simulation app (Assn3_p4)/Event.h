/*
 * Event.h
 * 
 * Description: Models arrival or departure event.
 * 
 * Class Invariant: Arrival events have type 'A'
 * 					Departure event have type 'D'
 * 
 * Author: AL
 * Modified: February 2019
 */

#pragma once
#include <iostream>

using namespace std;

class Event {

private:
	char type;
	int time;
	int length; //only used for arrival events
	
public:
	static const char ARRIVAL = 'A';
	static const char DEPARTURE = 'D';
	
	// Constructor
	Event();
	Event(char type, int time);
	Event(char type, int time, int length);
	
    // Getters
    char getType() const;
    int getTime() const;
    int getLength() const;
    
    // Setters
    void setType( char aType );
    void setTime( int aTime );
    void setLength( int aLength );
	
	// Description: Return true if this event is an arrival event, false otherwise.
	bool isArrival();

	// Overloaded Operators
	// Description: Returns "true" if "this" < "rhs", "false" otherwise.
	bool operator<=(const Event& rhs);

	// For Testing Purposes
	void printEvent();

}; // end of Event.h
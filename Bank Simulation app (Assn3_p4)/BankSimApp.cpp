/*
 * BankSimApp.cpp
 *
 *
 * Description: Event-driven Bank Simulation application.
 *				Application for maintaining the arrival and departure events
 *
 * Author: Arsen Nurshaikhy
 * Date: 31th of October, 2019
 */

#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"

using namespace std;

//Description: Processing the arrival Events
void processArrival(Event newEvent, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, bool &tellerAvailable,  int &currentTime)
{
	//Remove this event from the event queue
	try {
		eventPriorityQueue.dequeue();
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Unsuccessfull... " << anException.what() << endl;
	}

	Event customer = newEvent;

	if (bankLine.isEmpty() && tellerAvailable == 1)
	{
		//Creating new departure event
		int departureTime = customer.getLength() + currentTime;
		Event newDepartureEvent('D', departureTime);
		eventPriorityQueue.enqueue(newDepartureEvent);
		//Set teller busy
		tellerAvailable == false;
	}//end if

	else
	{
		//Set customer at the back if There is Queue
		bankLine.enqueue(customer);
	}//end else
}

//Description: Processing the departure Events
void processDeparture(Event newEvent, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, bool &tellerAvailable, int &currentTime)
{
	//Remove this event from the event queue
	try {
		eventPriorityQueue.dequeue();
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Unsuccessfull... " << anException.what() << endl;
	}

	if (!bankLine.isEmpty())
	{
		//Customer at front starts transaction
		Event customer = bankLine.peek();
		bankLine.dequeue();
		int departureTime = currentTime + customer.getLength();
		Event newDepartureEvent('D', departureTime);
		eventPriorityQueue.enqueue(newDepartureEvent);
	}//end if
	else
		tellerAvailable = true;
}


int main()
{
	//Initializing variables
	int time_input, trans_length, peopleCount = 0, currentTime, averageTime = 0;
	int previousClient, waitTime = 0;
	Queue<Event> bankLine;
	PriorityQueue<Event> eventPriorityQueue;
	bool tellerAvailable = true;

	//Starting the simulation
	cout << "Simulation Begins" << endl;

	//Taking inputs
	int i = 0;
	while(i < 10)
	{
		cin >> time_input >> trans_length;
		Event newArrivalEvent('A', time_input, trans_length);
		eventPriorityQueue.enqueue(newArrivalEvent);
		peopleCount++;
		i++;
	}

	//Creating the time of a first client in order to calculate wait time of people in Queue
	Event firstClient;
	//Peeking the front element
	try {
		firstClient = eventPriorityQueue.peek();
	}
	catch (EmptyDataCollectionException &anException)
	{
		cout << "Unsuccessfull... " << anException.what() << endl;
	}

	previousClient = firstClient.getLength() + firstClient.getTime();
	int j = 0;

	while (!eventPriorityQueue.isEmpty())
	{
		Event newEvent;
		//Peeking the front element
		try {
			newEvent = eventPriorityQueue.peek();
		}
		catch (EmptyDataCollectionException &anException)
		{
			cout << "Unsuccessfull... " << anException.what() << endl;
		}

		if (j > 0)
		{
			//Calculating the wait time of NewEvent
			waitTime = previousClient - newEvent.getTime();
			//Checking if a new client came standing in a queue
			if (waitTime <= 0)
				waitTime = 0;
			previousClient = newEvent.getTime() + newEvent.getLength() + waitTime;
		}//end if
		j++;

		//Get current Time
		currentTime = newEvent.getTime() + waitTime;

		//Processing newEvent by its type of event
		if (newEvent.getType() == 'A')
		{
			//Calculate the average time spent
			averageTime += waitTime;
			cout << "Processing an arrival event at time:     " << newEvent.getTime() << endl;
			processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
		}
		else
		{
			cout << "Processing a departure event at time:    " << newEvent.getTime() << endl;
			processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
		}

	}//end while

	cout << "Simulation Ends" << endl << endl;
	cout << "Final Statistics:" << endl << endl;
	cout << "\tTotal number of people processed: " << peopleCount << endl;
	cout << "\tAverage amount of time spent waiting: " << averageTime * 1.0 / peopleCount << endl;
	//end of Simulation




	system("pause");
	return 0;
}




/*
 * walkIn.cpp
 * 
 * Class Description: Walk-in clinic patients system application.
 *
 * Author: Arsen Nurshaikhy
 * Date: 17th of September, 2019
 */
#include "Patient.h"
#include "List.h"
#include <string>
#include <iostream>

using namespace std;


void printMenu()
{
	//Printing the menu of options to the user
	cout << "\tTo insert a new patient into the system\t\t\t press: 1" << endl;
	cout << "\tTo remove patient from the system\t\t\t press: 2" << endl;
	cout << "\tTo search for a patient in a system\t\t\t press: 3" << endl;
	cout << "\tTo modify the information about existing patient\t press: 4" << endl;
	cout << "\tTo print all patients\t\t\t\t\t press: 5" << endl;
	cout << "\tTo close the application\t\t\t\t press: 0\n" << endl;
}

void insert(List &patients)
{
	cout << "\n\t..::Inserting a new patient::..\n" << endl;
	//Declaration of variables
	string name, address, phone, email, careCard;
	//Taking input from user
	cout << "---Please enter the name of the patient> ";
	cin >> name;
	cout << "---Please enter the care card ID of the patient(must be 10 digits)> ";
	cin >> careCard;
	cout << "---Please enter the address of the patient> ";
	cin >> address;
	cout << "---Please enter the phone number of the patient> ";
	cin >> phone;
	cout << "---Please enter the email of the patient(should contain an '@' symbol)> ";
	cin >> email;

	// Create a new Patient
	Patient person(name, address, phone, email, careCard);
	//Checking if person was inserted to the List
	if (patients.insert(person))
	{
		cout <<	"\nThe patient has been successfully inserted into the system!\n";
		cout << person << endl;
	}
	else
		cout << "\nFAIL! The person has not been inserted because the maximum capacity is full\n" <<
				"or because the person already exists in the List." << endl;
}

void remove(List &patients)
{
	cout << "\n\t..::Removing a patient::..\n" << endl;
	//Declaring variables
	string careCard;
	//Taking user's input
	cout << "---Enter patients care Card ";
	cin >> careCard;

	// Create a new Patient
	Patient person(careCard);
	if (patients.remove(person))
		cout << "The Patient has been successfully removed\n" << endl;
	else
		cout << "FAIL! The patient does not exist in the list\n" << endl;
}

void search(List &patients)
{
	cout << "\n\t..::Searching a patient::..\n" << endl;
	//Declaring variables
	string careCard;
	//Taking user's input
	cout << "---Enter patients care Card ";
	cin >> careCard;

	// Create a new Patient
	Patient person(careCard);
	Patient *patientsPtr = patients.search(person);
	if (patientsPtr != NULL)
		cout << "The patient is found!\n" << *patientsPtr << endl;
	else
		cout << "FAIL! The patient does not exist in the list" << endl;
}

void newName(Patient *person)
{
	string name;
	cout << "\tWhat is your new Name> ";
	cin >> name;
	//Setting a new Name
	person->setName(name);
}

void newAddress(Patient *person)
{
	string address;
	cout << "\tWhat is your new address> ";
	cin >> address;
	//Setting a new address
	person->setAddress(address);
}

void newPhone(Patient *person)
{
	string phone;
	cout << "\tWhat is your new phone> ";
	cin >> phone;
	//Setting a new phone
	person->setPhone(phone);
}

void newEmail(Patient *person)
{
	string email;
	cout << "\tWhat is your new email> ";
	cin >> email;
	//Setting a new email
	person->setEmail(email);
}

void modify(List &patients)
{
	cout << "\n\t..::Modyfing information of a patient::..\n" << endl;
	//Declaring variables
	string careCard;
	//Taking user's input
	cout << "---Enter patients care Card ";
	cin >> careCard;

	//Create a new Patient
	Patient person(careCard);
	Patient *patientsPtr = patients.search(person);
	if (patientsPtr != NULL)
	{
		//Declaring variables
		bool notModified = true;
		char option = '-1';
		while(notModified)
		{
			//Printing the menu of what to modify
			cout << *patientsPtr << endl;
			cout << "---If you would like to modify a name,\t\t press: 1" << endl;
			cout << "---If you would like to modify an address,\t press: 2" << endl;
			cout << "---If you would like to modify a phone number,\t press: 3" << endl;
			cout << "---If you would like to modify an email,\t press: 4" << endl;
			cout << "---If you would like to quit, press: 0" << endl;

			//User's option
			cout << "Enter the command> ";
			cin >> option;
			switch(option)
			{
				case '1' : newName(patientsPtr); break;
				case '2' : newAddress(patientsPtr); break;
				case '3' : newPhone(patientsPtr); break;
				case '4' : newEmail(patientsPtr); break;
				case '0' : cout << "\nQuiting the patient's modification..." << endl; notModified = false; break;
				default: cout << "No command found for your input, Please try again!" << endl;
			}//end switch
		}//end loop
	}//end if
	else
	{
		cout << "Sorry, patient is not found in the list\n" << endl;
	}
}

int main()
{ 
	//Variables declaration
	List patients;
	bool notComplete = true;
	char option = 'z';

	cout << "\n..::Hello! Welcome to CMPT225 walk-in clinic::..\n" << endl;

	//Open the application and run it until user decides to exit
	while (notComplete)
	{
		//Printing the menu to the user
		printMenu();
	
		//Taking user's input
		cout << "Enter your choice> ";
		cin >> option; 
		switch(option)
		{
			case '1' : insert(patients); break;
			case '2' : remove(patients); break;
			case '3' : search(patients); break;
			case '4' : modify(patients); break;
			case '5' : patients.printList(); break;
			case '0' : cout << "\n..::Goodbye!::.." << endl; notComplete = false; break;
			default: cout << "No command found for your input, Please try again!" << endl;
		}

		//Printing objects that are stored in List
		cout << "\nAt the end of application there is now " << patients.getElementCount() <<
				" number of patients in the list\n " << endl;
		patients.printList();
				
	}//end loop

	system("pause");
	return 0;
}
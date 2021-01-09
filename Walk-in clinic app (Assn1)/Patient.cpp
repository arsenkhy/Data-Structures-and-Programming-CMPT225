/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Arsen Nurshaikhy 
 * Date: 17th of September, 2019
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"


// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {

// You need to complete this method.

//Care card set to "0000000000".
	this -> careCard = "0000000000";
//Other member variables set to "To be entered". 
	this -> name = "To be entered";
	this -> address = "To be entered";
	this -> phone = "To be entered";
	this -> email = "To be entered";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {

// You need to complete this method.

//Checking for the number of digits in the care card. 
	this->careCard = aCareCard;
	for (int i = 0; i < aCareCard.length(); i++)
		if (aCareCard.length() != 10 || careCard[i] < 48 || careCard[i] > 58)
			this -> careCard = "0000000000";
//Other member variables set to "To be entered". 
	this -> name = "To be entered";
	this -> address = "To be entered";
	this -> phone = "To be entered";
	this -> email = "To be entered";
}

// All other parameterized constructors -> You need to implement these methods.

// Parameterized Constructor
// Description: Create a patient with the given care card number and name.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aName, string aCareCard)
{
//Checking for the number of digits in the care card. 
	this->careCard = aCareCard;
	for (int i = 0; i < aCareCard.length(); i++)
		if (aCareCard.length() != 10 || careCard[i] < 48 || careCard[i] > 58)
			this -> careCard = "0000000000";
//Setting the name of a patient. 
	this -> name = aName;
//Other member variables set to "To be entered".
	this -> address = "To be entered";
	this -> phone = "To be entered";
	this -> email = "To be entered";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number, name and address.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aName, string anAddress, string aCareCard)
{
//Checking for the number of digits in the care card. 
	this->careCard = aCareCard;
	for (int i = 0; i < aCareCard.length(); i++)
		if (aCareCard.length() != 10 || careCard[i] < 48 || careCard[i] > 58)
			this -> careCard = "0000000000";
//Setting the name of a patient. 
	this -> name = aName;
//Setting the Patient's address.
	this -> address = anAddress;
//Other member variables set to "To be entered".
	this -> phone = "To be entered";
	this -> email = "To be entered";
}
	
// Parameterized Constructor
// Description: Create a patient with the given care card number, name, address, and phone.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aName, string anAddress, string aPhone, string aCareCard)
{
//Checking for the number of digits in the care card. 
	this->careCard = aCareCard;
	for (int i = 0; i < aCareCard.length(); i++)
		if (aCareCard.length() != 10 || careCard[i] < 48 || careCard[i] > 58)
			this -> careCard = "0000000000";
//Setting the name of a patient. 
	this -> name = aName;
//Setting Patient's address.
	this -> address = anAddress;
//Setting Patient's phone number
	this -> phone = aPhone;
//Other member variables set to "To be entered".
	this -> email = "To be entered";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number, name, address, phone, and email.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
// Postcondition: If anEmail does not have '@' symbol, then email is set to "Invalid email".
Patient::Patient(string aName, string anAddress, string aPhone, string anEmail, string aCareCard)
{
//Checking for the number of digits in the care card. 
	this->careCard = aCareCard;
	for (int i = 0; i < aCareCard.length(); i++)
		if (aCareCard.length() != 10 || careCard[i] < 48 || careCard[i] > 58)
			this -> careCard = "0000000000";
//Setting the name of a patient. 
	this -> name = aName;
//Setting Patient's address.
	this -> address = anAddress;
//Setting Patient's phone number
	this -> phone = aPhone;
//Setting Patient's email
	this -> setEmail(anEmail);
}

// Getters and setters -> You need to implement these methods.

// Description: Returns patient's name.
string Patient::getName() const
{
	return this -> name;
}

// Description: Returns patient's address.
string Patient::getAddress() const
{
	return this -> address;
}

// Description: Returns patient's phone.
string Patient::getPhone() const
{
	return this -> phone;
}

// Description: Returns patient's email.
string Patient::getEmail() const
{
	return this -> email;
}
	
// Description: Returns patient's care card.
string Patient::getCareCard() const
{
	return this -> careCard;
}

// Description: Sets the patient's name.
void Patient::setName(const string aName)
{
	this -> name = aName;
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress)
{
	this -> address = anAddress;
}

// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone)
{
	this -> phone = aPhone;
}

// Description: Sets the patient's email.
//If anEmail does not have '@' symbol, then email is set to "Invalid email".
void Patient::setEmail(const string anEmail)
{
	this -> email = "Invalid email";
	int length = anEmail.length();
//Checking for the presence of '@' symbol
	for (int i = 0; i < length; i++)
		if (anEmail[i] == '@')
			this -> email = anEmail;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp

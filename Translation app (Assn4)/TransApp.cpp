/*
 * TransApp.cpp
 * 
 * Description: English translator application 
 *
 * 
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */

#include <iostream>
#include <string>
#include "BST.h"
#include <fstream>

using namespace std;

//Description: The insertion function for a BST
template <class ElementType>
void insertInBST(BST<ElementType>& a, ifstream& fin)
{
	ElementType word;
	while(fin.eof() == false)
	{
		//Read words
		fin >> word;
		//Trying inserting into the BST
		try {
			a.insert(word);
		}
		catch (ElementAlreadyExistsInBSTException &anException) {
			cout << "Unsuccessful... " << anException.what() << endl;
		}
	} 
}

//Description: The printing of the specific element
template <class ElementType>
void findWord(BST<ElementType> &a, ElementType word)
{
	string translWord;
	try {
		//Print word if found
		translWord = a.retrieve(word);
		cout << "->" << translWord << endl;
	}
	catch (ElementDoesNotExistInBSTException &exception) {
		if (a.getElementCount() == 0)
			cout << "Unsuccessful... "<< exception.what() << endl;
		else
			cout << "->***Not Found!***" << endl;
	}
}

//Description: The printing in ascending order
template <class ElementType>
void printAll(BST<ElementType> &a)
{
	//Traversing BST in order
	try {
		a.traverseInOrder();
	}
	catch (ElementDoesNotExistInBSTException &exception){
		cout << "Unsuccessful... "<< exception.what() << endl;
	}
}

int main()
{
	cout << "\t\t\t\t.::Welcome to CMPT225 Translation App::." << endl;
	ifstream fin("dataFile.txt");
	//Checking if file fails to open 
	if (fin.fail())
	{
		cout << "File opening failed..." << endl;
		system("pause");
		return 0;
	}//end if

	//Initializing BST and adding words into it
	BST<string> newBST;
	insertInBST(newBST, fin);
	fin.close();

	//Reading user input
	string engWord;
	while(true)
	{
		cin >> engWord;
		if (engWord == "display") {
			printAll(newBST);
			break;
		} //end if
		else
			findWord(newBST, engWord);
	}
	
	cout << "\t\t\t\t\t.::Goodbye::." << endl;

	system("pause");
	return 0;
}

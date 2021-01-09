/*
 * BST.h
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */

// Put your code here! 

#include <iostream>
#include "BSTNode.h"
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"

using namespace std;



template <class ElementType>
class BST {
	
private:

	BSTNode<ElementType> *root;
	int elementCount; 

    // Utility methods
    bool insertR(const ElementType& element, BSTNode<ElementType>* current);
    ElementType& retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException);
	void traverseInOrderR(BSTNode<ElementType>* current) const;
         

public:
    // Constructors and destructor:
	BST();                               // Default constructor
    BST(ElementType& element);           // Parameterized constructor 
	BST(const BST<ElementType>& aBST);   // Copy constructor 
    ~BST();                              // Destructor 
	
    // BST operations:

    // Time efficiency: O(1)
	int getElementCount() const;

	// Description: Insertion wrapper
	// Time efficiency: O(log2 n)
	// Postcondition: 2 identical elements are not in the BST
	void insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException);	

	// Description: Retrieve wrapper 
	// Time efficiency: O(log2 n)
	// Precondition: BST is not empty
	ElementType& retrieve(const ElementType& targetElement) throw(ElementDoesNotExistInBSTException);

	// Description: Prints element of BST in ascending order
	// Time efficiency: O(n)
	// Precondition: BST is not empty
	void traverseInOrder() const throw(ElementDoesNotExistInBSTException);
	
};

//Default Costructor
template<class ElementType>
BST<ElementType>::BST()
{
	this->root = NULL;
	this->elementCount = 0;
}

//Parameterized constructor 
template<class ElementType>
BST<ElementType>::BST(ElementType& element)
{
	this->root = new BSTNode<ElementType>(element);
	this->elementCount = 1;
}

//Copy constructor
template<class ElementType>
BST<ElementType>::BST(const BST<ElementType>& aBST)
{
	this->root = aBST->root;
	this->elementCount = aBST.getElementCount();
}

//Destructor
template<class ElementType>
BST<ElementType>::~BST()
{
	this->root = NULL;
	this->elementCount = 0;
}

// Description: Number of elements in BST
// Time efficiency: O(1)
template<class ElementType>
int BST<ElementType>::getElementCount() const
{
	return this->elementCount;
}

//Description: Insertion wrapper
//Postcondition: 2 identical elements are not in the BST
// Time efficiency: O(log2 n)
template<class ElementType>
void BST<ElementType>::insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException)
{
	//Calling recursive method of insert
	bool inserted;
	inserted = insertR(newElement, root);
	if (inserted == 1)
		//Increment elementCount
		this->elementCount++; 
	else
		//Force postcondition
		throw ElementAlreadyExistsInBSTException("insert() called with element that already exists in BST");
}

//Description: Utillity method
template<class ElementType>
bool BST<ElementType>::insertR(const ElementType& element, BSTNode<ElementType>* current)
{
	bool inserted = 1, notInserted = 0;
	//Insert at right position 
	if (current == NULL)
	{
		//Creating  first Node if BST is empty
		if (this->getElementCount() == 0) {
			this->root = new BSTNode<ElementType>(element);	
		} 
		return inserted;
	}//end if
	else {
		BSTNode<ElementType>* newNode = new BSTNode<ElementType>(element);
		//Checking if element already exists in BST collection
		if (current->getEngWord() == newNode->getEngWord())
			return notInserted;
		//Inserting element if bigger than current Node
		else if (newNode->getEngWord() > current->getEngWord()) {
			if (current->right == NULL) {
				current->right = newNode;
				return inserted;
			}
			else
				return insertR(element, current->right);
		}//end else if
		//Inserting element if smaller than current Node
		else {
			if (current->left == NULL) {
				current->left = newNode;
				return inserted;
			}
			else
				return insertR(element, current->left);
		}//end else
	}//end else
}

// Description: Retrieve wrapper 
// Precondition: BST is not empty
// Time efficiency: O(log2 n)
template<class ElementType>
ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) throw(ElementDoesNotExistInBSTException)
{
	//force precondition 
	if (this->getElementCount() == 0)
		throw ElementDoesNotExistInBSTException("retrieve() called with empty a BST");
	else
		return retrieveR(targetElement, this->root);
}

//Description: Utillity method
template<class ElementType>
ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException)
{
	//Throw exception if element does not exist
	if (current == NULL)
		throw ElementDoesNotExistInBSTException("retrieve() called with element that does not exist in BST");
	//Search right subtree
	else if (targetElement > current->getEngWord())
		retrieveR(targetElement, current->right);
	//Search left subtree
	else if (targetElement < current->getEngWord())
		retrieveR(targetElement, current->left);
	//Return the found element
	else
		return current->element;
}

// Description: Prints element of BST in ascending order
// Time efficiency: O(n)
// Precondition: BST is not empty
template<class ElementType>
void BST<ElementType>::traverseInOrder() const throw(ElementDoesNotExistInBSTException)
{
	//force precondition 
	if (this->getElementCount() == 0)
		throw ElementDoesNotExistInBSTException("traverseInOrder() called with empty a BST");
	else
		traverseInOrderR(root);
}

//Description: Utillity method
template<class ElementType>
void BST<ElementType>::traverseInOrderR(BSTNode<ElementType>* current) const
{
	//Base case
	if (current == NULL)
		return;
	//Print left subtree
	traverseInOrderR(current->left);
	//Print the element
	cout << current->element << endl;
	//Print right subtree
	traverseInOrderR(current->right);
}
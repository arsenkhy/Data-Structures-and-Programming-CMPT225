/*
 * BSTNode.h
 * 
 * Description: The class of Node that will be inserted to a 
 *              BST data collection class
 *
 * 
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */


#include <string>

template <class ElementType>
class BSTNode {
public:
	ElementType element;                    //The string of two words
	BSTNode<ElementType> *left;             //Left child of a node
	BSTNode<ElementType> *right;            //Right child of a node

	//Constructors
	BSTNode();
	BSTNode(const ElementType& word);

	// Description: Returns english word in order to compare with requested word that needs to be find
	ElementType getEngWord() const;
};

//Default node constructor
template <class ElementType>
BSTNode<ElementType>::BSTNode()
{
	this->element = "";
	this->left = NULL;
	this->right = NULL;
}

//Parametarized constructor
template <class ElementType>
BSTNode<ElementType>::BSTNode(const ElementType& word)
{
	this->element = word;
	this->left = NULL;
	this->right = NULL;
}

// Description: Returns english word in order to compare with requested word that needs to be find
template<class ElementType>
ElementType BSTNode<ElementType>::getEngWord() const
{
	ElementType engWord = "";
	int i = 0;
	while(true)
	{
		//Base case for getting english word
		if (element[i] == ':')
			break;
		engWord += element[i];
		i++;
	}
	return engWord;
}
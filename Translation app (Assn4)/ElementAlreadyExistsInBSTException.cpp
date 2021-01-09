/*
 * ElementAlreadyExistsInBSTException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection BST class already has an element in its collection.
 *
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */


#include "ElementAlreadyExistsInBSTException.h"  

ElementAlreadyExistsInBSTException::ElementAlreadyExistsInBSTException(const string& message): 
logic_error("Element already exists in BST exception: " + message)
{
}  // end constructor

// End of implementation file.
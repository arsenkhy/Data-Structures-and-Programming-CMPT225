/*
 * ElementDoesNotExistInBSTException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection BST class does not have an element in its collection.
 *
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */

#include "ElementDoesNotExistInBSTException.h"  

ElementDoesNotExistInBSTException::ElementDoesNotExistInBSTException(const string& message): 
logic_error("Element does not exist in BST exception: " + message)
{
}  // end constructor

// End of implementation file.
/*
 * ElementDoesNotExistInBSTException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection BST class does not have an element in its collection.
 *
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */

#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class ElementDoesNotExistInBSTException : public logic_error
{
public:
   ElementDoesNotExistInBSTException(const string& message = "");
   
}; // end ElementDoesNotExistInBSTException
/*
 * ElementAlreadyExistsInBSTException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection BST class already has an element in its collection.
 *
 * Author: Arsen Nurshaikhy
 * Date: 22th of November, 2019
 */
 
#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class ElementAlreadyExistsInBSTException : public logic_error
{
public:
   ElementAlreadyExistsInBSTException(const string& message = "");
   
}; // end ElementAlreadyExistsInBSTException 

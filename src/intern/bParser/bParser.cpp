
#include "bParser.h"

/*!
\title bsVariable Construcot 
\brief Constructor for the bsVariable class
*/

bsVariable::bsVariable(std::string name, std::string value)
{
    this->name = name;
    this->value = value;
    this->type = bVariableUnknown;
}   
#pragma once
#include "Error.h"

class InputOperatorError : public Error
{
	std::string Message;
public:
	InputOperatorError() : Error("Invalid operator input attempted"){}
};


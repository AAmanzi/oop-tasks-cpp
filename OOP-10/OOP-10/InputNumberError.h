#pragma once
#include "Error.h"

class InputNumberError : public Error
{
	std::string Message;
public:
	InputNumberError() : Error("Invalid number input attempted"){}
};


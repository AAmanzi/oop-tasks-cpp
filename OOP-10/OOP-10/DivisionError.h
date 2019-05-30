#pragma once
#include "Error.h"

class DivisionError : public Error
{
	std::string Message;
public:
	DivisionError() : Error("Division by zero attempted"){}
};


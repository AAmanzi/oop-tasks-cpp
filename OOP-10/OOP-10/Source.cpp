#include <iostream>
#include <string>
#include "DivisionError.h"
#include "InputOperatorError.h"
#include "InputNumberError.h"
#include <fstream>

int InputNumber()
{
	int input;
	std::cin >> input;
	if(std::cin.fail())
	{
		throw InputNumberError();
	}

	return input;
}

char InputOperator()
{
	std::string input;
	std::cin >> input;

	if
	(
		input != "+" &&
		input != "-" &&
		input != "*" &&
		input != "/"
	)
	{
		throw InputOperatorError();
	}
	return input.front();
}

double Calculate(int left, int right, char opCode)
{
	if(right == 0 && opCode == '/')
	{
		throw DivisionError();
	}
	switch(opCode)
	{
	case('+'):
		return left + right;
	case('-'):
		return left - right;
	case('*'):
		return left * right;
	case('/'):
		return left / right;
	default:
		throw Error("Invalid operator!");
	}
}

int main()
{
	try
	{
		auto a = InputNumber();
		auto b = InputNumber();
		auto op = InputOperator();
		std::cout	<< Calculate(a, b, op)
					<< std::endl;
	}
	catch(Error& calculationError)
	{
		calculationError.LogError("errors.log");
	}
	system("pause");
}
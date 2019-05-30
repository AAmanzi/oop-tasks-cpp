#pragma once
#include <string>
#include <fstream>

class Error : public std::exception
{
	std::string Message;

public:
	Error(const std::string& message) : Message(message) {}
	std::string GetMessage() const
	{
		return Message;
	}
	void LogError(const std::string& fileName) const
	{
		std::ofstream errorLog;
		errorLog.open (fileName);
		errorLog << Message << std::endl;
		errorLog.close();
	}
};


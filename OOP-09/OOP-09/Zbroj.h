#pragma once
#include <iostream>

template<typename T>
class Zbroj
{
	T First, Second;
public:
	Zbroj() : First(T()), Second(T()){}
	Zbroj(const T& first, const T& second);

	T Sum() const;
};

template <typename T>
Zbroj<T>::Zbroj(const T& first, const T& second)
	: First(first), Second(second){}

template <typename T>
T Zbroj<T>::Sum() const
{
	return First + Second;
}

template<>
class Zbroj<char>
{
	char First, Second;
public:
	Zbroj()
		: First(char()), Second(char())
	{
		std::cout << "Pozvan specijalizirani template" << std::endl;
	}
	Zbroj(const char& first, const char& second)
		: First(first), Second(second)
	{
		std::cout << "Pozvan specijalizirani template" << std::endl;
	};
	char Sum() const;
};

inline char Zbroj<char>::Sum() const
{
	if(First >= '0' && First <= '9' ||
		Second >= '0' && Second <= '9' )
		return static_cast<int>(First) + static_cast<int>(Second) - static_cast<int>('0');
	if(First >= 'A' && First <= 'Z' ||
		Second >= 'A' && Second <= 'Z' )
		return static_cast<int>(First) + static_cast<int>(Second) - static_cast<int>('A') + 1;
	return static_cast<int>(First) + static_cast<int>(Second) - static_cast<int>('a') + 1;
}

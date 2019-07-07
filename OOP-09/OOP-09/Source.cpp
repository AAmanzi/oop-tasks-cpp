#include <iostream>
#include "Zbroj.h"

int main()
{
	Zbroj<int> numbers(5, 19);
	Zbroj<char> characters('E', 'F');

	std::cout << "Number sum: " << numbers.Sum()
		<< std::endl
		<< "Character sum: " << characters.Sum()
		<< std::endl;

	system("pause");
}

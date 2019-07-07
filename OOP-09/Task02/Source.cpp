#include <iostream>
#include "Stack.h"

int main()
{
	auto myStack = *new Stack<int> (10, 5);

	myStack.Push(11);
	myStack.Push(15);
	myStack.Pop();

	std::cout << myStack.GetTop() << std::endl << myStack.GetSize() << std::endl;
	system("pause");
}

#pragma once
#include <list>

template <typename T>
class Stack
{
	const int DefaultSize_ = 10;
	const int MaxSize_ = 1000;

	int Size;
	T Top;
	T* StackPtr;

public:
	Stack(T valueToFill);
	Stack(T valueToFill, int size);
	Stack(std::list<T> valuesToFill);
	~Stack();

	void Push(T value);
	T Pop();

	bool IsFull() const;
	bool IsEmpty() const;

	T GetTop() const;
	int GetSize() const;
};

template <typename T>
Stack<T>::Stack(T valueToFill)
{
	StackPtr = new T[MaxSize_];
	Size = 0;
	for(auto i = 0; i < DefaultSize_; ++i)
	{
		Push(valueToFill);
	}
}

template <typename T>
Stack<T>::Stack(T valueToFill, int size)
{
	StackPtr = new T[MaxSize_];
	Size = 0;
	for(auto i = 0; i < size; ++i)
	{
		Push(valueToFill);
	}
}

template <typename T>
Stack<T>::Stack(std::list<T> valuesToFill)
{
	StackPtr = new T[MaxSize_];
	Size = 0;
	for(auto i = valuesToFill.begin(); i != valuesToFill.end(); ++i)
	{
		Push(*i);
	}
}

template <typename T>
Stack<T>::~Stack()
{
	StackPtr = StackPtr - Size;
	delete[] StackPtr;
	StackPtr = nullptr;
}

template <typename T>
void Stack<T>::Push(T value)
{
	*StackPtr = value;
	Top = *StackPtr;
	++Size;
	if(IsFull()) return;
	++StackPtr;
}

template <typename T>
T Stack<T>::Pop()
{
	T deleted = *StackPtr;
	--StackPtr;
	--Size;
	Top = *(StackPtr - 1);
	return deleted;
}

template <typename T>
bool Stack<T>::IsFull() const
{
	return Size == MaxSize_;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
	return Size == 0;
}

template <typename T>
T Stack<T>::GetTop() const
{
	return Top;
}

template <typename T>
int Stack<T>::GetSize() const
{
	return Size;
}

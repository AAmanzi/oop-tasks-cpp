#include "Array.h"
#include <iostream>
#include <experimental/filesystem>

using namespace std;

Array::Array(int length)
{
	Length = length;
	Values = new int[Length];
}

Array::Array()
{
	Length = 0;
	Values = nullptr;
}

Array::Array(const Array& toCopy)
{
	Length = toCopy.Length;
	Values = new int[Length];
	copy(toCopy);
}

void Array::copy(const Array& toCopy)
{
	int *value = Values + Length;
	int *copy = toCopy.Values + toCopy.Length;
	while (value > Values)
		*--value = *--copy;
}

istream& operator >>(istream& in, Array& arr)
{
	for (auto i = 0; i < arr.Length; ++i)
	{
		in >> arr.Values[i];
	}
	return in;
}

ostream& operator << (ostream& out, const Array& arr)
{
	for (auto i = 0; i < arr.Length; ++i)
	{
		out << arr.Values[i] << " ";
	}
	return out << endl;
}

Array& operator+(const Array& arrL, const Array& arrR)
{
	Array tmp = arrL;
	tmp.Length += arrR.Length;

	for (auto i = 0; i < arrR.Length; ++i)
	{
		tmp.Values[arrL.Length + i] = arrR.Values[i];
	}

	return tmp;
}

Array operator-(const Array& arrL, const Array& arrR)
{
	Array tmp(arrL.Length);
	tmp.Length = 0;

	for(auto i = 0; i < arrL.Length; ++i)
	{
		auto isFound = false;

		for(auto j = 0; j < arrR.Length; ++j)
		{
			if(arrL.Values[i] == arrR.Values[j])
			{
				isFound = true;
				j = arrR.Length;
			}
		}
		if(!isFound)
		{
			tmp.Values[tmp.Length] = arrL.Values[i];
			tmp.Length++;
		}
	}

	return *new Array(5);
}

Array Array::operator= (const Array& toCopy) {
	Length = toCopy.Length;
	Values = new int[Length];

	copy(toCopy);

	return *this;
}

Array::~Array()
{
	cout << "pjero";
	delete [] Values;
	Values = nullptr;
}

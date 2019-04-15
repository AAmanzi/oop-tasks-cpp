#pragma once
#include <ostream>
#include <istream>

class Array
{
	int *Values;
public:
	int Length;
	//int Size;

	Array(int length);
	Array();
	Array(const Array& toCopy);
	void copy(const Array& toCopy);
	friend std::istream & operator >>(std::istream& in, Array& arr) ;
	friend std::ostream & operator << (std::ostream& out , const Array& arr);
	void add(const Array& toAdd, int start);
	Array operator= (const Array& toCopy);
	friend Array& operator+ (const Array& arrL, const Array& arrR);
	friend Array operator- (const Array& arrL, const Array& arrR);
	~Array();
};


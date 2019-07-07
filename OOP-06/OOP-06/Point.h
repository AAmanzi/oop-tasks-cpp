#pragma once
#include <iostream>

using namespace std;
class Point
{
	int X, Y, Z;
public:
	Point();
	Point(int x, int y, int z);
	Point(int minInterval, int maxInterval);
	Point(const Point& copy);
	int GetX() const;
	int GetY() const;
	int GetZ() const;
	Point& operator=(const Point& toCopy);

	friend istream & operator>>(istream& input, Point& toInput);
	friend ostream & operator<<(ostream& output, const Point& toOutput);

};
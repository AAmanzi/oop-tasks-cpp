#include "Point.h"
#include <iostream>

using namespace std;

Point::Point() :
	X(0),
	Y(0),
	Z(0){};

Point::Point(int x, int y, int z) :
	X(x),
	Y(y),
	Z(z){};

Point::Point(int minInterval, int maxInterval)
{
	auto f = static_cast<double>(rand()) / RAND_MAX;
	X = minInterval + f * (maxInterval - minInterval);
	f = static_cast<double>(rand()) / RAND_MAX;
	Y = minInterval + f * (maxInterval - minInterval);
	f = static_cast<double>(rand()) / RAND_MAX;
	Z = minInterval + f * (maxInterval - minInterval);
}

Point::Point(const Point &copy) :
	X(copy.X),
	Y(copy.Y),
	Z(copy.Z){};

int Point::GetX() const
{
	return X;
}

int Point::GetY() const
{
	return Y;
}

int Point::GetZ() const
{
	return Z;
}

Point& Point::operator=(const Point& toCopy)
{
	X = toCopy.X;
	Y = toCopy.Y;
	Z = toCopy.Z;
	return *this;
}

istream& operator>>(istream& input, Point& toInput)
{
	input >> toInput.X >> toInput.Y >> toInput.Z;
	return input;
}

ostream& operator<<(ostream& output, const Point& toOutput)
{
	output << "(" << toOutput.X << ", " << toOutput.Y << ", " << toOutput.Z << ")" << endl;
	return output;
}
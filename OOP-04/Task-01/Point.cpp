#include "Point.h"
#include <iostream>
#include <iomanip>

using namespace std;

Point::Point() :
	X(0),
	Y(0),
	Z(0){};

Point::Point(double x, double y, double z) :
	X(x),
	Y(y),
	Z(z){};

Point::Point(double minInterval, double maxInterval)
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

double Point::GetX() const
{
	return X;
}

double Point::GetY() const
{
	return Y;
}

double Point::GetZ() const
{
	return Z;
}

double Point::GetDistance(double x, double y) const
{
	return sqrt(pow(X - x, 2) + pow(Y - y, 2));
}

double Point::GetDistance(double x, double y, double z) const
{
	return sqrt(pow(X - x, 2) + pow(Y - y, 2) + pow(Z - z, 2));
}
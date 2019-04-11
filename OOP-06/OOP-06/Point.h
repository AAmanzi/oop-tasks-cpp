#pragma once
#include <iostream>
class Point
{
	double X, Y, Z;
public:
	Point();
	Point(double x, double y, double z);
	Point(double minInterval, double maxInterval);
	Point(const Point& copy);
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	double GetDistance(double x, double y) const;
	double GetDistance(double x, double y, double z) const;
	Point& operator=(const Point& toCopy);
};
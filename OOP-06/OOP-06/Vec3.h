#pragma once
#include "Point.h"

class Vec3
{
	Point Start;
	Point End;
public:
	Vec3();
	Vec3(const Point& start);
	Vec3(const Point& start, const Point& end);
	Vec3& operator=(const Vec3& toCopy);
	Vec3& operator+=(const Vec3& toCopy);
	Vec3& operator-=(const Vec3& toCopy);
	Vec3& operator*=(const double& scalar);
	Vec3& operator/=(const double& scalar);

	friend Vec3 operator+(const Vec3& vecL, const Vec3& vecR);
	friend Vec3 operator-(const Vec3& vecL, const Vec3& vecR);
	friend Vec3 operator*(const Vec3& vecL, const double& scalar);
	friend Vec3 operator/(const Vec3& vecL, const double& scalar);

	friend Vec3 operator*(const Vec3& vecL, const Vec3& vecR); //TODO
};


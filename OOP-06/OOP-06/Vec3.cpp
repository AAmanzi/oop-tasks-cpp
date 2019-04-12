#include "Vec3.h"
#include "Point.h"

Vec3::Vec3()
{
	Start = *new Point();
	End = *new Point();
}

Vec3::Vec3(const Point& end)
{
	Start = *new Point();
	End = end;
}

Vec3::Vec3(const Point& start, const Point& end)
{
	Start = start;
	End = end;
}

Vec3& Vec3::operator=(const Vec3& toCopy)
{
	Start = toCopy.Start;
	End = toCopy.End;
	return *this;
}

Vec3& Vec3::operator+=(const Vec3& toCopy)
{
	const auto differenceX = End.GetX() - toCopy.Start.GetX();
	const auto differenceY = End.GetY() - toCopy.Start.GetY();
	const auto differenceZ = End.GetZ() - toCopy.Start.GetZ();
	const auto endPoint = *new Point(
		differenceX + toCopy.End.GetX(),
		differenceY + toCopy.End.GetY(),
		differenceZ + toCopy.End.GetZ()
	);

	End = endPoint;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& toCopy)
{
	const auto endPoint = *new Point(
		toCopy.Start.GetX() - toCopy.End.GetX(),
		toCopy.Start.GetY() - toCopy.End.GetY(),
		toCopy.Start.GetZ() - toCopy.End.GetZ()
	);
	const auto tmpVector = *new Vec3(toCopy.Start, endPoint);
	End = (*this + tmpVector).End;

	return *this;
}

Vec3& Vec3::operator*=(const double& scalar)
{
	Point endPoint = *new Point(
		End.GetX() * scalar,
		End.GetY() * scalar,
		End.GetZ() * scalar
	);

	End = endPoint;
	return *this;
}

Vec3& Vec3::operator/=(const double& scalar)
{
	Point endPoint = *new Point(
		End.GetX() / scalar,
		End.GetY() / scalar,
		End.GetZ() / scalar
	);

	End = endPoint;
	return *this;
}

Vec3 operator+(const Vec3& vecL, const Vec3& vecR)
{
	const auto differenceX = vecL.End.GetX() - vecR.Start.GetX();
	const auto differenceY = vecL.End.GetY() - vecR.Start.GetY();
	const auto differenceZ = vecL.End.GetZ() - vecR.Start.GetZ();
	const auto endPoint = *new Point(
		differenceX + vecR.End.GetX(),
		differenceY + vecR.End.GetY(),
		differenceZ + vecR.End.GetZ()
	);

	return *new Vec3(vecL.Start, endPoint);
}

Vec3 operator-(const Vec3& vecL, const Vec3& vecR)
{
	const auto endPoint = *new Point(
		vecR.Start.GetX() - vecR.End.GetX(),
		vecR.Start.GetY() - vecR.End.GetY(),
		vecR.Start.GetZ() - vecR.End.GetZ()
	);
	const auto tmpVector = *new Vec3(vecR.Start, endPoint);

	return vecL + tmpVector;
}

Vec3 operator*(const Vec3& vecL, const double& scalar)
{
	Point endPoint = *new Point(
		vecL.End.GetX() * scalar,
		vecL.End.GetY() * scalar,
		vecL.End.GetZ() * scalar
	);

	return *new Vec3(vecL.Start, endPoint);
}

Vec3 operator/(const Vec3& vecL, const double& scalar)
{
	Point endPoint = *new Point(
		vecL.End.GetX() / scalar,
		vecL.End.GetY() / scalar,
		vecL.End.GetZ() / scalar
	);

	return *new Vec3(vecL.Start, endPoint);
}

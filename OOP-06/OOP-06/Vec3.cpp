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

Vec3 operator+(const Vec3& vecL, const Vec3& vecR)
{
	const auto differenceX = vecL.End.GetX() - vecR.Start.GetX();
	const auto differenceY = vecL.End.GetY() - vecR.Start.GetY();
	const auto differenceZ = vecL.End.GetZ() - vecR.Start.GetZ();
	const auto endPoint = *new Point(
		differenceX + vecR.End.GetX(),
		differenceY + vecR.End.GetY(),
		differenceZ + vecR.End.GetZ());

	return *new Vec3(vecL.Start, endPoint);
}

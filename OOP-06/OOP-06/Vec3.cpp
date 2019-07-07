#include "Vec3.h"
#include "Point.h"
#include <iostream>

int OOP::Vec3::Counter = 0;

OOP::Vec3::Vec3()
{
	End = *new Point();
	++Counter;
}

OOP::Vec3::Vec3(const Point& end)
{
	End = end;
	++Counter;
}

OOP::Vec3::Vec3(const Point& start, const Point& end)
{
	End = *new Point(
		end.GetX() - start.GetX(),
		end.GetY() - start.GetY(),
		end.GetZ() - start.GetZ()
	);
	++Counter;
}

OOP::Vec3::~Vec3()
{
	--Counter;
}

OOP::Vec3& OOP::Vec3::operator=(const Vec3& toCopy)
{
	End = toCopy.End;
	++Counter;
	return *this;
}

OOP::Vec3& OOP::Vec3::operator+=(const Vec3& toCopy)
{
	const auto endPoint = *new Point(
		End.GetX() + toCopy.End.GetX(),
		End.GetY() + toCopy.End.GetY(),
		End.GetZ() + toCopy.End.GetZ()
	);

	End = endPoint;
	return *this;
}

OOP::Vec3& OOP::Vec3::operator-=(const Vec3& toCopy)
{
	const auto endPoint = *new Point(
		0 - toCopy.End.GetX(),
		0 - toCopy.End.GetY(),
		0 - toCopy.End.GetZ()
	);
	const auto tmpVector = *new Vec3(endPoint);
	End = (*this + tmpVector).End;

	return *this;
}

OOP::Vec3& OOP::Vec3::operator*=(const int& scalar)
{
	Point endPoint = *new Point(
		End.GetX() * scalar,
		End.GetY() * scalar,
		End.GetZ() * scalar
	);

	End = endPoint;
	return *this;
}

OOP::Vec3& OOP::Vec3::operator/=(const int& scalar)
{
	Point endPoint = *new Point(
		End.GetX() / scalar,
		End.GetY() / scalar,
		End.GetZ() / scalar
	);

	End = endPoint;
	return *this;
}

int OOP::Vec3::operator[](const std::string& param) const
{
	if(param == "x" || param == "X")
		return End.GetX();
	if(param == "y" || param == "Y")
		return End.GetY();
	if(param == "z" || param == "Z")
		return End.GetZ();
	return 0;
}

bool OOP::Vec3::operator==(const Vec3& vecR) const
{
	return End.GetX() == vecR.End.GetX() &&
		End.GetY() == vecR.End.GetY() &&
		End.GetZ() == vecR.End.GetZ();
}

bool OOP::Vec3::operator!=(const Vec3& vecR) const
{
	return End.GetX() != vecR.End.GetX() ||
		End.GetY() != vecR.End.GetY() ||
		End.GetZ() != vecR.End.GetZ();
}

OOP::Vec3 OOP::Vec3::Normalize() const
{
	auto min = End.GetX();
	auto mid = End.GetY();
	auto max = End.GetZ();

	if(min > mid)
	{
		min += mid;
		mid = min - mid;
		min -= mid;
	}
	if(min > max)
	{
		min += max;
		max = min - max;
		min -= max;
	}
	if(mid > max)
	{
		mid += max;
		max = mid - max;
		mid -= max;
	}

	auto maxDivisor = 1;
	for(auto i = 2; i <= min; ++i)
	{
		if(min % i == 0 && mid % i == 0 && max % i == 0)
		{
			maxDivisor = i;
		}
	}

	const auto endPoint = *new Point(End.GetX() / maxDivisor, End.GetY() / maxDivisor, End.GetZ()/ maxDivisor);

	return *new Vec3(endPoint);
}

OOP::Vec3 OOP::operator+(const Vec3& vecL, const Vec3& vecR)
{
	const auto endPoint = *new Point(
		vecL.End.GetX() + vecR.End.GetX(),
		vecL.End.GetY() + vecR.End.GetY(),
		vecL.End.GetZ() + vecR.End.GetZ()
	);

	return *new OOP::Vec3(endPoint);
}

OOP::Vec3 OOP::operator-(const Vec3& vecL, const Vec3& vecR)
{
	const auto endPoint = *new Point(
		0 - vecR.End.GetX(),
		0 - vecR.End.GetY(),
		0 - vecR.End.GetZ()
	);
	const auto tmpVector = *new Vec3(endPoint);

	return vecL + tmpVector;
}

OOP::Vec3 OOP::operator*(const Vec3& vecL, const int& scalar)
{
	Point endPoint = *new Point(
		vecL.End.GetX() * scalar,
		vecL.End.GetY() * scalar,
		vecL.End.GetZ() * scalar
	);

	return *new Vec3(endPoint);
}

OOP::Vec3 OOP::operator/(const Vec3& vecL, const int& scalar)
{
	Point endPoint = *new Point(
		vecL.End.GetX() / scalar,
		vecL.End.GetY() / scalar,
		vecL.End.GetZ() / scalar
	);

	return *new Vec3(endPoint);
}

OOP::Vec3 OOP::operator*(const Vec3& vecL, const Vec3& vecR)
{
	auto endPoint = *new Point(
		vecL.End.GetX() * vecR.End.GetX(),
		vecL.End.GetY() * vecR.End.GetY(),
		vecL.End.GetZ() * vecR.End.GetZ()
	);

	return *new Vec3(endPoint);
}

istream& OOP::operator>>(istream& input, Vec3& toInput)
{
	input >> toInput.End;
	return input;
}

ostream& OOP::operator<<(ostream& output, const Vec3& toOutput)
{
	output << toOutput.End;
	return output;
}

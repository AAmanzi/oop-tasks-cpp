#pragma once
#include "Point.h"

namespace OOP{
	class Vec3
	{
		Point End;
	public:
		static int Counter;
		Vec3();
		Vec3(const Point& start);
		Vec3(const Point& start, const Point& end);
		~Vec3();

		Vec3& operator=(const Vec3& toCopy);
		Vec3& operator+=(const Vec3& toCopy);
		Vec3& operator-=(const Vec3& toCopy);
		Vec3& operator*=(const int& scalar);
		Vec3& operator/=(const int& scalar);
		int operator[](const std::string& param) const;

		bool operator==(const Vec3 & vecR) const;
		bool operator!=(const Vec3 & vecR) const;

		friend Vec3 operator+(const Vec3& vecL, const Vec3& vecR);
		friend Vec3 operator-(const Vec3& vecL, const Vec3& vecR);
		friend Vec3 operator*(const Vec3& vecL, const int& scalar);
		friend Vec3 operator/(const Vec3& vecL, const int& scalar);

		friend Vec3 operator*(const Vec3& vecL, const Vec3& vecR);

		friend istream & operator>>(istream& input, Vec3& toInput);
		friend ostream & operator<<(ostream& output, const Vec3& toOutput);

		Vec3 Normalize() const;
	};
}

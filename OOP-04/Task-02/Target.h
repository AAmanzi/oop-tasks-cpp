#pragma once
#include "../Task-01/Point.h"

class Target
{
	Point BottomLeftCorner;
	double Width = 0, Height = 0;
	bool IsHit = false;
public:
	Target(const Point& bottomLeftCorner, int width, int height);
	void Hit();
	bool IsOnYAxis(int yAxis) const;
};


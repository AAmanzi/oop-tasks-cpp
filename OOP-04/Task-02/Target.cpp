#include "Target.h"

Target::Target(const Point &bottomLeftCorner, int width, int height) :
	BottomLeftCorner(bottomLeftCorner),
	Width(width),
	Height(height){};

void Target::Hit()
{
	IsHit = true;
}

bool Target::IsOnYAxis(const int yAxis) const
{
	const auto maxHeight = BottomLeftCorner.GetY() + Height;

	return yAxis <= maxHeight && yAxis >= BottomLeftCorner.GetY();
}
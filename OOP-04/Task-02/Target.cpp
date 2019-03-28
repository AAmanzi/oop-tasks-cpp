#include "Target.h"

Target::Target(const Point &bottomLeftCorner, int width, int height) :
	BottomLeftCorner(bottomLeftCorner),
	Width(width),
	Height(height){};

void Target::Hit()
{
	IsHit = true;
}
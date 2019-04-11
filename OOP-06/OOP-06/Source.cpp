#include "Point.h"
#include "Vec3.h"

using namespace std;

int main()
{
	auto endPoint = *new Point(5, 0, 0);
	auto testVector = *new Vec3(endPoint);

	auto copyVector = testVector;

	auto addVector = testVector + copyVector;

	system("pause");
}
#include "Point.h"
#include "Vec3.h"

using namespace std;

int main()
{
	auto endPoint_1 = *new Point(5, 0, 0);
 	auto testVector = *new Vec3(endPoint_1);

	auto endPoint_2 = *new Point(10, 0, 0);
	auto testVector_2 = *new Vec3(endPoint_2);

	auto addVector = testVector + testVector_2;
	auto subtractVector = testVector - testVector_2;

	system("pause");
}
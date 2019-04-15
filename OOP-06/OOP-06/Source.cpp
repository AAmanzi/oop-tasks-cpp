#include "Point.h"
#include "Vec3.h"

using namespace std;
using namespace OOP;

int main()
{
	auto endPoint = *new Point(5, 10, 15);
 	auto testVector_1 = *new Vec3(endPoint);

	auto testVector_2 = testVector_1;

	auto addVector = testVector_1 + testVector_2;
	cout << addVector;
	auto subtractVector = testVector_1 - testVector_2;
	cout << subtractVector << Vec3::Counter << endl ;
	auto multiplyVector = testVector_1 * 2;

	testVector_1 += testVector_2;
	testVector_1 -= testVector_2;

	cout << testVector_2;
	cout << testVector_2.Normalize() << Vec3::Counter << endl;

	system("pause");
}
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> NewVector(bool isRandomlyGenerated, int intervalMin = 0, int intervalMax = 100, int size = 5)
{
	vector<int> newVector(size);

	if(isRandomlyGenerated)
	{
		for(auto i = newVector.begin(); i != newVector.end(); ++i)
		{
			*i = rand() % (intervalMax - intervalMin) + intervalMin;
		}

		return newVector;
	}

	cout << "Input " << size << "vector elements" << endl;

	for(auto i = newVector.begin(); i != newVector.end(); ++i)
	{
		cin >> *i;
	}

	return newVector;
}

void PrintVector(vector<int> toPrint)
{
	for (auto i = toPrint.begin(); i != toPrint.end(); ++i)
	{
		cout << *i << endl;
	}
}

int main()
{
	srand(time(NULL));

	vector<int> vector1 = NewVector(true, 0, 20, 10);
	vector<int> vector2 = NewVector(true, 0, 20, 10); 

	vector<int> newVector;

	sort(vector2.begin(), vector2.end());

	for (auto i = vector1.begin(); i != vector1.end(); ++i)
	{
		if(!binary_search(vector2.begin(), vector2.end(), *i))
			newVector.push_back(*i);
	}

	PrintVector(newVector);

	system("pause");
}
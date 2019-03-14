#include <iostream>
#include <iomanip>

using namespace std;

int* OddSort(int* first, int* last)
{
	int* tmpFirst = first;

	while(first < last)
	{
		while(*first % 2 == 0)
			++first;

		while(*last % 2 == 1)
			--last;

		if(first < last)
		{
			*first += *last;
			*last = *first - *last;
			*first -= *last;

			++first;
			--last;
		}
	}

	return tmpFirst;
}

int main()
{
	int arraySize;
	cout << "Enter the length of the array: ";
	cin >> arraySize;

	int* newArray = new int[arraySize];

	for (auto i = 0; i < arraySize; i++)
	{
		cin >> newArray[i];
	}

	OddSort(newArray, &newArray[arraySize-1]);

	for (auto i = 0; i < arraySize; i++)
	{
		cout << newArray[i] << " ";
	}

	system("pause");
}
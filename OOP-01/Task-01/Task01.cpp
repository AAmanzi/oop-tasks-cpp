#include <iostream>
#include <iomanip>

using namespace std;

int n = 10;

bool IsVisited(int* list, int listSize, int toCheck)
{
	for (int i = 0; i < listSize; i++)
	{
		if (list[i] == toCheck)
			return true;
	}

	return false;
}

int main()
{
	int *arrayToTest = static_cast<int*>(malloc(sizeof(int) * ::n));
	int *visited = static_cast<int*>(malloc(sizeof(int) * ::n));
	int visitedTail = 0;

	for (int i = 0; i < ::n; i++)
	{
		cin >> arrayToTest[i];
	}

	for (int i = 0; i < ::n; i++)
	{
		if(IsVisited(visited, visitedTail, arrayToTest[i]))
			continue;

		visited[visitedTail] = arrayToTest[i];
		visitedTail++;

		int numberOfOccurrences = 0;

		for (int j = i; j < ::n; j++)
		{
			if (arrayToTest[i] == arrayToTest[j])
			{
				numberOfOccurrences++;
			}
		}

		cout << arrayToTest[i] << "-" << numberOfOccurrences << endl;
	}



	system("pause");
}
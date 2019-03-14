#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

list<int> InsertOnes (list<int> listToEdit)
{
	listToEdit.sort();
	auto j = listToEdit.begin();

	for(auto i = 1; i < 10; ++i)
	{
		for(; *j != i; ++j)
		{
			if(i < *j)
			{
				listToEdit.insert(j, i);
				break;
			}

			if(i > *j)
			{
				auto tmp = j;
				++tmp;
				if(tmp == listToEdit.end())
					listToEdit.push_back(i);
			}
		}
	}
	return listToEdit;
}

void InsertOnes(int** toEdit, int toEditSize)
{
	for(auto i = 1; i < 10; ++i)
	{
		auto isContained = false;
		for(auto j = 0; j < toEditSize-1; ++j)
		{
			if(i == (*toEdit)[j]){
				isContained = true;
				break;
			}
		}
		if(!isContained)
		{
			(*toEdit)[toEditSize-1] = i;
			return;
		}
	}
}

int main()
{
	/*int arrayLength;

	cout << "Enter the length of the array: ";
	cin >> arrayLength;

	list<int> numberList;

	for (auto i = 0; i < arrayLength; ++i)
	{
		int input;
		cin >> input;
		numberList.push_back(input);
	}

	auto sortedList = InsertOnes(numberList);
	sortedList.clear();
	numberList.clear();*/

	int* numberList = new int[9];

	for (auto i = 0; i < 8; ++i)
	{
		int input;
		cin >> input;
		numberList[i] = input;
	}

	InsertOnes(&numberList, 9);
	delete [] numberList;
	numberList = nullptr;

	system("pause");
}
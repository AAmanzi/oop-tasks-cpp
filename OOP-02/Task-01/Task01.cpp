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

int main()
{
	int arrayLength;

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

	system("pause");
}
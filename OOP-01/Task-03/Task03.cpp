#include <iostream>
#include <iomanip>

using namespace std;

int n = 10;

int& FindItem(int* arrayToSearch)
{
	for (int i = 0; i < ::n; i++)
	{
		int hundreds = (arrayToSearch[i] / 100) % 10;
		int ones = arrayToSearch[i] % 10;

		if (hundreds + ones == 5)
		{
			return arrayToSearch[i];
		}
	}
}

int main()
{
	int newArray[] = {1234, 4542, 1241, 7532, 1357, 8531, 5421, 7532, 1039, 9860};

	FindItem(newArray) += 1;

	cout << newArray[6] << endl;

	system("pause");
}
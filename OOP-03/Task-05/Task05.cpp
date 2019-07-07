#include <iostream>
#include <iomanip>
#include<vector>
#include <string>

using namespace std;

struct Producer
{
	string Name;
	string Movie;
	string Year;

	bool Equals(Producer toCompare)
	{
		return Name == toCompare.Name && Movie == toCompare.Movie && Year == toCompare.Year;
	}

	bool IsInVector(vector<Producer> producers)
	{
		for (auto i = producers.begin(); i < producers.end(); ++i)
		{
			if (this->Equals(*i))
				return true;
		}
		return false;
	}
};

Producer MostOccurring(vector<Producer> producers)
{
	auto mostOccurring = *producers.begin();
	vector<Producer> visited;
	auto mostOccurrences = 0;

	for(auto i = producers.begin(); i < producers.end(); ++i)
	{
		auto current = *i;
		if(current.IsInVector(visited))
			continue;
		visited.push_back(current);

		auto tmpOccurrences = 1;

		for(auto j = i + 1; j < producers.end(); ++j)
		{
			if(current.Name == j->Name)
				tmpOccurrences++;
		}

		if(tmpOccurrences > mostOccurrences)
		{
			mostOccurrences = tmpOccurrences;
			mostOccurring = current;
		}
	}

	return mostOccurring;
}

int main()
{
	int producerCount;
	cout << "Enter the amount of producers you want to input: ";
	cin >> producerCount;
	cout << endl;

	vector<Producer> allProducers(producerCount);

	for(auto i = allProducers.begin(); i < allProducers.end(); ++i)
	{
		cout << "Name: ";
		if(i == allProducers.begin())
			cin.ignore();
		getline(cin, i->Name);
		cout << "Movie name: ";
		getline(cin, i->Movie);
		cout << "Year of release: ";
		getline(cin, i->Year);
		cout << endl;
	}

	auto mostOccurring = MostOccurring(allProducers);
	cout << "The most occurring producer is: " << mostOccurring.Name << endl;
	system("pause");
}
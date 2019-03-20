#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

int matchesRemaining(vector<bool> matches)
{
	for (auto i = matches.begin(); i < matches.end(); ++i)
	{
		if(!*i)
			return matches.end() - i;
	}
	return 0;
}

int main()
{
	srand(time(NULL));

	vector<bool> matchBox(21);
	auto i = matchBox.begin();
	
	auto remaining = 21;
	auto win = false;

	do
	{
		auto computerMatches = (rand() % 2 + 1)% remaining;

		if(remaining == 1)
			computerMatches = 1;
		else if(remaining == 2)
		{
			computerMatches = computerMatches % 2 + 1;
		}

		cout << computerMatches << endl;
		for(auto match = 0; match < computerMatches; ++match)
		{
			*i = true;
			++i;
		}
		
		remaining = matchesRemaining(matchBox);
		cout << "Remaining matches: " << remaining << endl;
		if(remaining == 0)
		{
			win = true;
			break;
		}

		int userMatches;

		while(true)
		{
			cin >> userMatches;
			if(userMatches <= remaining && userMatches <= 3)
			{
				break;
			}

			cout << "You cannot take as many matches!" << endl;
		};

		for(auto match = 0; match < userMatches; ++match)
		{
			*i = true;
			++i;
		}

		remaining = matchesRemaining(matchBox);
		
	}while(remaining > 0);

	if(win)
		cout << "You win!" << endl;
	else
		cout << "You lose!" << endl;

	system("pause");
}
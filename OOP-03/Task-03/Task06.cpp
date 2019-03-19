#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string ConvertToAlphanumeric(string toConvert)
{
	string converted;

	for (auto i = toConvert.begin(); i != toConvert.end(); ++i)
	{
		if(*i != *(i+1))
		{
			converted.push_back(*i);
		}
		else
		{
			auto count = 1;
			while(i != toConvert.end() - 1)
			{
				if(*i != *(i+1))
					break;
				count++;
				++i;
			}
			converted += to_string(count);
			converted.push_back(*i);
		}
	}

	return converted;
}

string ConvertToAlpha(string toConvert)
{
	string converted;
	auto count = 1;

	for (auto character : toConvert)
	{
		if(isdigit(character))
		{
			count = character - '0';
			continue;
		}

		for(auto i = 0; i < count; ++i)
		{
			converted.push_back(character);
		}
		count = 1;
	}

	return converted;
}

string Convert(string toConvert)
{
	for (auto character : toConvert)
	{
		if(isdigit(character))
		{
			return ConvertToAlpha(toConvert);
		}
	}
	return ConvertToAlphanumeric(toConvert);
}

bool IsStringValid(string toEvaluate)
{
	if(toEvaluate.size() >= 20)
	{
		cout << "Maximum string size exceeded!" << endl;
		return false;
	}
	for (auto character : toEvaluate)
	{
		if(!isdigit(character) && !isupper(character))
		{
			cout << "The string can only contain uppercase letters and numbers!" << endl;
			return false;
		}
	}
	return true;
}

int main()
{
	int stringAmount;

	cin >> stringAmount;

	vector<string> stringsToConvert(stringAmount);

	for(auto i = stringsToConvert.begin(); i != stringsToConvert.end(); ++i)
	{
		do
		{
			cin >> *i;	
		}while(!IsStringValid(*i));
	}

	for (auto toConvert : stringsToConvert)
	{
		cout << Convert(toConvert) << endl;
	}

	system("pause");
}
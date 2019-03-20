#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

string Trim(string toTrim)
{
	string trimmed;

	for(auto i = toTrim.begin(); i != toTrim.end(); ++i)
	{
		if(*i == ' ' && (*(i + 1) == ',' || *(i + 1) == '.'))
			continue;

		if(i != toTrim.begin() && *i != ' ' && *(i - 1) == ',')
			trimmed.push_back(' ');

		trimmed.push_back(*i);
	}

	return trimmed;
}

int main()
{
	auto untrimmed = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";

	cout << Trim(untrimmed) << endl;

	system("pause");
}
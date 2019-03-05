#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	bool flag;

	cout << "unesi " << boolalpha << true << " - " << false << endl;
	cin >> boolalpha >> flag;
	cout << flag << endl << endl;

	int a = 255;

	cout << uppercase << "hex " << hex << a << endl;
	cout << "dec " << dec << a << endl;
	cout << "oct " << oct << a << endl;

	cout << "\n";

	double pi = 3.141592;

	cout << "pi = " << scientific << left;
	cout << setprecision(7) << setw(15) << setfill('\n');
	cout << pi;

	system("pause");
}
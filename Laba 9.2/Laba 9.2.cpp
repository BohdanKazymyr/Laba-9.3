#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Marchrut { I = 1, II, III, IV, V };
string NomerStr[] = { "I", "II", "III", "IV", "V" };
struct Route
{
	string pochatok;
	string kinec;
	Marchrut nomer;
};
void Create(Route* p, const int N);
void Print(Route* p, const int N);
void Sort(Route* p, const int N);
int main()
{
	int N;
	int menuItem;
	cout << "Enter N: "; cin >> N;

	Route* p = new Route[N];
	Create(p, N);
	Sort(p, N);
	Print(p, N);
	cout << "Enter numder marchrut you wont to take information (0 - I, 1 - II, 2 - III, 3 - IV, 4 - V): "; cin >> menuItem;
	cout << endl << endl << endl;
	if (abs(menuItem) >= 5)
		cout << "Marchrut does not exist" << endl;

	for (int i = 0; i < N; i++)
	switch (menuItem)
	{
	case 0:
		cout << "I" << endl;
		cout << p[i].pochatok << endl;
		cout << p[i].kinec << endl;
		break;
	case 1:
		cout << "II" << endl;
		cout << p[i].pochatok << endl;
		cout << p[i].kinec << endl;
		break;
	case 2:
		cout << "III" << endl;
		cout << p[i].pochatok << endl;
		cout << p[i].kinec << endl;
		break;
	case 3:
		cout << "IV" << endl;
		cout << p[i].pochatok << endl;
		cout << p[i].kinec << endl;
		break;
	case 4:
		cout << "V" << endl;
		cout << p[i].pochatok << endl;
		cout << p[i].kinec << endl;
		return 0;

	}
}
void Create(Route* p, const int N)
{
	int nomer;
	for (int i = 0; i < N; i++)
	{
		cout << "Student # " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Pochatoc: "; getline(cin, p[i].pochatok);
		cout << " Kinec : "; cin >> p[i].kinec;
		cout << " Marchrut # (0 - I, 1 - II, 2 - III, 3 - IV, 4 - V): ";
		cin >> nomer;
		p[i].nomer = (Marchrut)nomer;
	}
}
void Print(Route * p, const int N)
{
	cout << "===================================="
		<< endl;
	cout << "| # | Pochatok | Kinec | Marchrut # |"
		<< endl;
	cout << "------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].pochatok
			<< "| " << setw(5) << right << p[i].kinec << " "
			<< "| " << setw(6) << left << NomerStr[p[i].nomer];
		cout << endl;
		cout << "===================================="
			<< endl;
		cout << endl;
	}
}
void Sort(Route * p, const int N)
{
	Marchrut tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].nomer > p[i1 + 1].nomer)

			{
				tmp = p[i1].nomer;
				p[i1].nomer = p[i1 + 1].nomer;
				p[i1 + 1].nomer = tmp;
			}
}


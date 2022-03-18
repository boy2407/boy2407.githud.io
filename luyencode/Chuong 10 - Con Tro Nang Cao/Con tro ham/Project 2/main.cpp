#include <iostream>
using namespace std;

//int Min(int a, int b)
//{
//	return a < b ? a : b;
//}
//
//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}

int MinOrMax(int a, int b, bool (*SoSanh)(int, int))
{
	return SoSanh(a, b) ? a : b;
}

bool NhoHon(int a, int b)
{
	return a < b;
}

bool LonHon(int a, int b)
{
	return a > b;
}

void main()
{
	int a = 1, b = 2;

	cout << "\nMin = " << MinOrMax(a, b, &NhoHon);
	cout << "\nMax = " << MinOrMax(a, b, LonHon);

	system("pause");
}
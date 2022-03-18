#include <iostream>
#include <fstream>
using namespace std;

struct PhanSo
{
	int TuSo, MauSo;
};
typedef struct PhanSo PHANSO;

istream& operator >> (istream &is, PHANSO &x)
{
	char chr;
	is >> x.TuSo >> chr >> x.MauSo;
	return is;
}

ostream& operator << (ostream &os, PHANSO x)
{
	os << x.TuSo << "/" << x.MauSo;
	return os;
}

bool operator > (PHANSO x, PHANSO y)
{
	return (float)x.TuSo / x.MauSo > (float)y.TuSo / y.MauSo;
}

bool operator < (PHANSO x, PHANSO y)
{
	return (float)x.TuSo / x.MauSo < (float)y.TuSo / y.MauSo;
}

bool LonHon(PHANSO x, PHANSO y)
{
	return x > y;
}

bool NhoHon(PHANSO x, PHANSO y)
{
	return x < y;
}

PHANSO find(PHANSO arr[], int n, bool (*Pointer)(PHANSO, PHANSO))
{
	PHANSO result = arr[0];

	for(int i = 1; i < n; ++i)
	{
		if(Pointer(arr[i], result))
		{
			result = arr[i];
		}
	}
	return result;
}

void main()
{
	ifstream FileIn;
	FileIn.open("input.txt", ios_base::in);



	int n;
	FileIn >> n;

	PHANSO *arr = new PHANSO[n];

	for(int i = 0; i < n; ++i)
	{
		FileIn >> arr[i];
	}

	for(int i = 0; i < n; ++i)
	{
		cout << "\nPhan so thu " << i + 1 << " la: " << arr[i];
	}

	// Cách 1.
	//cout << "\nMax = " << find(arr, n, operator >);
	//cout << "\nMin = " << find(arr, n, operator <);

	// Cách 2.
	cout << "\nMax = " << find(arr, n, LonHon);
	cout << "\nMin = " << find(arr, n, NhoHon);

	delete[] arr;

	FileIn.close();

	system("pause");
}
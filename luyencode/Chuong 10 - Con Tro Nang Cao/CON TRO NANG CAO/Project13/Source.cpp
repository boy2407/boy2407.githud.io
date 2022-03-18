#include <iostream>
using namespace std;

template <class SonDepTrai>
void NhapMang(SonDepTrai *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		cin >> a[i];
	}
}

template <class SonDepTrai>
void XuatMang(SonDepTrai *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "    ";
	}
}

int main()
{
	int n = 5;
	float *a = new float[n];

	NhapMang<float>(a, n);
	XuatMang<float>(a, n);

	delete[] a;

	system("pause");
	return 0;
}
/* Nhập mảng 1 chiều các số nguyên, xuất mảng, sắp xếp tăng/giảm */

#include <iostream>
using namespace std;

template <class T>
void NhapMang(T *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap vao a[" << i << "] = ";
		cin >> a[i];
	}
}

template <class T>
void XuatMang(T *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}

template <class T>
void Swap(T *a, T *b)
{
	T *Temp = new T;

	*Temp = *a;
	*a = *b;
	*b = *Temp;
}

template <class T>
void SapXepTang(T *a, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j]) // Sắp tăng.
			{
				Swap(&a[i], &a[j]);
			}
		}
	}
}

template <class T>
void SapXepGiam(T *a, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] < a[j]) // Sắp giảm.
			{
				Swap(&a[i], &a[j]);
			}
		}
	}
}

template <class T>
void Sort(T *a, int n, bool (*SoSanh)(T, T))
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(SoSanh(a[i], a[j]))
			{
				Swap(&a[i], &a[j]);
			}
		}
	}
}

template <class T>
bool NhoHon(T a, T b)
{
	return a < b;
}

template <class T>
bool LonHon(T a, T b)
{
	return a > b;
}

void main()
{
	int n = 5;

	int *a = new int[n];

	NhapMang(a, n);
	XuatMang(a, n);

	cout << "\nSap xep tang \n";
	//SapXepTang(a, n);
	Sort<int>(a, n, LonHon);
	XuatMang(a, n);

	cout << "\nSap xep giam \n";
	//SapXepGiam(a, n);
	Sort<int>(a, n, NhoHon);
	XuatMang(a, n);

	delete[] a;

	system("pause");
}
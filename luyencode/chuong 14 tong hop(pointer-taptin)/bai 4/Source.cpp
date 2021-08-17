#include<iostream>
using namespace std;

template<class T>
void NhapMang(T** a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout<<"\nNhap vao a["<<i<<j<<"]";
			cin >> a[i][j];

		}
	}
	/*for (int i = 0; i < dong * cot; i++)
	{
		printf("\nNhap vao a[%d][%d]", i/cot, i%cot);
		scanf_s("%d", &a[i / cot][i % cot]);
	}*/

}

template<class T>
void XuatMang(T** a, int dong, int cot)
{

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout<<"%4d", a[i][j]<<" ";

		}
		cout << "\n";
	}
	/*for (int i = 0; i < dong * cot; i++)
	{
		if (i % cot == 0)
		{
			printf("\n");
		}
		printf("%d", a[i / cot][i % cot]);
	}*/
}
template<class T>
void HoanVi(T& a, T& b)
{
	int temp = a;
	a = b;
	b = temp;
}
template<class T>
void HoanVi2Dong(T** a, int d1, int d2, int cot)
{
	for (int i = 0; i < cot; i++)
	{
		HoanVi<T>(a[d1][i], a[d2][i]);
	}
}
template<class T>
void XoaDong(T** a, int& dong, int cot, int k)
{
	for (int i = k; i < dong; i++)
	{
		HoanVi2Dong<T>(a, i, i + 1, cot);
	}
	realloc(a[dong - 1], 0);
	dong--;
}
int main()
{
	int** a, dong = 3, cot = 3;
	a = (int**)malloc(dong * sizeof(int*));

	for (int i = 0; i < dong; i++)
	{
		a[i] = (int*)malloc(cot * sizeof(int*));
	}
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);



	for (int i = 0; i < dong; i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}
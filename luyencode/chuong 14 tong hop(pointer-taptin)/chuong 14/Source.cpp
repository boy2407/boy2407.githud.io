#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void NhapMang(int** a, int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d]", i, j);
			scanf_s("%d", &a[i][j]);

		}
	}
	/*for (int i = 0; i < dong * cot; i++)
	{
		printf("\nNhap vao a[%d][%d]", i/cot, i%cot);
		scanf_s("%d", &a[i / cot][i % cot]);
	}*/

}
void XuatMang(int** a, int dong, int cot)
{

	for (int i = 0; i < dong ; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("%4d", a[i][j]);

		}
		printf("\n");
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
void HoanVi(int& a, int& b)
{
	int temp = a; 
	a = b;
	b = temp;
}
void HoanVi2Dong(int** a, int d1,int d2,int cot)
{
	for (int i = 0; i < cot; i++)
	{
		HoanVi(a[d1][i], a[d2][i]);
	}
}
void XoaDong(int** a, int &dong, int cot, int k)
{
	for (int i = k; i < dong; i++)
	{
		HoanVi2Dong(a, i, i + 1, cot);
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
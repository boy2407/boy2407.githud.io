#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf("%d", a + i);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d", *(a + i));
	}
}

void HoanVi(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

// Trả về true nếu như a > b
bool LonHon(int a, int b)
{
	return a > b;
}

// Trả về true nếu như a < b
bool NhoHon(int a, int b)
{
	return a < b;
}

// Sắp xếp tăng hoặc giảm.
void SapXep(int *a, int n, bool (*SoSanh)(int, int))
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(SoSanh(a[i], a[j]) == true)
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}

// Min or Max
int TimPhanTuThoaYeuCau(int *a, int n, bool (*SoSanh)(int, int))
{
	int x = a[0]; // Gán x là phần tử đầu tiên của mảng.

	for(int i = 1; i < n; i++)
	{
		if(SoSanh(a[i], x) == true)
		{
			x = a[i];
		}
	}
	return x;
}

int main()
{
	int n = 5;

	int *a =(int *)malloc(n * sizeof(int));

	NhapMang(a, n);
	XuatMang(a, n);
	
	printf("\nMang sap xep tang dan la\n");
	SapXep(a, n, LonHon);
	XuatMang(a, n);

	printf("\nMang sap xep giam dan la\n");
	SapXep(a, n, NhoHon);
	XuatMang(a, n);

	int Max = TimPhanTuThoaYeuCau(a, n, LonHon);
	printf("\nMax = %d", Max);

	int Min = TimPhanTuThoaYeuCau(a, n, NhoHon);
	printf("\nMin = %d", Min);

	free(a);

	getch();
	return 0;
}

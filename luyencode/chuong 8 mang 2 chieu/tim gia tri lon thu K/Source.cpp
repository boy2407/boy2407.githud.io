#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void XuatMang(int[][MAX], int, int);
void NhapMang(int[][MAX], int, int);

void NhapMang(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d]= ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void XuatMang(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
int DemSoLuongPhanBiet(float a[][MAX], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong * cot; i++)
	{
		bool Check = true; // M?c ??nh là ch?a b? trùng.
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i / cot][i % cot] == a[j / cot][j % cot])
			{
				Check = false; // B? trùng.
				break;
			}
		}

		if (Check == true)
		{
		
			dem++;
		}
	}
	return dem;
}
void HoanVi(float& a, float& b)
{
	float temp = a; a = b; b = a;
}
void SapXepGiamDan(float a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong * cot - 1; i++)
	{
		for (int j = i + 1; j < dong * cot ; j++)
		{
			if (a[i / cot][i % cot] < a[j / cot][j % cot])
			{
				HoanVi(a[i / cot][i % cot], a[j / cot][j % cot]);
			}
		}
	}
}
int TimMaxThuK(float a[][MAX], int dong, int cot, int k)
{

	int dem;
	SapXepGiamDan(a, dong, cot);
	for (int i = 0; i < dong * cot; i++)
	{
		
		bool Check = true; // M?c ??nh là ch?a b? trùng.
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i / cot][i % cot] == a[j / cot][j % cot])
			{
				Check = false; // B? trùng.
				break;
			}
		}
		if (Check == true)
		{

			dem++;
			if (dem == k)
			{
				return a[i / cot][i % cot];
			}
		}
	}
}
int main()
{

}
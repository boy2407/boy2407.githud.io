#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
void XuatMang(int a[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int KiemTraNguyenTo(int x)
{
	if (x < 2)
	{
		return 0;
	}
	else if (x > 2)
	{
		if (x % 2 == 0)
		{
			return 0;
		}
		for (int i = 3; i <= (int)sqrt((double)x); i += 2)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;

}
void SuaNguyenToThanhSo0(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNguyenTo(a[i]))
		{
			a[i]=0;
		}
	}
}
void ThemPhanTu(int a[], int &n,int vitrithem,int phantu)
{
	for (int i = n - 1; i >= vitrithem; i--)
	{
		a[i+1] = a[i];
	}
	a[vitrithem] = phantu;
	n++;
}
void XoaPhanTu(int a[], int &n, int vitrixoa)
{
	for (int i = vitrixoa+1; i < n; i++)
	{
		a[i-1] = a[i];
	}
	n--;
}
void ChenVaoSauNguyenTo(int a[], int &n, int socanchen)
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNguyenTo(a[i])==1)
		{
			ThemPhanTu(a, n, i + 1,socanchen);
			i++;//?? không xét l?i ph?n t? v?a thêm
		}
	}
}
void XoaTatCaSoNguyenTo(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNguyenTo(a[i])==1)
		{
			XoaPhanTu(a,n,i);
			i--;// c?p nh?t v? trí
		}
	}
}
int main()
{
	int a[MAX];
	int n = 10;
	//random m?ng
	srand(time(0));//?? bên ngoài
	for (int i = 0; i < n; i++)
	{
		// a+rand() % (b-a+1)
		//-20 --30

		a[i] = -20 + rand() % 51;
	}

	XuatMang(a, n);

	/*SuaNguyenToThanhSo0(a, n);
	printf("\nda so thay doi ");
	XuatMang(a, n);*/

	/*ChenVaoSauNguyenTo(a, n, 0);
	printf("\nda thay doi\n");
	XuatMang(a, n);*/

	XoaPhanTu(a, n, 0);
	printf("\nda thay doi\n");
	XuatMang(a, n);
	return 0;
}
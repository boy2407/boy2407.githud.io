#include<stdio.h>
#include<conio.h>
#define MAX 100
#include<stdlib.h>
#include<time.h>
#include<math.h>
int KiemTraBiTrung(int a[], int n, int vitrixet);
int DemSoLanXuatHien(int a[], int n, int vitrixet);
void GiaoHop(int a[], int n);
void HoanVi(int& a, int& b)
{
	b = a + b;
	a = b - a;
	b = b - a;
}
void XuatMang(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%3d ", a[i]);
	}
}

void SapXepDuongTang(int a[], int n)
{
	for (int i = 0; i < n - 1 && a[i] >= 0; i++)
	{
		for (int j = i + 1; j < n && a[j] >= 0; j++)
		{
			if (a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
void SapXep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] >= 0 && a[j] >= 0)
			{
				if (a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
			if (a[i] <= 0 && a[j] <= 0)
			{
				if (a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}
//179 
void LietKe(double a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > fabs(a[i + 1]))
		{
			printf("%4d", a[i]);
		}
	}
}
//180
void LietKe180(double a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//cach 1


		if (a[i] > a[i - 1] && a[i] < fabs(a[i + 1]))
		{
			printf("%4d", a[i]);
		}

		// cach 2
		if (a[i] >= fabs(a[i + 1]))
		{
			continue;
		}
		if (a[i] < a[i - 1])
		{
			printf("%4d", a[i]);
		}
		// cach 3
		if (a[i] <= a[i - 1] || a[i] >= fabs(a[i + 1]))
		{
			continue;
		}
		printf("%4d", a[i]);
	}
}
void LietKetDaCoTrongMang(int a[], int n)
{
	int dem = 0;
	int check = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				// da bi trung
				check = 0;
				break;
			}
		}
		if (check)
		{
			printf("%4d", a[i]);
			dem++;
		}
	}
	printf("\nCo %d Phan Tu Phan Biet La ", dem);
}
//230
int KiemTraBiTrung(int a[], int n, int vitrixet)
{
	for (int i = vitrixet - 1; i >= 0; i--)
	{
		if (a[i] == a[vitrixet])
		{
			return 1;
		}
	}
	return 0;
}
int DemSoLanXuatHien(int a[], int n, int vitrixet)
{
	int dem = 1;
	for (int i = vitrixet + 1; i < n; i++)
	{
		if (a[i] == a[vitrixet])
		{
			dem++;
		}
	}
	return dem;
}
void GiaoHop(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int kiemtratrung = KiemTraBiTrung(a, n, i);
		if (kiemtratrung)
		{
			continue;
		}
		int dem = DemSoLanXuatHien(a, n, i);
		printf("\nPhan Tu %d xuat hien %d lan", a[i], dem);
	}
}
// 1 2 3 4 5 -  2  3  4  5  1  - 3  4  5  1  2
//			lan 1             lan 2
// 0 1 2 3 4 -  1  2  3  4  0  - 2  3  4  0  1
//              0  1  2  3  4    0  1  2  3  4
//              1  1  1  1 -4    2  2  2 -3  3
// 
//0    1     2    3    4
// 
// 4    1    2    3    0 
//1=4  1=0  1=1  1=2  1=3
//
// 1     2    3   4    0
//2=3  2=4  2=0	 2=1  2=2 
// 
// 2    3    4    0    1
//=2  3=3  3=4  3=0  3=1
void DichTrai(int a[], int n,int solandich)
{
	int chiso = (solandich %n)+n;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			 a[i]=a[0];
			printf("%4d", a[i]);
			break;
		}
		a[i]= a[i - chiso];
		printf("%4d", a[i]);
	}
}
int main()
{

	int a[MAX];
	int n =4;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = -10 + rand() % -21;
	}
	
	XuatMang(a, n);
	printf("\nThay Doi \n");
	DichTrai(a, n, 2);
	return 0;
}
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<limits>
void NhapMang(int a[], int&n)
{
	printf("\nNhap so luong ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}
#define MAX  100
void xuatmang(int a[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		printf("%6d", a[i]);
	}
}
void HoanVi(int a, int b)
{
	a = a - b;
	b = a + b;
	a = b - a;
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}
void them(int a[], int &n, int vitri, int giatri)
{
	for (int i = n - 1; i >= vitri; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitri] = giatri;
	n++;
}
void xoa(int a[], int &n, int vitri)
{
	for (int i = vitri+1; i<n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}
// thêm s? 0 vào ??ng sau t?t c? các s? ch?n trong m?ng
void ThemSauTatCaSoChan(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			them(a, n, i + 1, 0);
			i++;
		}
	}
}
void XoaTatCaSoChan(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			xoa(a, n, i);
			i--;
		}
	}
}
int KiemTraToanChan(int a[],int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			return 0;
		}
	}
	return 1;
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
		for (int i = 2; i <=(int)sqrt((double)x) ; i+=2)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;

}
int KiemTraMangToanNguyenTo(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if(!KiemTraNguyenTo(a[i]))
		{
			return 0;
		}
	}
	return 1;
}

/*
	t?ng d?n la khi
	a[0]<=a[1]...
	a[0]>a[1]||...

*/
int KiemTraTangDan(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			return 0;
		}
	}
	return 1;
}
int TongCacSoNguyenTo(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraMangToanNguyenTo)
		{
			tong += a[i];
		}
	}
	return tong;
}
//Các Thao Tác Tìm Ki?m 
int TimViTriCuoiCung(int a[], int n, int x)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
int TimViTriNguyenToDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNguyenTo(a[i]))
		{
			return i;
		}
	}
	return -1;
}
/// <summary>
/// Tìm S? Nh? Nh?t
/// </summary>
/// <returns>min</returns>
int TimDuongMin(int a[], int n)
{
	int vitriduongdautien = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] >=0)
		{
			vitriduongdautien = i;
			break;
		}
	}
	if (vitriduongdautien == -1)
	{
		return vitriduongdautien;
	}
	int Min = a[vitriduongdautien];
	for (int i = vitriduongdautien+1; i < n; i++)
	{
		if (a[i] >= 0 && a[i]<Min)
		{
			Min = a[i];
		}
	}
	return Min;
}
int TimDuongMin_cach2(int a[], int n)
{
	int Min = INT_MAX;
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0 )
		{

			check = 1;
			if (a[i] < Min)
			{
				Min = a[i];
			}
			
		}
	}
	if (!check)
	{
		return -1;
	}
	return Min;
}
int TimMin(int a[], int n)
{
	int Min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < Min)
		{
			Min = a[i];
		}
	}
	return Min;
}

int main()
{
	int a[MAX];
	int n ;

	

	///*printf("\nMang them ");
	//them(a, n, 2, 12);
	//xuatmang(a, n);*/

	/*printf("\nMang xoa so chan ");
	XoaTatCaSoChan(a, n);
	xuatmang(a, n);*/

	/*printf("\nThem  so 0  ");
	ThemSauTatCaSoChan(a, n);
	xuatmang(a, n);*/


	/*int check2 = KiemTraMangToanNguyenTo(a, n);
	if (check2==1)
	{
		printf("\nMang la nguyen to");
	}
	else
	{
		printf("\nMang khong phai nguyen to");
	}*/
	//NhapMang(a,n);
	int check3 = KiemTraNguyenTo(18);
	if (check3)
	{
		printf("\nMang tang dan");
	}
	else
	{
		printf("\nMang khong tang dan");
	}

	
	return 0;
}
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

void XuatMang(int a[], int n)
{
	printf("Mang la ");
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
		for (int i = 2; i <= (int)sqrt((double)x); i += 2)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
void TachSoNguyenTo(int a[], int n, int b[], int& m)
{
	m = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraNguyenTo(a[i]))
		{
			b[m++] = a[i];
		}
	}
}
void TachThanh2MangAmDuong(int a[], int n, int b[], int& m, int c[], int& k)
{
	m = k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			b[m++] = a[i];
		}
		else
		{
			c[k++] = a[i];
		}
	}
}
void HoanVi(int& a, int& b)
{
	b = a + b;
	a = b - a;
	b = b - a;
}


void SapXepAmDuong(int a[], int n, int b[], int m, int c[], int k)
{
	//Dương Giảm dần
	InterChangSotr(b, m, 'g');
	//Âm Tăng Dần
	InterChangSotr(c, k, 'k');
	int i;
	for ( i= 0; i < m; i++)
	{
		a[i] = b[i];
	}
	for (int j=0;j<k;j++)
	{
		a[i++] = c[j];
	}
}
//sắp xếp InterChang Sort
void InterChangSotr(int a[], int n, char phanbiet)
{
	//a-b-c-d
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (phanbiet == 't')
			{
				if (a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}

			}
			else if (phanbiet == 'g')
			{
				if (a[i] < a[j])
				{
					HoanVi(a[j], a[i]);
				}
			}
		}
	}
}
int main()
{
	int a[MAX];
	int n = 10;

	int b[MAX], m;
	int c[MAX], k;
	//random mảng
	srand(time(0));//để bên ngoài
	for (int i = 0; i < n; i++)
	{
		// a+rand() % (b-a+1)
		//-20 --30

		a[i] = -20 + rand() % 51;
	}

	//XuatMang(a, n);
	///*TachSoNguyenTo(a, n, b, m);
	//printf("\nMang b ");*/
	//printf("\nTachs thanh 2 mang am duong \n");
	//TachThanh2MangAmDuong(a, n, b, m, c, k);


	//XuatMang(b, m);
	//XuatMang(c, k);
	XuatMang(a, n);

	/*InterChangSotr(a, n, 't');
	printf("\nTang ");
	XuatMang(a, n);

	InterChangSotr(a, n, 'g');
	printf("\nGiam ");
	XuatMang(a, n);*/




	return 0;
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void NhapMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap phan tu a[%d] ", i);
		scanf_s("%d", a++);
	}
}
void XuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",*(a++));		
	}
}
void HoanVi_1(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

}
/*
* int a ,b;
* HoanVi_1(a,b)
* int *a,*b;
* HoanVi_1(*a,*b);
*/
void HoanVi_2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	temp = *b;
}
/*
* int a ,b;
* HoanVi_2(&a,&b)
* int *a,*b;
* HoanVi_2(a,b);
*/
int TimMax_1(int* a,int n)
{
	int MAX = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > MAX)
		{
			MAX = a[i];
		}
	}
	return MAX;
}
int TimMin(int* a, int n)
{
	int* Min;
	Min = &a[0];//trỏ tới ô đầu tiền
	for (int i = 0; i < n; i++)
	{
		if (a[i] <*Min )
		{
			Min = &a[i];///trỏ con trỏ tới gia trị Min
			//*Min=a[i] làm thay đổi gì trị a[0]=>kết thúc a[0]=Min mất phần từ a[0];
		}
	}
	return *Min ;///trả về con trỏ 
}
void REALLOC(int *&a, int OldSize, int NewSize)
{
	// Bước 1: Tạo ra 1 mảng mới là bản sao của mảng cũ rồi đổ dữ liệu từ mảng cũ sang.
	int* tam = new int[OldSize];

	for (int i = 0; i < OldSize; i++)
	{
		tam[i] = a[i];
	}

	// Bước 2: Xóa mảng cũ đi và cấp mới lại.
	delete[] a;
	a = new int[NewSize];

	// Bước 3: Đổ dữ liệu từ mảng tạm sang mảng mới.
	int Min = OldSize < NewSize ? OldSize : NewSize;

	for (int i = 0; i < Min; i++)
	{
		a[i] = tam[i];
	}

	// Bước 4: Xóa mảng tạm đi.
	delete[] tam;
}
void ThemPhanTu(int*& a, int& n, int vitrithem, int phantuthem)
{
	realloc(a, (n + 1) * sizeof(int)); // cấp dư ra 1 ô.

	for (int i = n - 1; i >= vitrithem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitrithem] = phantuthem;
	n++;
}

// Them vao sau cac so chan so 69
void ThemNhieu(int*& a, int& n, int sophantuthem)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = 1; j <= sophantuthem; j++)
			{
				ThemPhanTu(a, n, i + 1, 70);
				i++; // để tránh bị trùng.
			}

		}
	}
}

void XoaPhanTu(int*& a, int& n, int vitrixoa)
{
	for (int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	realloc(a, (n - 1) * sizeof(int));
	n--;
}

void XoaTatCaSoChan(int*& a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			XoaPhanTu(a, n, i);
			i--; // để lùi lại xét hết được tất cả.
		}
	}
}
int main()
{
	int n;
	do
	{
		printf("\nNhap vao so luong phan tu ");
		scanf_s("%d", &n);
		if (n < 0)
		{
			printf("\nNhap lai n ");
		}
	} while (n<0);
	//khai báo con trỏ

	//int* a = (int *)malloc(n * sizeof(int));
	//int* a = (int*)calloc (n , sizeof(int));

	int* a = (int*)realloc(NULL,n * sizeof(int));
	NhapMang(a, n);
	XuatMang(a, n);

	int Max = TimMax_1(a, n);
	printf("\nMax= %d \n", Max);

	int Min = TimMin(a, n);
	printf("\nMin= %d \n", Min);
	XuatMang(a, n);

	free(a);
	return 0;

}
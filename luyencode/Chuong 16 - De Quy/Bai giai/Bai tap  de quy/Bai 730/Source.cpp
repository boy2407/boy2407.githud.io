#include <stdio.h>
#include <conio.h>
#include <time.h>

// 1 + 2 + 3 + ... + n.

// cong thuc de quy: S(n) = S(n - 1) + n

int DeQuy(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return DeQuy(n - 1) + n;
}

int DeQuyDuoi(int n, int x = 1)
{
	if(n == 1)
	{
		return x;
	}
	return DeQuyDuoi(n - 1, x + n);
}

int KhuDeQuy(int n)
{
	int Tong = 1;

	for(int i = 2; i <= n; i++)
	{
		Tong += i;
	}
	return Tong;
}

int main()
{
	int n = 50;

	printf("\nKhu de quy(%d) = %d", n, KhuDeQuy(n));
	printf("\nDe quy(%d) = %d", n, DeQuy(n));
	printf("\nDe quy duoi(%d) = %d", n, DeQuyDuoi(n));

	clock_t start1 = clock(); // Bắt đầu tính thời gian. Tính theo miliseconds.
	for(int i = 1; i <= 1000000; i++)
		KhuDeQuy(n);
	clock_t finish1 = clock(); // Kết thúc tính thời gian.

	clock_t start2 = clock(); // Bắt đầu tính thời gian. Tính theo miliseconds.
	for(int i = 1; i <= 1000000; i++)
		DeQuy(n);
	clock_t finish2 = clock(); // Kết thúc tính thời gian.

	clock_t start3 = clock(); // Bắt đầu tính thời gian. Tính theo miliseconds.
	for(int i = 1; i <= 1000000; i++)
		DeQuyDuoi(n);
	clock_t finish3 = clock(); // Kết thúc tính thời gian.
	
	double ThoiGian1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	double ThoiGian2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
	double ThoiGian3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;

	printf("\nKhu de quy chay het %lf s", ThoiGian1);
	printf("\nDe quy chay het %lf s", ThoiGian2);
	printf("\nDe quy duoi chay het %lf s", ThoiGian3);

	getch();
	return 0;
}
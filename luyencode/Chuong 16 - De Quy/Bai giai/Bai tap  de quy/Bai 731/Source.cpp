#include <stdio.h>
#include <conio.h>

/* 1^2 + 2^2 + 3^2 + ... + n^2 */

int DeQuy(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return DeQuy(n - 1) + n * n;
}

int DeQuyDuoi(int n, int x = 1)
{
	if(n == 1)
	{
		return x;
	}
	return DeQuyDuoi(n - 1, x + n * n);
}

int KhuDeQuy(int n)
{
	int Tong = 1;

	for(int i = 2; i <= n; i++)
	{
		Tong += i * i;
	}
	return Tong;
}

int main()
{
	int n = 5;

	printf("\nKhu de quy(%d) = %d", n, KhuDeQuy(n));
	printf("\nDe quy(%d) = %d", n, DeQuy(n));
	printf("\nDe quy duoi(%d) = %d", n, DeQuyDuoi(n));

	getch();
	return 0;
}
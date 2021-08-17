#include <stdio.h>
#include <conio.h>

/* 1^2 + 2^2 + 3^2 + ... + n^2 */

float DeQuy(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return DeQuy(n - 1) + 1.0 / n;
}

float DeQuyDuoi(int n, float x = 1)
{
	if(n == 1)
	{
		return x;
	}
	return DeQuyDuoi(n - 1, x + 1.0 / n);
}

float KhuDeQuy(int n)
{
	float Tong = 1;

	for(int i = 2; i <= n; i++)
	{
		Tong += 1.0 / i;
	}
	return Tong;
}

int main()
{
	int n = 3;

	printf("\nKhu de quy(%d) = %f", n, KhuDeQuy(n));
	printf("\nDe quy(%d) = %f", n, DeQuy(n));
	printf("\nDe quy duoi(%d) = %f", n, DeQuyDuoi(n));

	getch();
	return 0;
}
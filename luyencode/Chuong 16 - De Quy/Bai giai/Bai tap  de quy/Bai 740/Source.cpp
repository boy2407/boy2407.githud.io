#include <stdio.h>
#include <conio.h>

int DeQuyPhiTuyen(int n)
{
	if(n == 1)
	{
		return 1;
	}

	int Tich = 1;
	for(int i = 1; i <= n; i++)
	{
		Tich *= i;
	}

	return DeQuyPhiTuyen(n - 1) + Tich;
}

/* ========== cách 2 ============= */

// Giong bai 738
int TinhGiaiThua(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return TinhGiaiThua(n - 1) * n;
}

int DeQuy(int n)
{
	if(n == 1)
	{
		return 1;
	}
	return DeQuy(n - 1) + TinhGiaiThua(n);
}

int main()
{
	int n = 3;

	printf("\nDe quy(%d) = %d", n, DeQuy(n));
	printf("\nDe quy phi tuyen(%d) = %d", n, DeQuyPhiTuyen(n));

	getch();
	return 0;
}
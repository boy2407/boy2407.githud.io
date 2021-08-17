/* Tính S(x, n) = x^n

Ta cần biết: 
+ Với n > 0 (ví dụ là 3) thì x^3 chính là: x * x * x
+ Với n < 0 (ví dụ là -3) thì x^-3 chính là: 1 / (x^3) = 1/x * 1/x * 1/x

*/

#include <stdio.h>
#include <conio.h>

float DeQuy(float x, int n)
{
	if(n == 1)
	{
		return x;
	}

	if(n == -1)
	{
		return 1.0 / x;
	}

	if(n < 0)
	{
		return DeQuy(x, n + 1) * 1.0 / x;
	}
	else if(n == 0)
	{
		return 1;
	}
	return DeQuy(x, n - 1) * x;
}

float DeQuyDuoi(float x, int n, float y = 1)
{
	if(n == 0)
	{
		return y;
	}

	if(n < 0)
	{
		return DeQuyDuoi(x, n + 1, y * 1.0 / x) ;
	}
	else if(n == 0)
	{
		return 1;
	}
	return DeQuyDuoi(x, n - 1, y * x);
}

float KhuDeQuy(float x, int n)
{
	bool Check = true; // Mặc định > 0
	float Tich = 1;

	if(n == 0)
	{
		return Tich;
	}
	else if(n < 0)
	{
		Check = false;
		n *= -1; // Biến thành dương lại.
	}

	for(int i = 1; i <= n; i++)
	{
		Tich *= x;
	}

	if(Check == true)
		return Tich;
	return 1.0 / Tich;
}

int main()
{
	float x = 2;
	int n = -3;

	printf("\nKhu de quy(%f, %d) = %f", x, n, KhuDeQuy(x, n));
	printf("\nDe quy(%f, %d) = %f", x, n, DeQuy(x, n));
	printf("\nDe quy duoi(%f, %d) = %f", x, n, DeQuyDuoi(x, n));

	getch();
	return 0;
}
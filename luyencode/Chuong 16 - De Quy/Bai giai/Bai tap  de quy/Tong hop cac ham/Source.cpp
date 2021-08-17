/* 

			TỔNG HỢP

Bài 741:

float DeQuy(float x, int n)
{
	if(n == 1)
	{
		return x;
	}
	return DeQuy(x, n - 1) + pow(x, n);
}

float DeQuyDuoi(float x, int n, float y = 0)
{
	if(n == 0)
	{
		return y;
	}
	return DeQuyDuoi(x, n - 1, y + pow(x, n));
}

float KhuDeQuy(float x, int n)
{
	float Tong = x;

	for(int i = 2; i <= n; i++)
	{
		Tong += pow(x, i);
	}
	return Tong;
}

Bài 742 & 743: Tự làm giống bài 741

Bài 744:

float DeQuy(int n)
{
	if(n == 1)
	{
		return 1;
	}
	
	float Tong = 1;
	for(int i = 2; i <= n; i++)
	{
		Tong += i;
	}
	return DeQuy(n - 1) + 1 / Tong;
}

float DeQuyDuoi(int n, float y = 1)
{
	if(n == 1)
	{
		return y;
	}

	float Tong = 1;
	for(int i = 2; i <= n; i++)
	{
		Tong += i;
	}

	return DeQuyDuoi(n - 1, y + 1.0 / Tong);
}

float KhuDeQuy(int n)
{
	float Tong = 1;

	for(int i = 2; i <= n; i++)
	{
		float Tong2 = 1;
		for(int j = 2; j <= i; j++)
		{
			Tong2 += j;
		}
		Tong += 1.0 / Tong2;
	}
	return Tong;
}

Bài 745 & 746: Tương tự bài 744.

Bài 747:

int DeQuy(int n)
{
	if(n % 2 != 0)
	{
		return n;
	}
	return DeQuy(n / 2); // Vì nó không bao giờ chia hết cho 1 số nằm trong đoạn từ n/2 + 1 cho tới n - 1 => ta khỏi xét.
}

Bài 748:

#include <math.h>

float DeQuy(int n)
{
	if(n == 1)
	{
		return sqrt(2.0);
	}
	return sqrt(2 + DeQuy(n - 1));
}

float DeQuyDuoi(int n, float x = sqrt(2.0))
{
	if(n == 1)
	{
		return x;
	}
	return DeQuyDuoi(n - 1, sqrt(2.0 + x));
}

Bài 749 & 750:	Tương tự bài 748

Bài 751:

float DeQuy(int n)
{
	if(n == 1)
	{
		return 0.5;
	}
	return 1.0 / (1 + DeQuy(n - 1));
}

float DeQuyDuoi(int n, float x = 0.5)
{
	if(n == 1)
	{
		return x;
	}
	return DeQuyDuoi(n - 1, 1.0 / (1 + x));
}

float KhuDeQuy(int n)
{
	float Tong = 0.5;

	for(int i = 2; i <= n; i++)
	{
		Tong = 1.0 / (1 + Tong);
	}
	return Tong;
}

Bài 752:

int DeQuy(int n)
{
	if(n == 0)
	{
		return 0;
	}
	return DeQuy(n / 10) + 1;
}

int DeQuyDuoi(int n, int x = 0)
{
	if(n == 0)
	{
		return x;
	}
	return DeQuyDuoi(n / 10, x + 1);
}

int KhuDeQuy(int n)
{
	int dem = 0;

	while(n != 0)
	{
		n /= 10;
		dem++;
	}
	return dem;
}

Bài 753:

int DeQuy(int n)
{
	if(n == 0)
	{
		return 0;
	}
	return DeQuy(n / 10) + n % 10;
}

int DeQuyDuoi(int n, int x = 0)
{
	if(n == 0)
	{
		return x;
	}
	return DeQuyDuoi(n / 10, x + n % 10);
}

int KhuDeQuy(int n)
{
	int Tong = 0;

	while(n != 0)
	{
		Tong += n % 10;
		n /= 10;
	}
	return Tong;
}

Bài 754 --> 757: Tự làm

Bài 758:

int DeQuy(int n)
{
	if(n < 10)
	{
		return n;
	}
	return DeQuy(n / 10);
}

Bài 759:

int Tong = 0;
int DeQuy(int n)
{
	if(n == 0)
	{
		return 0;
	}
	Tong = Tong * 10 + n % 10;
	return DeQuy(n / 10); 
}

int DeQuyDuoi(int n, float Tong = 0)
{
	if(n == 0)
	{
		return Tong;
	}
	return DeQuyDuoi(n / 10, Tong * 10 + n % 10);
}

int KhuDeQuy(int n)
{
	int Tong = 0;

	while(n != 0)
	{
		Tong = Tong * 10 + n % 10;
		n /= 10;
	}
	return Tong;
}

Bài 760:

int DeQuyDuoi(int n, int Max = 0)
{
	if(n == 0)
	{
		return Max;
	}
	return DeQuyDuoi(n / 10, Max > n % 10 ? Max : n % 10);
}

int KhuDeQuy(int n)
{
	int Max = 0;

	while(n != 0)
	{
		int chuso = n % 10;
		n /= 10;

		if(chuso > Max)
		{
			Max = chuso;
		}
	}
	return Max;
}

Bài 761: Làm tương tự bài 760

Bài 762:

bool DeQuy(int n)
{
	if(n == 0)
	{
		return true; // Toàn lẻ.
	}
	if((n % 10) % 2 == 0)
	{
		return false; // Sai do đã phát hiện ra có 1 chữ số chẵn.
	}
	return DeQuy(n / 10); // Bỏ đi 1 chữ số.
}

Bài 763 & 764: Tương tự như bài 762.


*/
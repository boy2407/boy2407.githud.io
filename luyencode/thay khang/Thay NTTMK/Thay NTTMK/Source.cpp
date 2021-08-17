#include<stdio.h>
#include<conio.h>
#include<math.h>
void LietKeSoChan(int a[], int n)//132
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			printf("4%d", a[i]);
		}
	}
}
void LietKeCacViTriAm(double a[], int n)//133
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			printf("4%d", i);
		}
	}
}
//134
int TimMax(double a[], int n)
{
	double MAX = a[0];
	for (int i = 1; i < n; i++)
	{
		if (MAX < a[i])
		{
			MAX = a[i];
		}
	}
	return MAX;
}
//135
int TimDuongDauTien(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			return a[i];
		}
	}
	return -1;
}
//136
int TimSoChanCuoiCung(double a[], int n)
{
	for (int i = n- 1; i >= 0; i--)
	{
		if (a[i] % 2 == 0)
		{
			return a[i];
		}
	}
	return -1;
}
int TimViTriMin(double a[], int n)//137
{
	double MIN = a[0];
	int vitri = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i < MIN])
		{
			MIN = a[i];
			vitri = i;
		}
	}
	return vitri;
}
//138
int TimVitriChanDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			return i;
		}
	}
}
//139
int KiemTraHoanThien(int x)
{
	int tong = 0;
	for (int i = 1; i < x / 2; i++)
	{
		if (x % i == 0)
		{
			tong += i;
		}
	}
	return tong == x;
}
int TimViTriSoHoanThienCuoiCung(double a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (KiemTraHoanThien(a[i]))
		{
			return i;
		}
	}
}
//140
//141
//142
//143
//144
//145
//146
//147
//148
//149
//150
int TimViTriAmDau(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			return i;
		}
	}
	return -1;

}
int TimSoAmMax(int a[], int n)
{
	int vitri = TimViTriAmDau(a, n);
	int AmMax = a[vitri];
	for (int i = vitri + 1; i < n; i++)
	{
		if (a[i] < 0 && a[i] < AmMax)
		{
			AmMax = a[i];
		}
	}
	return AmMax;
}
//155
double TimGiaTriXaNhat(double a[], int n, double x)
{
	double Max = fabs(a[0] - x);
	int vitri = 0;
	for (int i = 1; i < n; i++)
	{
		if (fabs(a[i] - x) > Max)
		{
			Max = fabs(a[i] - x);
			vitri = i;
		}
	}
}
//156
double TimGiaTriGanNha(double a[], int n, double x)
{
	double Min = fabs(a[0] - x);
	int vitri = 0;
	for (int i = 1; i < n; i++)
	{
		if (fabs(a[i] - x) < Min)
		{
			Min = fabs(a[i] - x);
			vitri = i;
		}
	}
}
//157 
//158
//159
//160
//161
int TimGiatiDAuTienThoa(int a[], int n, int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x && a[i] < y)
		{
			return a[i];
		}
	}
	return x;
}
//162
//163
int TimViTriThoa(double a[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i - 1] * a[i + 1] == a[i])
		{
			return i;
		}
	}
}
//164
int TimGiaTriDauTienDauLe(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int sochuso = log10((double)a[i]) + 1;
		if ((a[i] / pow(10, sochuso - 1)) % 2 != 0)
		{
			return a[i];
		}
	}
	return 0;
}
int KiemTraXK(int x, int a)
{
	double ketqua = log10((double)x) / log10((double)a);
	return ketqua == (int)ketqua;
}
int TimGiaTriDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraXK(a[i],2))
		{
			return a[i];
		}
	}
}
//165
//167
int KiemTraToanLe(int x)
{
	while (x!=0)

	{
		int chuso = x % 10;
		x / 10;
		if (chuso % 2 == 0)
		{
			return 0;
		}
	}
	return 1;
}
int TimSoToanChuSoLeLonNhat(int a[], int n)
{
	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < Max && KiemTraToanLe(a[i])==1)
		{
			Max=a[i];
		}
	}

	return Max;
}
//167
int TimMin(int a[], int n)
{
	int Min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < Min)
		{
			Min = a[i];
		}
	}
	return Min;
}
int KiemTraChiahetChoX(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % x != 0)
		{
			return 0;
		}
	}
	return 1;
}
int TimUCNLNCuaMang(int a[], int n)
{
	int Min = TimMin(a, n);
	int check = KiemTraChiahetChoX(a, n, Min);
	if (!check)
	{
		for (int i = Min; i >=1; i++)
		{
			if (KiemTraChiahetChoX(a, n, i))
			{
				return i;
			}
		}
	}
	return Min;
}
//172
int TimMax(int a[], int n)
{
	int Max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > Max)
		{
			Max = a[i];
		}
	}
	return Max;
}
int TimBCNNcuaMang(int a[], int n)
{
	int Max = TimMax(a, n);
	int dem = 1;
	while (1)
	{
		int bcnn = dem * Max;
		dem++;
		if (KiemTraChiahetChoX(a, n, bcnn))
		{
			return bcnn;
		}
	}
}
//173
int main()
{

}
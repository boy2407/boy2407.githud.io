#include <stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int a, b;
	int tongdoixung = 0;
	int demdoixxung = 0;

	int tongchinhphuong = 0;
	int demchinhphuong = 0;

	int tongnguyento = 0;
	int demnguyento = 0;
	do {
		printf("\n nhap so nguyen a =");
		scanf_s("%d", &a);
		if (a < 0)
		{
			printf("\nGia Tri khong hop le. Xin kiem tra lai");
		}

	} while (a < 0);
	do {
		printf("\n nhap so nguyen b =");
		scanf_s("%d", &b);
		if (b <= a)
		{
			printf("\n vui long nhap lai b > a");
		}
	} while (b <= a);
	

	
	int check = 1;
	for (int i = a; i <= b; ++i)
	{
		int Temp = i;// luu bien
		int sodaonguoc = 0;
		int dem = log10((double)Temp);
		while (Temp != 0)
		{
			
			int chuso = Temp % 10;
			Temp /= 10;
			sodaonguoc += chuso * pow(10.0, dem--);
		}
		if (i == sodaonguoc)
		{
			
			demdoixxung++;
			tongdoixung += i;
		}
		 
		if (sqrt((double)i) == (int)sqrt((double)i))
		{
			demchinhphuong++;
			tongchinhphuong += i;
		}
		int check;
		if (i < 2)
		{
			check = 0;
		}
		else
		{
			check = 1;
			for (int j = 2; j <= sqrt((double)i); j++)
			{
				if (i % j == 0)
				{
					check = 0;
					break;
				}
			}
			if (check == 1)
			{
				demnguyento += 1;
				tongnguyento += i;
			}
		}
		int check;
		if (i < 2)
		{
			check = 0;
		}
		else
		{
			check = 1;
			for (int j = 2; j <= sqrt((double)i); j++)
			{
				if (i % j == 0)
				{
					check = 0;
					break;
				}
			}
			if (check == 1)
			{
				demnguyento ++ ;
				tongnguyento += i;
			}
		}
	}
	printf("\n so nguyen to %d", demnguyento);
	printf("\n so luong cac so chinh phuong %d", demchinhphuong);
	printf("\n so luong cac so doi xuong %d", demdoixxung);

	printf("\nTong nguyen to %d", tongnguyento);
	printf("\nTong doi xung %d", tongdoixung);
	printf("\nTong chinh phuong %d", tongchinhphuong);

	return 0;
}


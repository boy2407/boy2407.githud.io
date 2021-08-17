#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include <Windows.h>
int main()
{
	int gia, nhan, tra;
	tiep:
		do
		{
			printf("\nSo tien phai tra:");
			scanf_s("%d", &gia);
			printf("\nSo tien nhan:");
			scanf_s("%d", &nhan);
			if (nhan < gia)
			{
				printf("nhan lai thang ngu !");
				Sleep(2000);
				system("cls");
			}
		} while (nhan < gia);
		tra = nhan - gia;
		int temp = tra;
		int dem500 = 0;
		int dem200 = 0;
		int dem100 = 0;
		int dem50 = 0;
		int dem20 = 0;
		int dem10 = 0;
		int dem1 = 0;
		int dem2 = 0;
		int dem5 = 0;
		int dem05 = 0;
		int du;
		while (temp!=0)
		{
			if (tra == 0)
			{
				printf("eo can tra tien thua");
				break;
			}
			if (temp >= 500000)
			{
				dem500 = temp / 500000;
				du = temp % 500000;
				temp = du;
			}
			if (temp < 500000 && temp >= 200000)
			{
				dem200 = temp / 200000;
				du = temp % 200000;
				temp = du;
			}
			if (temp < 200000 && temp >= 100000)
			{
				dem100 = temp / 100000;
				du = temp % 100000;
				temp = du;
			}
			if (temp < 100000 && temp >= 50000)
			{
				dem50 = temp / 50000;
				du = temp % 50000;
				temp = du;
			}
			if (temp < 50000 && temp >= 20000)
			{
				dem20 = temp / 20000;
				du = temp % 20000;
				temp = du;
			}
			if (temp < 20000 && temp >= 10000)
			{
				dem10 = temp / 10000;
				du = temp % 10000;
				temp = du;
			}
			if (temp < 10000 && temp >= 5000)
			{
				dem5 = temp / 5000;
				du = temp % 5000;
				temp = du;
			}
			if (temp < 5000 && temp >= 2000)
			{
				dem2 = temp / 2000;
				du = temp % 2000;
				temp = du;
			}
			if (temp < 2000 && temp >= 1000)
			{
				dem1 = temp / 1000;
				du = temp % 1000;
				temp = du;
			}
			 if (temp < 1000)
			{
				 dem05 = temp / 500;
				 du = temp / 500;
				 temp = du;
			}
			
			
			 
		}
		printf("\n so tien du %d", tra);
		printf("\n 500k %d", dem500);
		printf("\n 200k %d", dem200);
		printf("\n 100k %d", dem100);
		printf("\n 50k %d", dem50);
		printf("\n 20k %d", dem20);
		printf("\n 10k %d", dem10);
		printf("\n 5k %d", dem5);
		printf("\n 2k %d", dem2);
		printf("\n 1k %d", dem1);
		printf("\n  0.5k %d", dem05);
		int tieptuc;
		printf("\nngung lai nhan 1");
		scanf_s("%d", &tieptuc);
		if (tieptuc != 1)
		{
			system("cls");
			goto tiep;	
		}
		else
		{
			system("closed");
		}
	
	
	return 0;
	
}
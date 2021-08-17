#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
int KiemTraLaSoNguyen(char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] < '0' || s[i]>'9')
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int soluong;
	char chuoi[30];
	nghiadeptrai:
	printf("\nNhapvao so luong:");
	gets_s(chuoi);
	
	int kiemtra = KiemTraLaSoNguyen(chuoi);
	if (kiemtra)
	{
		soluong = atoi(chuoi);
		printf("\nSo luong = %d",soluong);
	}
	else
	{
		printf("\nLoi Kieu du lieu");
		goto nghiadeptrai;
	}


}
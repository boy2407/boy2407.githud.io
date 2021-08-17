#include<stdio.h>
#include<conio.h>
#include<math.h>
int main() {
	int n;
	do {
		scanf_s("%d", &n);
		if (n<=0) {
			printf("gia tr khong hop loi");
		}
		
	} while (n <= 0);
	int Temp = n;
	int sodaonguoc=0;
	int dem = log10((double)Temp);
	while (Temp!=0)
	{
		int chuso = Temp % 10;
		Temp /= 10;
		sodaonguoc += chuso * pow(10.0, dem--);
	}
	printf("\nSo dao nguoc cua %d la %d", n, sodaonguoc);
	if (n == sodaonguoc)
	{
		printf("\nLa so doi xung");
	}
	else
	{
		printf("\nkhong phai so doi xung");
	}
	if (sqrt((double)n) == (int)sqrt((double)n))
	{
		printf("la so chinh phuong");
	}
	return 0;
}
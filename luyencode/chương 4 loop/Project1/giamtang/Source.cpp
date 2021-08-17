#include<stdio.h>
#include<conio.h>
int main()

{
	int temp;
	int n;
	// kiem tra tang dang
	scanf_s("%d", &n);
	temp = n;
	int checkTang = 1;
	int checkGiam = 1;
	//12345
	while (temp > 9)// còn  ch? s? d?ng l?i temp/10 !=0
	{
		int chuso1 = temp % 10;//5
		temp/=10;
		int chuso2 = temp % 10;//4
		if (chuso1 <= chuso2)
		{
			checkTang = 0;
		}
		if (chuso1 >= chuso2)
		{
			checkGiam = 0;
		}
	}
	if (checkTang == 1)
	{
		printf("\nTang dan");
	}
	else if (checkGiam==1)
	{
		printf("\nGiam dan");
	}
	else
	{
		printf("\nKhong tang khong giam");
	}
}
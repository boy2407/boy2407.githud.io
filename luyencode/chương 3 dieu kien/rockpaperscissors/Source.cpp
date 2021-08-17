#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	int nguoi;
	printf("\n------------------------------Menu------------------------");
	printf("\n1.keo");
	printf("\n2.Bua");
	printf("\n3.Bao");
	printf("\nNguoi choi lua chon ");
	scanf_s("%d", &nguoi);
	printf("\nDang chon");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	system("cls");
	if (nguoi == 1)
	{
		printf("\nnguoi ra Keo");
	}
	else if (nguoi == 2)
	{
		printf("\nnguoi ra bua");
	}
	else if (nguoi == 3)
	{
		printf("\nnguoi ra bao");
	}

	/* sleep (x)
	* x tính theo mili giây
	*
	*
	*/
	printf("\nLoading");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(500);
	system("cls");
	srand(time(0));//reset l?i th?i gian
	//[a,b]=. a + rand()% b - a +1;
	int may = 1 + rand() % 3;
	if (may == 1)
	{
		printf("\nmay ra Keo");
	}
	else if (may == 2)
	{
		printf("\nmay ra bua");
	}
	else if(may == 3)
	{
		printf("\nmay ra bao");
	}
	// ki?m tra ?i?u ki?n th?ng thua
	if (nguoi == 1 )
	{
		if (may == 1)
		{
			printf("\nHoa!");
		}
		else if (may == 2)
		{
			printf("\nMay Thang!");
		}
		else
		{
			printf("\nNguoi thang!");
		}
	}
	else if (nguoi == 2)
	{
		if (may == 1)
		{
			printf("\nNguoi Thang!");
		}
		else if (may == 2)
		{
			printf("\nHoa");
		}
		else
		{
			printf("\nMay Thang!");
		}
	}
	else if (nguoi == 3)
	{
		if (may == 1)
		{
			printf("\nMay Thang!");
		}
		else if (may == 2)
		{
			printf("\nNguoi Thang!");
		}
		else
		{
			printf("\nHoa");
		}
	}
}
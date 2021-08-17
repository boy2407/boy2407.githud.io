#include<stdio.h>
#include<conio.h>
int main() {
	int a, b;
	do {
		printf("\nnhap so duong a = ");
		scanf_s("%d", &a);
		if (a < 0)
		{
			printf("\nVui long nhap lai");
		}
	} while (a < 0);
	do {
		printf("\nnhap so duong b = ");
		scanf_s("%d", &b);
		if (b < 0)
		{
			printf("\nVui long nhap lai");
		}
	} while (b < 0);
	/*
	số 4 chia hết 1 2 4
	só 6 chia hết 1 2 3 6
	ta sẽ đi xết tứ số bé nhất và xét các số nó chia hết, lần lượt lấy từng số đó
	so sánh
	*/
	int max = a < b ? b : a;
	int min = a > b ? b : a;
	int solanlapcach1 = 0;
	int solanlapcach2 = 0;
	int ucln;

	if (max % min == 0)
	{
		ucln = min;

	}
	else
	{
		for (int i = min / 2; i >= 1; --i)// thuật toán 
		{
			solanlapcach1++;
			if (max % i == 0 && min % i == 0)
			{
				ucln = i;
				break;
			}
		}
	}
	printf("\ncach 1 %d", ucln);
	printf("\nso lan chay 1 : %d", solanlapcach1);
	/*
	trên giang hố có thuật toán sau : a , b
	a # b;
	nếu a>b thi a = a - b;
	nếu a<b thì b = b - a;
	nếu a == b thì dừng
	*/
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
		solanlapcach2++;

	}
	ucln = a;
	
	printf("\ncach 2 %d", ucln);
	printf("\nso lan chay 2 : %d", solanlapcach2);
	return 0;
}